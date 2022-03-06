#include "CppUnitTest.h"
#include "snct_constexpr_math.hpp"
#include "test_doubles.h"
#include <array>
#include <utility>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace constexpr_math_function
{
    TEST_CLASS(is_nan)
    {
    public:

        TEST_METHOD(returns_EXPECTED_on_INPUT)
        {

            using expected = bool;
            using input = double;
            auto pairs = std::array<std::pair<expected, input>, 10>
            {
                {
                    { true, Doubles.at(DD::signalling_NaN) },
                    { true, Doubles.at(DD::quiet_NaN) },
                    { false,Doubles.at(DD::positive_infinity) },
                    { false,Doubles.at(DD::negative_infinity) },
                    { false,Doubles.at(DD::positive_lowest) },
                    { false,Doubles.at(DD::negative_lowest) },
                    { false,Doubles.at(DD::minimum) },
                    { false,Doubles.at(DD::maximum) },
                    { false,Doubles.at(DD::zero) },
                    { false,Doubles.at(DD::one) }
                }
            };

            for (auto const & [expected, input] : pairs)
            {
                Assert::AreEqual(expected, snct::is_nan(input));
            }
        }
    };
    TEST_CLASS(is_positive_infinite)
    {
        TEST_METHOD(returns_EXPECTED_on_INPUT)
        {

            using expected = bool;
            using input = double;
            auto pairs = std::array<std::pair<expected, input>, 10>
            {
                {
                    { false, Doubles.at(DD::quiet_NaN) },
                    { false, Doubles.at(DD::signalling_NaN) },
                    { true,  Doubles.at(DD::positive_infinity) },
                    { false, Doubles.at(DD::negative_infinity) },
                    { false, Doubles.at(DD::positive_lowest) },
                    { false, Doubles.at(DD::negative_lowest) },
                    { false, Doubles.at(DD::minimum) },
                    { false, Doubles.at(DD::maximum) },
                    { false, Doubles.at(DD::zero) },
                    { false, Doubles.at(DD::one) }
                }
            };

            for (auto const& [expected, input] : pairs)
            {
                Assert::AreEqual(expected, snct::is_positive_infinite(input));
            }
        }
    };
    TEST_CLASS(is_negative_infinite)
    {
        TEST_METHOD(returns_EXPECTED_on_INPUT)
        {

            using expected = bool;
            using input = double;
            auto pairs = std::array<std::pair<expected, input>, 10>
            {
                {
                    { false, Doubles.at(DD::signalling_NaN) },
                    { false, Doubles.at(DD::quiet_NaN) },
                    { false, Doubles.at(DD::positive_infinity) },
                    { true,  Doubles.at(DD::negative_infinity) },
                    { false, Doubles.at(DD::positive_lowest) },
                    { false, Doubles.at(DD::negative_lowest) },
                    { false, Doubles.at(DD::minimum) },
                    { false, Doubles.at(DD::maximum) },
                    { false, Doubles.at(DD::zero) },
                    { false, Doubles.at(DD::one) }
                }
            };

            for (auto const& [expected, input] : pairs)
            {
                Assert::AreEqual(expected, snct::is_negative_infinite(input));
            }
        }
    };
    TEST_CLASS(is_infinite)
    {
        TEST_METHOD(returns_EXPECTED_on_INPUT)
        {

            using expected = bool;
            using input = double;
            auto pairs = std::array<std::pair<expected, input>, 10>
            {
                {
                    { false, Doubles.at(DD::signalling_NaN) },
                    { false, Doubles.at(DD::quiet_NaN) },
                    { true,  Doubles.at(DD::positive_infinity) },
                    { true,  Doubles.at(DD::negative_infinity) },
                    { false, Doubles.at(DD::positive_lowest) },
                    { false, Doubles.at(DD::negative_lowest) },
                    { false, Doubles.at(DD::minimum) },
                    { false, Doubles.at(DD::maximum) },
                    { false, Doubles.at(DD::zero) },
                    { false, Doubles.at(DD::one) }
                }
            };

            for (auto const& [expected, input] : pairs)
            {
                Assert::AreEqual(expected, snct::is_infinite(input));
            }
        }
    };
    TEST_CLASS(is_finite)
    {
        TEST_METHOD(returns_EXPECTED_on_INPUT)
        {

            using expected = bool;
            using input = double;
            auto pairs = std::array<std::pair<expected, input>, 10>
            {
                {
                    { false, Doubles.at(DD::signalling_NaN) },
                    { false, Doubles.at(DD::quiet_NaN) },
                    { false, Doubles.at(DD::positive_infinity) },
                    { false, Doubles.at(DD::negative_infinity) },
                    { true,  Doubles.at(DD::positive_lowest) },
                    { true,  Doubles.at(DD::negative_lowest) },
                    { true,  Doubles.at(DD::minimum) },
                    { true,  Doubles.at(DD::maximum) },
                    { true,  Doubles.at(DD::zero) },
                    { true,  Doubles.at(DD::one) }
                }
            };

            for (auto const& [expected, input] : pairs)
            {
                Assert::AreEqual(expected, snct::is_finite(input));
            }
        }
    };
}
