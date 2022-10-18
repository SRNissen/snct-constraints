#ifndef SNCT_CONSTRAINED_HPP
#define SNCT_CONSTRAINED_HPP

#include <concepts>
#include <type_traits>
#include <stdexcept>
#include <optional>
#include <string_view>

namespace snct
{
    template<typename ConstraintType, typename ValueType>
    concept Constraint = requires(ValueType v)
    {
        { ConstraintType::is_satisfied(v) } noexcept -> std::same_as<bool>;
        { ConstraintType::error_message() } noexcept -> std::same_as<const char*>;
    };

    /** @brief Trait to specify the relation between constraints.
	 * 
	 * This is a customization point for users to specialize for their own custom constraints. See the predefined ones for examples.
	 * 
	 * @example
	 * 
	 * constexpr static bool equivalent = false; //define a member 'equialent' with the value 'true' when the two traits are equivalent
	 * 
	 * @example 
	 * 
	 * constexpr static bool narrower = false; // define a member 'narrower' when constraint C1 is narrower than C2
	 * 
	 * For example 'x < 10' is narrower than 'x < 0'
	 * 
	 * Any relation not specified is assumed to be false.
	*/
    template<typename C1, typename C2>
    struct constraint_relation; // the primary template must not define any of these members, otherwise the reduction logic breaks

	/**
	 * @brief Exception class thrown if a constraint is not satisfied
	 */
    class Constraint_Exception : public std::exception
    {
    public:
        Constraint_Exception(const char* error_message) noexcept : error_message_{ error_message } {}
        const char* what()  const noexcept override { return error_message_; }
    private:
        const char* error_message_;
    };



    namespace detail
    {
        template<typename C1, typename C2>
        concept is_equivalent = requires
        {
			//trick that should work to both check the existance and value at the same time.
        	typename std::enable_if<constraint_relation<C1,C2>::equivalent>; 
        }; 

        template<typename C1, typename C2>
        concept is_narrower = requires
        {
        	typename std::enable_if<constraint_relation<C1,C2>::narrower>;
        };

        /** @brief normalized relation trait, that gives us the relation between constraint C1 and constraint C2 */
        template<typename C1, typename C2>
        struct normalized_relation
        {
           constexpr static bool equivalent = is_equivalent<C1,C2> || is_equivalent<C2,C1>;
           constexpr static bool narrower = is_narrower<C1,C2>;
           constexpr static bool wider = is_narrower<C2,C1>;
        };

        /* @brief helper type that holds indices for constraint search */
        struct relation_idx_t
        {
            std::size_t equivalent;
            std::size_t narrower;
            std::size_t wider;
        };

        /* @brief determines the (last, but w/e) index where 'C' is related to 'Cs...'*/
        template<typename C, typename ... Cs>
        constexpr relation_idx_t get_relation_idx() noexcept
        {
            constexpr std::size_t S = sizeof...(Cs);
            relation_idx_t idx{ S, S, S };
            std::size_t i=0;

            ( (
                ( idx.equivalent==S and normalized_relation<C,Cs>::equivalent ? idx.equivalent=i : 0 ),
                ( idx.narrower==S and normalized_relation<C,Cs>::narrower ? idx.narrower=i : 0 ),
                ( idx.wider==S and normalized_relation<C,Cs>::wider ? idx.wider=i : 0 ),
                ++i
            ),... );

            return idx;
        }


        /** @brief a pack of checks 'Cs...' on type 'T' */
        template<typename T, typename ... Cs>
        struct constraint_pack
        {
			constexpr static bool is_nothrow_check = ( std::is_nothrow_invocable_v<Cs,T> && ... );

            /** @brief checks all constraints and throws if one is false */
            constexpr static void check_and_throw( T value )
            {    
                return ( ( Cs::is_satisfied(value) ? (void)0 : throw Constraint_Exception{ Cs::error_message() } ), ...);
            }

            /** @brief checks all constraints*/
            constexpr static bool check( T value ) noexcept( is_nothrow_check )
            {
                return ( Cs::is_satisfied(value) && ... );
            }

            /** @brief meta helper function that replaces the type at index I in Cs... */
            template<typename C, std::size_t I, std::size_t ... Is>
            constexpr static auto replace_type( std::index_sequence<Is...> ) noexcept
            {
                return constraint_pack<T, std::conditional_t<I==Is,C,Cs> ...>{};
            }

            /** @brief meta helper function to add a type to the check list*/
            template<typename C>
            constexpr static auto add_type() noexcept
            {
                constexpr auto S = sizeof...(Cs);
                if constexpr ( S == 0 )
                {
                    return constraint_pack<T,C>{};
                }
                else
                {
                    constexpr auto rel_idx = get_relation_idx<C,Cs...>();

                    //if the constraint to add has no relation to the already existing ones
                    if constexpr ( rel_idx.equivalent == S and rel_idx.narrower == S and rel_idx.wider == S )
                    {
                        return constraint_pack<T,C,Cs...>{};
                    }
                    else if constexpr ( rel_idx.equivalent != S or rel_idx.wider != S ) // the constraint to add is equivalent to wider than an existing one
                    {
                        return constraint_pack<T,Cs...>{};
                    }
                    else
                    {
                        return replace_type<C,rel_idx.narrower>( std::make_index_sequence<S>() );
                    }
                }
            }

            /** @brief checks only those constraints that are not already subsumed in other_constraints... */
            template<typename ... other_constraints>
            constexpr static void check_and_throw_parameters_if_not_already_subsumed( T value )
            {
                return ( 
                    []( T value )
                    {
                        using with_new_check = decltype(add_type<other_constraints>());
                        if constexpr ( not std::is_same_v<with_new_check,constraint_pack> ) //adding the constraint changes the type -> its a new check
                        {
                            other_constraints::is_satisfied(value) ? void(0) : throw Constraint_Exception{other_constraints::error_message() }; 
                        }
                    }(value)
                    ,... 
                );
            }
        };

		// trait to create a normalized check_pack. provides a 'type' member for the reduced 'constraint_pack'
        template<typename T, typename ... Cs>
        struct make_normalized_check_pack;

        template<typename T, typename C>
        struct make_normalized_check_pack<T,C>
        {
            using type = constraint_pack<T,C>;
        };

		//specialization for more than one constraint. recursive
        template<typename T, typename C, typename ... Cs >
        struct make_normalized_check_pack<T,C,Cs...>
        {
            using type = decltype(make_normalized_check_pack<T,Cs...>::type:: template add_type<C>() );
        };
    }


	/**
	 * @brief Template class used to create a constrained value holder
	 * 
	 * @tparam T type to hold
	 * @tparam constraints... the constraints that should be checked on construction
	 */
    template<typename T, Constraint<T> ... constraints>
    class Constrained
    {
        //static_assert( sizeof...(constraints) > 0 );
    public:
        //nice little helper that holds all our checks as a pack
        //using checks = detail::make_normalized_check_pack<T,constraints...>::type;

        Constrained() = delete;

        [[nodiscard]] constexpr operator T const & () const { return underlying_; }

		/**
		 * @brief Construct a new Constrained object
		 * 
		 * @param value the value to check and hold
		 * 
		 * @throws Constraint_Exception if one of the constraints is not satisfied
		 */
        constexpr Constrained( T t )
            : underlying_{t}
        {
            if constexpr (sizeof...(constraints) > 0)
                detail::make_normalized_check_pack<T, constraints...>::type::check_and_throw(t);
        }

        template<typename U, Constraint<U> ... other_constraints>
        friend class Constrained;


		/**
		 * @brief Converts from a Constrained object with different constraints to this Constrained.
		 * 
		 *  Only checks constraints that are not already satisified in 'other'
		 * 
		 * @param other the other Constrained value
		 * 
		 * @throws Constraint_Exception if one of the constraints is not satisfied
		 */
        template<typename ... other_constraints>
        constexpr Constrained( const Constrained<T,other_constraints...>& other )
            : underlying_{ other.underlying_ }
        { 
            // this check actually only checks 'constraints...' (which are this->constraints ) if they are not subsumed in 'other_constraints...'
            // its a bit convoluted, but easiest to check this way around
            if constexpr (sizeof...(constraints) > 0)
                Constrained<T,other_constraints...>::checks::template check_and_throw_parameters_if_not_already_subsumed<constraints...>( other.underlying_ );
        }


		/**
		 * @brief Conditionally constructs a Constrained object if the constraints are satisified
		 * 
		 * @param value to check and hold
		 * @return std::optional<Constrained> 
		 */
        [[nodiscard]] static constexpr std::optional<Constrained> factory( T value ) noexcept(detail::make_normalized_check_pack<T, constraints...>::type::is_nothrow_check)
        {
            if constexpr (sizeof...(constraints) > 0)
            {
                const bool all_satisfied = detail::make_normalized_check_pack<T, constraints...>::type::check(value);

                if (all_satisfied)
                {
                    return Constrained{ value, Factoryparam{} };
                }
                else
                {
                    return std::nullopt;
                }
            }
            else
            {
                return Constrained{ value, Factoryparam{} };
            }
        }

    private:
        class Factoryparam {};
        constexpr Constrained(T t, Factoryparam) : underlying_{ t } {};
        T underlying_;
    };
} //namespace

#endif //header guard