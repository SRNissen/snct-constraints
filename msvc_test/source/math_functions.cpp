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

			TEST_METHOD(on_positive_max) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_max);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_min) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_min);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_denormalized_min) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_denormalized_min);

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

			TEST_METHOD(on_negative_max) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_max);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_min) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_min);

				//Act
				auto actual_returnvalue = snct::is_nan(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_denormalized_min) {
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_denormalized_min);

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
			TEST_METHOD(on_positive_infinity)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_signalling_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_quiet_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_max)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_max);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_min);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_infinity)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_max)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_max);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_min);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//ACT
				const auto actual_returnvalue = snct::is_positive_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}

	namespace is_negative_infinite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_negative_infinity)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_signalling_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_quiet_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_infinity)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_max)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_max);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_min);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_max)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_max);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_min);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//ACT
				const auto actual_returnvalue = snct::is_negative_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}

	namespace is_infinite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_positive_infinity)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_infinity)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_signalling_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_quiet_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_max)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_max);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_min);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_max)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_max);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_min);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::zero);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::one);

				//ACT
				const auto actual_returnvalue = snct::is_infinite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}
	namespace is_finite
	{
		TEST_CLASS(returns_true)
		{
			TEST_METHOD(on_positive_max)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_max);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_min)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_min);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::positive_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_max)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_max);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_min)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_min);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_denormalized_min)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::negative_denormalized_min);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_zero)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::zero);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_one)
			{
				//Arrange
				const auto expected_returnvalue = true;
				const auto input_value = Doubles.at(DD::one);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};

		TEST_CLASS(returns_false)
		{
			TEST_METHOD(on_signalling_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::signalling_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_quiet_NaN)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::quiet_NaN);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_positive_infinity)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::positive_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}

			TEST_METHOD(on_negative_infinity)
			{
				//Arrange
				const auto expected_returnvalue = false;
				const auto input_value = Doubles.at(DD::negative_infinity);

				//ACT
				const auto actual_returnvalue = snct::is_finite(input_value);

				//Assert
				Assert::AreEqual(expected_returnvalue, actual_returnvalue);
			}
		};
	}
}
