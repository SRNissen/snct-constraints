#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include "test_doubles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace {
	static constexpr int integerSeven = 7;
}

namespace individual_constraint::LessThan::IntegerSeven
{


	TEST_CLASS(is_not_satisfied_when_called_with)
	{
		TEST_METHOD(exactly_seven) {
			Assert::IsFalse(snct::LessThan<integerSeven>::is_satisfied(integerSeven));
		}



		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsFalse(snct::LessThan<integerSeven>::is_satisfied(integerSeven + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsFalse(snct::LessThan<integerSeven>::is_satisfied(integerSeven + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsFalse(snct::LessThan<integerSeven>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{
		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsTrue(snct::LessThan<integerSeven>::is_satisfied(integerSeven - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsTrue(snct::LessThan<integerSeven>::is_satisfied(integerSeven - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsTrue(snct::LessThan<integerSeven>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};
}



namespace individual_constraint::GreaterThan::IntegerSeven
{


	TEST_CLASS(is_not_satisfied_when_called_with)
	{


		TEST_METHOD(exactly_seven) {
			Assert::IsFalse(snct::GreaterThan<integerSeven>::is_satisfied(integerSeven));
		}



		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsFalse(snct::GreaterThan<integerSeven>::is_satisfied(integerSeven - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsFalse(snct::GreaterThan<integerSeven>::is_satisfied(integerSeven - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsFalse(snct::GreaterThan<integerSeven>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{
	
		
		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsTrue(snct::GreaterThan<integerSeven>::is_satisfied(integerSeven + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsTrue(snct::GreaterThan<integerSeven>::is_satisfied(integerSeven + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsTrue(snct::GreaterThan<integerSeven>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};
}



namespace individual_constraint::Minimum::IntegerSeven
{
	

	TEST_CLASS(is_not_satisfied_when_called_with)
	{



		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsFalse(snct::Minimum<integerSeven>::is_satisfied(integerSeven - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsFalse(snct::Minimum<integerSeven>::is_satisfied(integerSeven - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsFalse(snct::Minimum<integerSeven>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{



		TEST_METHOD(exactly_seven) {
			Assert::IsTrue(snct::Minimum<integerSeven>::is_satisfied(integerSeven));
		}



		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsTrue(snct::Minimum<integerSeven>::is_satisfied(integerSeven + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsTrue(snct::Minimum<integerSeven>::is_satisfied(integerSeven + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsTrue(snct::Minimum<integerSeven>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};
}



namespace individual_constraint::Maximum::IntegerSeven
{


	TEST_CLASS(is_not_satisfied_when_called_with)
	{



		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsFalse(snct::Maximum<integerSeven>::is_satisfied(integerSeven + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsFalse(snct::Maximum<integerSeven>::is_satisfied(integerSeven + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsFalse(snct::Maximum<integerSeven>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{



		TEST_METHOD(exactly_seven) {
			Assert::IsTrue(snct::Maximum<integerSeven>::is_satisfied(integerSeven));
		}



		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsTrue(snct::Maximum<integerSeven>::is_satisfied(integerSeven - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsTrue(snct::Maximum<integerSeven>::is_satisfied(integerSeven - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsTrue(snct::Maximum<integerSeven>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};
}