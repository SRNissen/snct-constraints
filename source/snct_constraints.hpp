#ifndef SNCT_CONSTRAINTS_HPP
#define SNCT_CONSTRAINTS_HPP

#include "snct_constrained.hpp"
#include "snct_constexpr_math.hpp"

namespace snct
{
	struct Finite
	{
		constexpr static bool is_satisfied(std::floating_point auto t) noexcept { return snct::is_finite(t); }
		inline static const char* error_message() noexcept { return "Constraint 'snct::Finite' was violated."; }
	};

	template<auto value>
	struct Not
	{
		using T = decltype(value);
		constexpr static bool is_satisfied(T const& t) noexcept { return t != value; }
		inline static const char* error_message() noexcept { return "Constraint 'snct::Not<value>' was violated."; }
	};

	template<>
	struct Not<nullptr>
	{
		constexpr static bool is_satisfied(auto const* const t) noexcept { return t != nullptr; }
		inline static const char* error_message() noexcept { return "Constraint 'snct::Not<nullptr>' was violated."; }
	};


	struct NotNaN
	{
		constexpr static bool is_satisfied(std::floating_point auto t) noexcept { return !snct::is_nan(t); }
		inline static const char* error_message() noexcept { return "Constraint 'snct::NotNaN' was violated."; }
	};


	template<auto value>
	struct LessThan
	{
		using T = decltype(value);
		constexpr static bool is_satisfied(T const& t) noexcept { return std::less<T>{}(t, value); }
		inline static const char* error_message() noexcept { return "Constraint 'snct::LessThan<value>' was violated"; }
	};


	template<auto value>
	struct GreaterThan
	{
		using T = decltype(value);
		constexpr static bool is_satisfied(T const& t) noexcept { return std::greater<T>{}(t, value); }
		inline static const char* error_message() noexcept { return "Constraint 'snct::GreaterThan<value>' was violated"; }
	};


	template<auto value>
	struct Minimum
	{
		using T = decltype(value);
		constexpr static bool is_satisfied(T const& t) noexcept { return std::greater_equal<T>{}(t, value); }
		inline static const char* error_message() noexcept { return "Constraint 'snct::Minimum<value>' was violated"; }
	};


	template<auto value>
	struct Maximum
	{
		using T = decltype(value);
		constexpr static bool is_satisfied(T const& t) noexcept { return std::less_equal<T>{}(t, value); }
		inline static const char* error_message() noexcept { return "Constraint 'snct::Maximum<value>' was violated"; }
	};

	template<bool value>
	struct Satisfied
	{
		constexpr static bool is_satisfied(auto const&) noexcept { return value; }
		inline static const char* error_message() noexcept { return "Constraint 'snct::Satisfied<true/false>' was violated"; }
	};

	struct AlwaysSatisfied
	{
		constexpr static bool is_satisfied(auto const&) noexcept { return true; }
		inline static const char* error_message() noexcept { return "Constraint 'Always_Valid' was violated"; }
	};


	struct NeverSatisfied
	{
		constexpr static bool is_satisfied(auto const&) noexcept { return false; }
		inline static const char* error_message() noexcept { return "Constraint 'Never_Valid' was violated"; }
	};


	/////////////////////////
	// traits to define relation between predefined constraints
	/////////////////////////

    template<auto v1, auto v2>
    struct constraint_relation< GreaterThan<v1>, Not<v2> >
    {
        constexpr static bool narrower = v1 >= v2; //"GreaterThan" is narrower than "Not" when this condition is true
    };

    template<auto v1, auto v2>
    struct constraint_relation< LessThan<v1>, Not<v2> >
    {
        constexpr static bool narrower = v1 <= v2; 
    };

    template<auto v1, auto v2>
    struct constraint_relation< Not<v1>, Not<v2> >
    {
        constexpr static bool equivalent = v1 == v2; 
    };

    template<auto v1, auto v2>
    struct constraint_relation< GreaterThan<v1>, Minimum<v2> >
    {
        constexpr static bool narrower = v1 >= v2; //"GreaterThan" is narrower than "Miniumum" when this condition is true
    };

    template<auto v1, auto v2>
    struct constraint_relation< LessThan<v1>, Maximum<v2> >
    {
        constexpr static bool narrower = v1 <= v2; //"GreaterThan" is narrower than "Miniumum" when this condition is true
    };

    template<auto v1, auto v2>
    struct constraint_relation< GreaterThan<v1>, GreaterThan<v2> >
    {
        constexpr static bool equivalent = v1 == v2; //"GreaterThan" is equivalent to "GreaterThan" when this condition is true
        constexpr static bool narrower = v1 > v2; //"GreaterThan" is narrower than "GreaterThan" when this condition is true
    };

    template<auto v1, auto v2>
    struct constraint_relation< LessThan<v1>, LessThan<v2> >
    {
        constexpr static bool equivalent = v1 == v2; 
        constexpr static bool narrower = v1 < v2; 
    };

	template<auto v1, auto v2>
	struct constraint_relation< LessThan<v1>, GreaterThan<v2> >
	{
		static_assert( v1 >= v2, "The intersection of two constraints should not be empty" );
	};

	template<auto v1, auto v2>
	struct constraint_relation< GreaterThan<v1>, LessThan<v2> >
	{
		static_assert( v1 <= v2, "The intersection of two constraints should not be empty" );
	};

}

#endif //header guard