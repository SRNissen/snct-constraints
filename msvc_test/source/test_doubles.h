#ifndef SNCT_TEST_DOUBLES_H
#define SNCT_TEST_DOUBLES_H

#include <limits>
#include <unordered_map>

namespace {

	enum class DD
	{
		signalling_NaN,
		quiet_NaN,

		positive_infinity,
		positive_max,
		positive_min,
		positive_denormalized_min,

		negative_infinity,
		negative_max,
		negative_min,
		negative_denormalized_min,

		zero,
		one
	};

	auto const Doubles = std::unordered_map<DD, double>
	{
		{DD::signalling_NaN, std::numeric_limits<double>::signaling_NaN()},
		{DD::quiet_NaN, std::numeric_limits<double>::quiet_NaN()},
		
		{DD::positive_infinity, std::numeric_limits<double>::infinity()},
		{DD::positive_max,std::numeric_limits<double>::max()},
		{DD::positive_min,std::numeric_limits<double>::min()},
		{DD::positive_denormalized_min,std::numeric_limits<double>::denorm_min()},
		
		{DD::negative_infinity, std::numeric_limits<double>::infinity() * -1.0},
		{DD::negative_max,std::numeric_limits<double>::max() * -1.0},
		{DD::negative_min,std::numeric_limits<double>::min() * -1.0},
		{DD::negative_denormalized_min,std::numeric_limits<double>::denorm_min() * -1.0},
		
		{DD::zero, 0.0},
		{DD::one, 1.0},
	};
}

#endif