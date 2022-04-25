#ifndef SNCT_TEST_CONSTRAINTS_H
#define SNCT_TEST_CONSTRAINTS_H

// A constraint satisfies this concept:
//  
// template<typename ConstraintType, typename ValueType>
// concept Constraint = requires(ValueType v)
// {
//     { ConstraintType::is_satisfied(v) } noexcept -> std::same_as<bool>;
//     { ConstraintType::error_message() } noexcept -> std::same_as<const char*>;
// };


namespace {

    struct ValidConstraint_One
    {
        constexpr static bool is_satisfied(auto const& t) noexcept { return true; }
        inline static const char* error_message() noexcept { return "ValidConstraint_One"; }
    };

    struct ValidConstraint_Two
    {
        constexpr static bool is_satisfied(auto const& t) noexcept { return true; }
        inline static const char* error_message() noexcept { return "ValidConstraint_Two"; }
    };




    struct InvalidConstraint_One
    {
        constexpr static bool is_satisfied(auto const& t) noexcept { return false; }
        inline static const char* error_message() noexcept { return "InvalidConstraint_One"; }
    };

    struct InvalidConstraint_Two
    {
        constexpr static bool is_satisfied(auto const& t) noexcept { return false; }
        inline static const char* error_message() noexcept { return "InvalidConstraint_Two"; }
    };





    int set_by_ToggleConstraint = 0;

    struct ToggleConstraint_Satisfied
    {
        constexpr static bool is_satisfied(auto t) noexcept { set_by_ToggleConstraint = t; return true; }
        inline static const char* error_message() noexcept { return "ToggleConstraint"; }
    };

    struct ToggleConstraint_not_Satisfied
    {
        constexpr static bool is_satisfied(auto t) noexcept { set_by_ToggleConstraint = t; return false; }
        inline static const char* error_message() noexcept { return "ToggleConstraint"; }
    };

}

#endif //header guard