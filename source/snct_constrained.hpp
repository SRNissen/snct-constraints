#ifndef SNCT_CONSTRAINED_HPP
#define SNCT_CONSTRAINED_HPP

#include <concepts>
#include <type_traits>
#include <exception>
#include <optional>



namespace snct
{

    template<typename ConstraintType, typename ValueType>
    concept Constraint = requires(ValueType v)
    {
        { ConstraintType::is_satisfied(v) } noexcept -> std::same_as<bool>;
        { ConstraintType::error_message() } noexcept -> std::same_as<const char*>;
    };



    template<typename T, Constraint<T> ... constraint>
    class Constrained
    {
    public:

        Constrained() = delete;

        [[nodiscard]] constexpr operator T const & () const { return underlying_; }

        constexpr Constrained(T t); // throws Constraint_Exception on constraint violation

        [[nodiscard]] static constexpr std::optional<Constrained> factory(T t) noexcept; // returns std::nullopt on constraint violation

    private:
        class Factoryparam {};
        constexpr Constrained(T t, Factoryparam) : underlying_{ t } {};
        T underlying_;
    };



    class Constraint_Exception : public std::exception
    {
    public:
        Constraint_Exception(const char* error_message) noexcept : error_message_{ error_message } {}
        const char* what()  const noexcept override { return error_message_; }
    private:
        const char* error_message_;
    };



    template<typename T, Constraint<T> ... constraint>
    [[nodiscard]] inline constexpr Constrained<T, constraint ...>::Constrained(T t) : underlying_{ t }
    {
        ((constraint::is_satisfied(t) ? void(0) : throw Constraint_Exception{ constraint::error_message() }), ...);
    }



    template<typename T, Constraint<T> ... constraint>
    [[nodiscard]] inline constexpr std::optional<Constrained<T, constraint ...>> Constrained<T, constraint ...>::factory(T t) noexcept
    {
        bool const all_satisfied = ((constraint::is_satisfied(t) ? true : false) && ...);

        if (all_satisfied)
            return Constrained{ t, Factoryparam{} };
        else
            return std::nullopt;
    }


} //namespace

#endif //header guard