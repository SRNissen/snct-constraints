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
        negative_infinity,
        positive_lowest,
        negative_lowest,
        minimum,
        maximum,
        zero,
        one
    };

    auto const Doubles = std::unordered_map<DD, double>
    {
        {DD::signalling_NaN, std::numeric_limits<double>::signaling_NaN()},
        {DD::quiet_NaN, std::numeric_limits<double>::quiet_NaN()},
        {DD::positive_infinity, std::numeric_limits<double>::infinity()},
        {DD::negative_infinity, std::numeric_limits<double>::infinity() * -1.0},
        {DD::positive_lowest, std::numeric_limits<double>::lowest()},
        {DD::negative_lowest, std::numeric_limits<double>::lowest() * -1.0},
        {DD::minimum, std::numeric_limits<double>::min()},
        {DD::maximum, std::numeric_limits<double>::max()},
        {DD::zero, 0.0},
        {DD::one, 1.0},
    };
}

#endif