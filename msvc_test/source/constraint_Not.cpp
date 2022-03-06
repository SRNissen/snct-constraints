#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include "test_doubles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace constraint::Not::Nullptr
{
    TEST_CLASS(is_satisfied_when_called_with)
    {
        TEST_METHOD(a_cstring)
        {
            auto a = "hello";
            Assert::IsTrue(snct::Not<nullptr>::is_satisfied(a));
        }

        TEST_METHOD(an_int_pointer)
        {
            auto a = 8;
            Assert::IsTrue(snct::Not<nullptr>::is_satisfied(&a));
        }
    };

    TEST_CLASS(is_not_satisfied_when_called_with)
    {
        TEST_METHOD(a_nullptr)
        {
            Assert::IsFalse(snct::Not<nullptr>::is_satisfied( (void*)0 ));
        }
    };
}

namespace constraint::Not::NaN
{
    TEST_CLASS(is_satisfied_when_called_with_NotNaN_value) {

        TEST_METHOD(double_maximum) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::maximum)));
        }

        TEST_METHOD(double_minimum) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::minimum)));
        }

        TEST_METHOD(double_zero) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::zero)));
        }

        TEST_METHOD(double_one) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::one)));
        }

        TEST_METHOD(double_positive_lowest) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::positive_lowest)));
        }

        TEST_METHOD(double_negative_lowest) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::negative_lowest)));
        }

        TEST_METHOD(double_positive_infinity) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::positive_infinity)));
        }

        TEST_METHOD(double_negative_infinity) {
            Assert::IsTrue(snct::NotNaN::is_satisfied(Doubles.at(DD::negative_infinity)));
        }
    };

    TEST_CLASS(is_not_satisfied_when_called_with_NaN_value)
    {
        TEST_METHOD(double_signallign_NaN) {
            Assert::IsFalse(snct::NotNaN::is_satisfied(Doubles.at(DD::signalling_NaN)));
        }
        TEST_METHOD(double_quiet_NaN) {
            Assert::IsFalse(snct::NotNaN::is_satisfied(Doubles.at(DD::quiet_NaN)));
        }
    };
}

namespace constraint::Not::SevenPointFive
{
    static constexpr double sevenPointFive = 7.5; // any arbitrary value that isn't nullptr or NaN

    TEST_CLASS(is_not_satisfied_when_called_With_specified_value)
    {
        
        TEST_METHOD(double_specified)
        {
            Assert::IsFalse(snct::Not<sevenPointFive>::is_satisfied(sevenPointFive));
        }
    };

    TEST_CLASS(is_satisified_when_called_with_non_specified_value)
    {
        TEST_METHOD(double_maximum) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::maximum)));
        }

        TEST_METHOD(double_minimum) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::minimum)));
        }

        TEST_METHOD(double_zero) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::zero)));
        }

        TEST_METHOD(double_one) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::one)));
        }

        TEST_METHOD(double_positive_lowest) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::positive_lowest)));
        }

        TEST_METHOD(double_negative_lowest) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::negative_lowest)));
        }

        TEST_METHOD(double_positive_infinity) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::positive_infinity)));
        }

        TEST_METHOD(double_negative_infinity) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::negative_infinity)));
        }

        TEST_METHOD(double_signallign_NaN) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::signalling_NaN)));
        }
        TEST_METHOD(double_quiet_NaN) {
            Assert::IsTrue(snct::Not<sevenPointFive>::is_satisfied(Doubles.at(DD::quiet_NaN)));
        }
    };
}