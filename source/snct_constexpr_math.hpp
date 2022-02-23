#ifndef SNCT_CONSTEXPR_MATH_HPP
#define SNCT_CONSTEXPR_MATH_HPP


/***************************************************************************************************/
/* Prior to C++23, <cmath> is not constexpr so we need our own versions of some of these functions */
/***************************************************************************************************/

#include <numeric>
#include <type_traits>

namespace snct
{

	[[nodiscard]] constexpr bool is_nan(std::floating_point auto t) noexcept
	{
		return t != t;
	}



	[[nodiscard]] constexpr bool is_positive_infinite(std::floating_point auto t) noexcept
	{
		return t == std::numeric_limits<decltype(t)>::infinity();
	}



	[[nodiscard]] constexpr bool is_negative_infinite(std::floating_point auto t) noexcept
	{
		return t == -1.0 * std::numeric_limits<decltype(t)>::infinity();
	}



	[[nodiscard]] constexpr bool is_infinite(std::floating_point auto t) noexcept
	{
		return is_positive_infinite(t) || is_negative_infinite(t);
	}

	 

	[[nodiscard]] constexpr bool is_finite(std::floating_point auto t) noexcept
	{
		return ! (is_infinite(t) || is_nan(t) );
	}



} //namespace
#endif //header guard