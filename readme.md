Introducing snct::Constrained<T>
===

**A faster *and* easier approach to error handling in C++**
<br>*Søren Rune Nissen*

```c++
    // all errors and edge cases handled 
    using Divisor = snct::Constrained<double, Not<0.0>, Finite>;
    constexpr double invert(Divisor d) noexcept { return 1.0/d; }
    // with no runtime performance degradation
```

# Index

* [Introduction](#introduction)
  * Acknowledgements
* [Using constrained types](#using-constrained-types)
  * With exceptions enabled
  * Without using exceptions
* [Creating constrained types](#creating-constrained-types)
  * The name
  * The underlying type
  * The constraints
* [The benefits of constrained types](#the-benefits-of-constrained-types)
  * Total and partial functions
  * Put constraints in code rather than documentation
  * Letting the user decide on error handling strategies
  * Impacts on performance and binary size
* [Postscrip: But Why Though?](#postscript-but-why-though)

# Introduction

Any number of C++ guides will tell you to constrain your input. With `snct::Constrained`, I aim to give you the best tool to do this for your API.

Writing this, I operated under my own constraints to make this better for you:

* **Ease of use - for API users.** Rather than relying on docs or comments that may grow stale or wrong, the constraints are expressed directly in a single line of code pr. parameter, visible right there in the header.
* **Ease of use - for API designers.** If you can make do with constraints available, you barely need to change anything. If you need domain-specific constraints, those are easy to add.
* **No visible macros.** - By God this would have been easier if I'd forced you to use a macro, but I wouldn't do that to you.
* **Performance.** Nothing about using `snct::Constrained` has been allowed to take longer than the naive approach, and every constraint is constexpr to move any possible check into compile time. (For embedded developers, see the headings on binary size, you might be positively surprised)
<!--* **Permissively licensed.** For what shall it profit a man, if he shall gain the whole world, and lose his own soul?-->

## Acknowledgements

I would like to thank

* Ben Deane, for his excellent talk ["Using Types Effectively"](https://www.youtube.com/watch?v=ojZbFIQSdl8) presented at CppCon 2016.
* Members of the [Odense C++ User Group](https://www.meetup.com/meeting-c-user-group-odense/), for their great feedback.
* /u/IyeOnline, who [truly stepped up to the plate](https://godbolt.org/z/erzKrKqzs) when I was struggling with a performance improvement, helping to change this from a zero-cost abstraction to a *negative*-cost abstraction\*.

\* Assuming certain costs don't count ;)


# Using constrained types

If you need to call a function that takes a constrained parameter - you need to constrain your parameter.

Reading an API header, you may see this declaration:

```c++
    using Dimension = snct::Constrained<double, GreaterThan<0.0>, NotNaN>;
    constexpr double area(Dimension x, Dimension y);
```

The template specifies exactly one underlying type (here `double`), and a list of constraints that must be satisfied to create an object of the constrained type (Here `GreaterThan<0.0>` and `NotNaN`)

How to use that depends on whether you have exceptions enabled

## With exceptions enabled

If you have exceptions, this:

```c++
    using Dimension = snct::Constrained<double, GreaterThan<0.0>, NotNaN>;
    constexpr double area(Dimension x, Dimension y) noexcept;
```

should read and used exactly like this:

```c++
    // Throws snct::Constraint_Exception if x or y are NaN or not greater than 0.0
    constexpr double area(double x, double y);
```

### The happy path:

A constrained type `snct::Constrained<T` is implicitly constructible from a `T`:

```c++
    constexpr auto my_area = area(10.0, 20.0); // area = 200.0
    //                             ^     ^-- constructs a Dimension{20.0}
    //                             |
    //                             +-- constructs a Dimension{10.0}
```

### In case of error:

What if you call it with a double that violates the constraints?

If you know your values ahead of time, the `snct::Constrained` constructor is marked `constexpr`, and refuses to compile with values that don't satisfy the specified constraints:

```c++
    constexpr auto my_area = area(-10.0, 20.0);
    //                              ^-- Compiler error here
```

If your call is made at runtime, you get an exception instead

```c++
    auto my_area = area( -10.0, 20.0);
    //                   ^-- The Dimension constructor will throw
    //                       an snct::Constraint_Exception here
```

The exception inherits from `std::exception`, and `::what()` returns a cstring that explains which constraint was violated. In this example, the string will read "`Constraint 'snct::GreaterThan<value>' was violated`"

## Without using exceptions

With exceptions disabled, the constructors for Constrained types are private:

```c++
    using Dimension = snct::Constrained<double, GreaterThan<0.0>, NotNaN>;
    constexpr double area(Dimension x, Dimension y);

    auto my_area = area(10.0, 20.0);
    //                   ^--compiler error here
```

Instead, constrained types must be constructed with a factory method

```c++
    constexpr std::optional<Dimension> Dimension::factory(double d) noexcept;
```

(This factory method is also available if you compile with exceptions enabled but need to remain `noexcept` for some reason)


```c++
    const auto optional_x = Dimension::factory(10.0);
    const auto optional_y = Dimension::factory(20.0);

    if(! (optional_x && optional_y) )
        //handle error here
    else
        auto my_area = area(*optional_x, *optional_y);
```

As the factory method on `snct::Constrained` is `constexpr`, you can statically assert correctness rather than wait for runtime if you are working with known values.

# Creating constrained types

The overall process of creating a constrained type is simple if you keep in mind the primary goal: Simplifying things for your API's user.

A useful constrained type needs three things:

1. A good name - you can typically use the same name as you would have given the parameter
2. A underlying type, typically the exact same type you would otherwise have used in your API
3. A list of constraints

For example, if you want to multiply two doubles to calculate the area they describe, you can write this constrained type:

```c++
    //       ¤-- A descriptive name "Dimension"
    //       |
    //       |                            ¤-- An underlying type "double"
    //       |                            |
    using Dimension = snct::Constrained<double, GreaterThan<0.0>, NotNaN>;
    //                                          |                       |
    //                                          ¤-----------¤-----------¤
    //                                                      |
    //   A list of constraints "GreaterThan<0.0>, NotNaN" --¤
```

## The name

Technically, the name is not required, you could replace this function:

```c++
    using Dimension = snct::Constrained<double, GreaterThan<0.0>, NotNaN>;
    
    constexpr double area(Dimension x,
                          Dimension y);
```

with

```c++
    constexpr double area(snct::Constrained<double, GreaterThan<0.0>, NotNaN> x,
                          snct::Constrained<double, GreaterThan<0.0>, NotNaN> y);
```

but if you cannot think of a good name for your constrained type, possibly you need to workshop it a bit more. (Naming constrained types is a lot like naming classes)

## The underlying type

Depending on your use case, your underlying type can be a

* value
  * `using Dimension = snct::Constrained< double, GreaterThan<0.0>>;`
* reference
  * `using Day = snct::Constrained< std::vector<hour>&, Size<24> >;`
* or pointer
  * `using Name = snct::Constrained< const char*, Not<nullptr> >;`

of both built in types and user defined types.

My general advice is to use a value when the underlying type is small, a const reference when a copy would be slower than an indirection, and pointers only when you must, or when the type you are constraining is inherently a pointer.

You can only constrain one type at a time, but of course that type can be a struct or tuple if you need multiple values.

Once you have a `Constrained<T`, it is readily convertible to a `T`, letting you access the constrained value implicitly or explicitly:

```c++
    using Divisor = snct::Constrained<double, Not<0.0>, Finite>;
    constexpr double invert(Divisor d) {
        return 1.0/d;
    }
    
    using Dimension = snct::Constrained<double, GreaterThan<0.0>, NotNaN>;
    constexpr double area(Dimension x, Dimension y) {
        return (double)x * (double)y;
    }
```

The conversion operator returns a `const&` to the underlying value.

## The constraints

Some constraints are supplied in the header `snct_constraints.hpp`:

```c++
    snct::Finite // satisfied for values where std::isfinite(v) returns true (filters out NaNs and infinities)
    snct::NotNaN // satisfied for values where std::isnan(v) returns false

    snct::Not<value>
    snct::Not<nullptr>

    snct::LessThan<value>
    snct::GreaterThan<value>
    snct::Minimum<value>
    snct::Maximum<value>

    snct::AlwaysSatisfied
    snct::NeverSatisfied
    snct::Satisfied<bool>
```

If you need a constraint that isn't on this list, writing a new constraint is simple - a constraint is a struct that matches this concept:

```c++
    template<typename ConstraintType, typename ValueType>
    concept Constraint = requires(ValueType v)
    {
        { ConstraintType::is_satisfied(v) } noexcept -> std::same_as<bool>;
        { ConstraintType::error_message() } noexcept -> std::same_as<const char*>;
    };
```

If concepts are new to you, here's the struct that implements the constraint `snct::Maximum<value>`:

```c++
    template<auto value>
    struct Maximum
    {
        using T = decltype(value);
        constexpr static bool is_satisfied(T const& t) noexcept { return std::less_equal<T>{}(t, value); }
        inline static const char* error_message() noexcept { return "Constraint 'snct::Maximum<value>' was violated"; }
    };
```

Two `static` and `noexcept` methods, `is_satisfied` to check whether the supplied value satisfies your constraint, and `error_message` with an appropriate descriptive message for when the constraint isn't satisfied.

It is recommended - but not required - that your `is_satisfied` method is marked `constexpr`. If it isn't, your users cannot check the constraint at compile time

It is required that both `is_satisfied` and `error_message` are marked `noexcept`. This is also a requirement in code bases that can handle exceptions. It is up to the user whether they can, at this exact point in their code, handle an exception. If they can, they may call the public `snct::Constrained` constructor, which will handle any necessary throws. If they cannot handle exceptions, they are calling the `snct::Constrained::factory` method, which guarantees no exceptions will be thrown. In either case, a throw from `is_satisfied` is useless, and has thus been banned by the `Constraint` concept.

# The benefits of constrained types

It's Great.

You get to write total functions (much easier).

You get to let the user decide on error handling strategy so your API can be used by more people.

You may get a *performance increase* which was wild to me once I realized it - my original goal was just to avoid a performance *decrease* but this is actually faster in some cases.

You *may* get a smaller binary size (Or it may grow - this one depends a lot on your use case, you should measure.)

## Total and partial functions

First, let's talk about functions in math.

In the domain of real numbers, `f(x) = x+1` is a "total" function. Here, "f is a total function" means `f` is defined for every input in its domain - for any real number `x`, `f(x)` has a valid answer.

By comparison, in the domain of real numbers, `h(x) = 1/x` is a *partial* function - it only *partially* maps every number in its domain into an answer - because you cannot divide with 0.

In math, you cannot use a partial function on a number that doesn't map to an output. Of course there is nothing *preventing* you from getting out pencil and paper and writing the characters `h(0)`, but regular math has no defined answer for you.

On computers, we see a lot of partial functions, e.g. calling `::front();` on an empty vector leads to undefined behavior. We also see a lot of functions that are *morally* partial - functions that avoid partiality by returning bad values (e.g. calling `sqrt(-1);`) or by throwing exceptions (calling `::at(0);` on our empty vector)

By *constraining the domain of our input*, we can write *total* functions. And total functions are *so much easier to write*.

### Total functions are so much easier to write

This is math:

    h(x) = 1/x | {x ∈ ℝ : x ≠ 0}

Equivalent C++ with constraints:

```c++
    using X = Constrained<double, Finite, Not<0.0> >
    double h(X x) { return 1.0/x;}
```

Equivalent C++ without constraints:

```c++
    double h(double x)
    {
        if( x == 0.0)
            throw zero_exception{};
        else if ( !std::isfinite(x) )
            throw not_finite_exception{};
        else
            return 1.0/x;
    }
```

We could add some keywords to both functions - `constexpr` is a good one, and arguably the constrained function should be marked `noexcept` - but I believe my point is made.

Let's talk about functions that aren't math.

How would you write a function that counts digits in an arbitrary input string, in 1998?

```c++
    std::size_t count_digits(std::string const & input);
```

Valid approach maybe. Expensive to instantiate a `std::string` if all you already have a char array, but it could be done.

```c++
    std::size_t count_digits( char const * chars, std::size_t count);
```

Maybe better. If you already have a `std::string` you can get a `char const *` from it cheaply, and a size as well. But now you have to check if `chars` points to `null`, and what's your return if it does? A signalling value like-1 maybe? Or do you throw?

Or, if you have future vision, you look into 2017 and you invent `string_view`.

```c++
    std::size_t count_digits( std::string_view sv );
```

You can just use a string view! Your function becomes so easy to write, it's almost embarrassing

```c++
    std::size_t count_digits( std::string_view sv )
    {
        std::size_t count = 0;
        for(char c : sv)
        {
            if('0' <= c && c <= '9') count += 1;
        }
        return count;
    }
```

Go watch Ben Deane's talk (link in the introduction) for more on this.













## Put constraints in code rather than documentation

Putting your constraints into code instead of comments nets you some benefits.

### Debugging

Let's start with an under-appreciated one: Errors are easier to debug.

If a function throws an exception, it can sometimes be hard to find out what went wrong - to start with, did *this* function throw, or did it call another function that threw?

Throws from constraints do not originate inside your function - they happen right there in the calling code, as the user is trying to construct the parameters they will pass into your function.

This is extra true for changes to code - if you add an additional requirement to a function and put that in the header comment, how long will it take, once they log that new exception::what message, before they find out that *you* threw, then find the new place in your function that threw? And then realize they they haven't coded wrong in the past, in fact there's been a change, they should go check the docs/comments?

But if you just add a new constraint, even if they don't find it before it throws, once again I say: The throw itself will happen exactly right there when they construct the argument they want to pass in.

### Stale comments and documentation

> *The compiler doesn't read comments, and neither do I*
> <br>\- Bjarne Stroustrup, apochryphal

Unit tests don't read comments. They'll compile your constrained params though.

Users don't read comments *or* unit tests. They'll read your input param type though.

An old version of the docs might be the first result on google. The current version of your constraint is right there in the code though.

## Letting the user decide on error handling strategies

On othe one hand, standard C++ has exceptions.

On the other hand, let's be real here. Some code bases use no exceptions at all. Others have parts, perhaps originally written as C, that will leak like a sieve if an exception is suddenly thrown from a refactored function. Sometimes, even if the C++ standard has exceptions, *you* don't.

But sometimes you do. Sometimes exceptions are exactly the right answer. 

Are you writing two functions now? Or are you going to constrain your inputs and offer both possibilities?

```c++
    using Divisor = Constrained<double, Not<0.0>, Finite>
    constexpr double inverse(Divisor d) { return 1.0/d;}
```

You can call that function whether your code base can handle exceptions or not:

```c++
    double double_inversion()
    {
        double const input1 = get_from_config(); // Could be zero
        double const input2 = get_from_config(); // or NaN or inf
        double my_inverse_1;
        double my_inverse_2;

        // getting an inverse with no possibility of throws:
        auto opt_divisor = Divisor::factory(input1);
        if(!opt_divisor)
            std::exit(1);
        my_inverse_1 = inverse(*opt_divisor);

        // getting an inverse without having to handle nullopts:
        try {
            auto my_inverse_2 = inverse(input2);
            return my_inverse_1 + my_inverse_2;
        }
        catch(snct::Constrained_Exception const &) {
            std::exit(1);
        }
    }
```

## Impacts on performance and binary size

Sort of two sides of the same coin:

### Conditionals and branching

Creating a constrained value is not free. The more constraints, the more tests in the constructor - and the more conditionals that might go one way or the other.

Uncontrained values aren't free either - the fewer known constraints, the more tests in the *function* - and the more conditionals that might go one way or the other.

SO IF You don't *have* an error handling strategy - if all your functions are written in the naive style that assumes no bad inputs - `double inverse(double d) {return 1.0/d;}` - you will see a performance loss.

If you currently have checks inside your functions, that either throw or return error codes, and you have to operate on a lot of different values, you should see neither performance gains, nor performance losses.

But. If you have to operate a lot on the same value - sometimes you can constrain it *once*, adding a few checks, and then *remove* checks from several separate functions. In that case, your code will now have *fewer* branches than it did before.

### Binary size

About the same as with the branching conditionals.

You remove `jmp` and `cmp` instructions from functions, and move them into constructors, win some lose some.

If you're using the factory functions rather than the public constructors, that gets you an extra conditional outside your function when you check whether the optional is good or `null_opt`.

But again, as with the performance impact, that *might* still see you ahead on binary size if you can remove a lot of conditionals from functions, but keep operating on the same values so you don't have to check over and over - once constructed, they're good.

I must be honest here and say that I do not have a large code base without excpetions to test this on, so I cannot guarantee that binary sizes won't grow. There is reason to think they may, there is reason to think they will not. If you get the opportunity to try it out, please report back to me so I can update this section with and replace theorizing with facts.

# Postscript: But Why Though?

The original motivating example was a function like this:

```c++
    unsigned legacy_function(
        return_struct *,
        param_1 *,
        param_2 *,
        param_3 *,
        param_etc *);
```

that needed to be expanded a little:

```c++
    unsigned legacy_function(
        return_struct *,
        param_1 *,
        param_2 *,
        param_3 *,
        param_etc *,
            Date * beginning_of_period, //new param
            Date * end_of_period);      //new param
```

for legacy reasons, the function only had two return values, `0U`, and `-1U`. It was used in a lot of places that absolutely expect it to not throw any exceptions. At the same time, the `Date` objects had two failure modes - a Date can be invalid, and two of them might be out of order.

After struggling for a while, seven functions and two callbacks deep inside `legacy_function`, I realized the solution was actually dead simple:

```c++
    unsigned legacy_function(
        return_struct *,
        param_1 *,
        param_2 *,
        param_3 *,
        param_etc *,
            Period *);  // new param
```

Introducing a `Period` class was very much best-of-all-worlds. By establishing invariants in the constructor (Both contained dates are valid, and the order is correct) I could remove *so much error handling* I would otherwise have to introduce.

I still had to contend with the fact that many callers were not exception safe but that was simple, really - C++ had just added `std::optional` so a non-allocating factory function was easy to write.

For years I didn't give it much further thought, but then I watched "Using Types Effectively" and I realized my experience wasn't a one-off.

Now I want to use this approach for almost every error handling scenario I'm in. Just one problem though - if I write a class for every input parameter in every API I work on, that's going to be a lot of time spent writing classes - and I'm forcing all my users to *read* all those classes, too!

But... what if I find a generic approach? Users have to understand a template *once*, the first time they see it.

With `snct::Constrained`, the legacy function declaration would look like this:

```c++
    using Period = snct::Constrained< std::pair<Date,Date>,
                                      BothDatesValid,
                                      FirstElementLessThanSecondElement>;
    
    unsigned legacy_function(
        return_struct *,
        param_1 *,
        param_2 *,
        param_3 *,
        param_etc *,
            Period *); // new param
```

Users who operate in a code base with constrained values won't have to go read the template, the `using` line says exactly what they need to pass into the function  *and* tells them there's a factory function available if they can't handle an exception.
