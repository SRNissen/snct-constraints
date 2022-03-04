#include "CppUnitTest.h"
#include "snct_constexpr_math.hpp"
#include "test_doubles.h"
#include <array>
#include <utility>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace math_functions
{

    TEST_CLASS(snct_constexpr_math_function)
    {
    public:

        TEST_METHOD(is_nan_returns_EXPECTED_on_INPUT)
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

        TEST_METHOD(is_positive_infinite_returns_EXPECTED_on_INPUT)
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

        TEST_METHOD(is_negative_infinite_returns_EXPECTED_on_INPUT)
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

        TEST_METHOD(is_infinite_returns_EXPECTED_on_INPUT)
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

        TEST_METHOD(is_finite_returns_EXPECTED_on_INPUT)
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
