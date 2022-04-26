#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include "test_doubles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace constraint::Finite
{
	TEST_CLASS(is_satisfied_when_called_with_finite_value) {
		TEST_METHOD(double_positive_max) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::positive_max)));
		}
		TEST_METHOD(double_positive_min) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::positive_min)));
		}
		TEST_METHOD(double_positive_denormalized_min) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::positive_denormalized_min)));
		}
		TEST_METHOD(double_negative_max) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::negative_max)));
		}
		TEST_METHOD(double_negative_min) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::negative_min)));
		}
		TEST_METHOD(double_negative_denormalized_min) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::negative_denormalized_min)));
		}
		TEST_METHOD(double_zero) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::zero)));
		}
		TEST_METHOD(double_one) {
			Assert::IsTrue(snct::Finite::is_satisfied(Doubles.at(DD::one)));
		}
	};

	TEST_CLASS(is_not_satisfied_when_called_with_non_finite_value)
	{
		TEST_METHOD(double_signalling_NaN) {
			Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::signalling_NaN)));
		}
		TEST_METHOD(double_quiet_NaN) {
			Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::quiet_NaN)));
		}
		TEST_METHOD(double_positive_infinity) {
			Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::positive_infinity)));
		}
		TEST_METHOD(double_negative_infinity) {
			Assert::IsFalse(snct::Finite::is_satisfied(Doubles.at(DD::negative_infinity)));
		}
	};
}