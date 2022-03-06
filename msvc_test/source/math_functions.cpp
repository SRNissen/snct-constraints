#include "CppUnitTest.h"
#include "snct_constexpr_math.hpp"
#include "test_doubles.h"
#include <array>
#include <utility>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace constexpr_math_function
{
	namespace is_nan 
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_signalling_NaN) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_quiet_NaN) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_positive_infinity) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_infinity) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_lowest);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_lowest);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_minimum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::minimum);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_maximum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::maximum);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}

	namespace is_positive_infinite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_positive_infinity) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_quiet_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_signalling_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_infinity) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_lowest);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_lowest);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_minimum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::minimum);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_maximum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::maximum);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//Act
				auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}

	namespace is_negative_infinite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_negative_infinity) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_quiet_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_signalling_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_infinity) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_lowest);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_lowest);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_minimum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::minimum);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_maximum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::maximum);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//Act
				auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}

	namespace is_infinite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_positive_infinity) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_negative_infinity) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_signalling_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_quiet_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_positive_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_lowest);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_negative_lowest) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_lowest);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_minimum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::minimum);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_maximum) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::maximum);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_zero) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
			TEST_METHOD(on_one) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//Act
				auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}
	namespace is_finite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_positive_lowest) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_lowest);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_lowest) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_lowest);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_minimum) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::minimum);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_maximum) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::maximum);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::zero);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one) {
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::one);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_signalling_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_quiet_NaN) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_infinity) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_infinity) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//Act
				auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

		};
	}
}
