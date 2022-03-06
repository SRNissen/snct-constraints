#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include "test_doubles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace constraint::Finite
{
    TEST_CLASS(is_satisfied_when_called_with_finite_value) {
        TEST_METHOD(double_maximum) {
            Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::maximum)));
        }

        TEST_METHOD(double_minimum) {
            Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::minimum)));
        }

        TEST_METHOD(double_zero) {
            Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::zero)));
        }

        TEST_METHOD(double_one) {
            Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::one)));
        }

        TEST_METHOD(double_positive_lowest) {
            Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::positive_lowest)));
        }

        TEST_METHOD(double_negative_lowest) {
            Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::negative_lowest)));
        }
    };

    TEST_CLASS(is_not_satisfied_when_called_with_non_finite_value)
    {
        TEST_METHOD(double_positive_infinity) {
            Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::positive_infinity)));
        }

        TEST_METHOD(double_negative_infinity) {
            Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::negative_infinity)));
        }

        TEST_METHOD(double_signallign_NaN) {
            Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::signalling_NaN)));
        }

        TEST_METHOD(double_quiet_NaN) {
            Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::quiet_NaN)));
        }
    };
}