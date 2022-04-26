#include "CppUnitTest.h"
#include "snct_constraints.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace {
	static constexpr int arbitraryInteger = 7;
}

namespace constraint::LessThan::ArbitraryInteger
{


	TEST_CLASS(is_not_satisfied_when_called_with)
	{
		TEST_METHOD(exactly_that_arbitrary_integer) {
			Assert::IsFalse(snct::LessThan<arbitraryInteger>::is_satisfied(arbitraryInteger));
		}



		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsFalse(snct::LessThan<arbitraryInteger>::is_satisfied(arbitraryInteger + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsFalse(snct::LessThan<arbitraryInteger>::is_satisfied(arbitraryInteger + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsFalse(snct::LessThan<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{
		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsTrue(snct::LessThan<arbitraryInteger>::is_satisfied(arbitraryInteger - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsTrue(snct::LessThan<arbitraryInteger>::is_satisfied(arbitraryInteger - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsTrue(snct::LessThan<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};
}



namespace constraint::GreaterThan::ArbitraryInteger
{


	TEST_CLASS(is_not_satisfied_when_called_with)
	{


		TEST_METHOD(exactly_that_arbitrary_integer) {
			Assert::IsFalse(snct::GreaterThan<arbitraryInteger>::is_satisfied(arbitraryInteger));
		}



		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsFalse(snct::GreaterThan<arbitraryInteger>::is_satisfied(arbitraryInteger - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsFalse(snct::GreaterThan<arbitraryInteger>::is_satisfied(arbitraryInteger - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsFalse(snct::GreaterThan<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{
	
		
		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsTrue(snct::GreaterThan<arbitraryInteger>::is_satisfied(arbitraryInteger + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsTrue(snct::GreaterThan<arbitraryInteger>::is_satisfied(arbitraryInteger + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsTrue(snct::GreaterThan<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};
}



namespace constraint::Minimum::ArbitraryInteger
{
	

	TEST_CLASS(is_not_satisfied_when_called_with)
	{



		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsFalse(snct::Minimum<arbitraryInteger>::is_satisfied(arbitraryInteger - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsFalse(snct::Minimum<arbitraryInteger>::is_satisfied(arbitraryInteger - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsFalse(snct::Minimum<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{



		TEST_METHOD(exactly_that_arbitrary_integer) {
			Assert::IsTrue(snct::Minimum<arbitraryInteger>::is_satisfied(arbitraryInteger));
		}



		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsTrue(snct::Minimum<arbitraryInteger>::is_satisfied(arbitraryInteger + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsTrue(snct::Minimum<arbitraryInteger>::is_satisfied(arbitraryInteger + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsTrue(snct::Minimum<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};
}



namespace constraint::Maximum::ArbitraryInteger
{


	TEST_CLASS(is_not_satisfied_when_called_with)
	{



		TEST_METHOD(edge_case_off_by_one_greater) {
			Assert::IsFalse(snct::Maximum<arbitraryInteger>::is_satisfied(arbitraryInteger + 1));
		}



		TEST_METHOD(arbitrarily_greater_value) {
			Assert::IsFalse(snct::Maximum<arbitraryInteger>::is_satisfied(arbitraryInteger + 1000));
		}



		TEST_METHOD(edge_case_int_max) {
			Assert::IsFalse(snct::Maximum<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::max()));
		}
	};



	TEST_CLASS(is_satisfied_when_called_with)
	{



		TEST_METHOD(exactly_that_arbitrary_integer) {
			Assert::IsTrue(snct::Maximum<arbitraryInteger>::is_satisfied(arbitraryInteger));
		}



		TEST_METHOD(edge_case_off_by_one_lesser) {
			Assert::IsTrue(snct::Maximum<arbitraryInteger>::is_satisfied(arbitraryInteger - 1));
		}



		TEST_METHOD(arbitrarily_lesser_value) {
			Assert::IsTrue(snct::Maximum<arbitraryInteger>::is_satisfied(arbitraryInteger - 1000));
		}



		TEST_METHOD(edge_case_int_min) {
			Assert::IsTrue(snct::Maximum<arbitraryInteger>::is_satisfied(std::numeric_limits<int>::min()));
		}
	};
}