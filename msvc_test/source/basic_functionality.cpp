#include "CppUnitTest.h"
#include "snct_constrained.hpp"
#include "test_constraints.h"
#include <string_view>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace snct_constrained
{
	TEST_CLASS(constrained_object_stores_parameter_on_succesful_construction)
	{
		TEST_METHOD(using_the_factory)
		{
			// Arrange
			using Storage = snct::Constrained<double, ValidConstraint_One>;
			double parameter = 2.2;

			// Act
			double storedParameter = Storage::factory(parameter).value();

			// Assert
			Assert::AreEqual(parameter, storedParameter);	
		}



		TEST_METHOD(using_the_ctor)
		{
			// Arrange
			using Storage = snct::Constrained<double, ValidConstraint_One>;
			double parameter = 2.2;

			// Act
			double storedParameter = Storage{ parameter };

			// Assert
			Assert::AreEqual(parameter, storedParameter);
		}
	};

	TEST_CLASS(ctor_actually_passes_parameter_to_constraints) {


		TEST_METHOD(when_the_constraint_is_satisfied) {
			// Arrange
			const auto toggleValue = 7;
			set_by_ToggleConstraint = 0;

			using Toggle = snct::Constrained<int, ToggleConstraint_Satisfied>;

			// Act
			try {
				Toggle{ toggleValue };
			}
			catch (...) {}

			// Assert
			Assert::AreEqual(toggleValue, set_by_ToggleConstraint);
		}



		TEST_METHOD(when_the_constraint_is_not_satisfied) {
			// Arrange
			const auto toggleValue = 7;
			set_by_ToggleConstraint = 0;

			using Toggle = snct::Constrained<int, ToggleConstraint_not_Satisfied>;

			// Act
			try {
				Toggle{ toggleValue };
			}
			catch (...) {}

			// Assert
			Assert::AreEqual(toggleValue, set_by_ToggleConstraint);
		}
	};


	TEST_CLASS(ctor_will_throw_snct_ConstraintException) {


		TEST_METHOD(when_there_is_one_constraint_and_it_is_not_satisfied) {

			// Arrange
			using ShouldThrowConstraintException = snct::Constrained<double, InvalidConstraint_One>;
			bool ctor_threw_snct_ConstraintException = false;
			bool ctor_threw_other_exception = false;

			// Act
			try {
				ShouldThrowConstraintException{ 2.2 /*any arbitrary value of the constrained type */ };
			}
			catch (snct::Constraint_Exception const&) {
				ctor_threw_snct_ConstraintException = true;
			}
			catch (...) {
				ctor_threw_other_exception = true;
			}


			// Assert
			Assert::IsTrue(ctor_threw_snct_ConstraintException);
			Assert::IsFalse(ctor_threw_other_exception);

		}



		TEST_METHOD(when_there_are_several_constraints_and_none_are_satisfied) {

			// Arrange
			using ShouldThrowConstraintException = snct::Constrained<double, InvalidConstraint_One, InvalidConstraint_Two>;
			bool ctor_threw_snct_ConstraintException = false;
			bool ctor_threw_other_exception = false;

			// Act
			try {
				ShouldThrowConstraintException{ 2.2 /*any arbitrary value of the constrained type */ };
			}
			catch (snct::Constraint_Exception const&) {
				ctor_threw_snct_ConstraintException = true;
			}
			catch (...) {
				ctor_threw_other_exception = true;
			}


			// Assert
			Assert::IsTrue(ctor_threw_snct_ConstraintException);
			Assert::IsFalse(ctor_threw_other_exception);

		}


		TEST_METHOD(when_there_are_several_constraints_and_just_one_is_not_satisfied) {

			// Arrange
			using ShouldThrowConstraintException = snct::Constrained<double, ValidConstraint_One, ValidConstraint_Two, InvalidConstraint_One>;
			bool ctor_threw_snct_ConstraintException = false;
			bool ctor_threw_other_exception = false;

			// Act
			try {
				ShouldThrowConstraintException{ 2.2 /*any arbitrary value of the constrained type */ };
			}
			catch (snct::Constraint_Exception const&) {
				ctor_threw_snct_ConstraintException = true;
			}
			catch (...) {
				ctor_threw_other_exception = true;
			}


			// Assert
			Assert::IsTrue(ctor_threw_snct_ConstraintException);
			Assert::IsFalse(ctor_threw_other_exception);
		}


		TEST_METHOD(when_any_constraint_is_not_satisfied_even_if_the_last_constraint_is_satisfied) {

			// Arrange
			using ShouldThrowConstraintException = snct::Constrained<double, InvalidConstraint_One, ValidConstraint_One>;
			bool ctor_threw_snct_ConstraintException = false;
			bool ctor_threw_other_exception = false;

			// Act
			try {
				ShouldThrowConstraintException{ 2.2 /*any arbitrary value of the constrained type */ };
			}
			catch (snct::Constraint_Exception const&) {
				ctor_threw_snct_ConstraintException = true;
			}
			catch (...) {
				ctor_threw_other_exception = true;
			}


			// Assert
			Assert::IsTrue(ctor_threw_snct_ConstraintException);
			Assert::IsFalse(ctor_threw_other_exception);
		}

	};


	TEST_CLASS(ctor_will_not_throw) {


		TEST_METHOD(when_there_is_one_constraint_and_it_is_satisfied) {

			// Arrange
			using Should_Not_ThrowConstraintException = snct::Constrained<double, ValidConstraint_One>;
			bool ctor_threw_snct_ConstraintException = false;
			bool ctor_threw_other_exception = false;

			// Act
			try {
				Should_Not_ThrowConstraintException{ 2.2 /*any arbitrary value of the constrained type */ };
			}
			catch (snct::Constraint_Exception const&) {
				ctor_threw_snct_ConstraintException = true;
			}
			catch (...) {
				ctor_threw_other_exception = true;
			}


			// Assert
			Assert::IsFalse(ctor_threw_snct_ConstraintException);
			Assert::IsFalse(ctor_threw_other_exception);
		}



		TEST_METHOD(when_there_are_several_constraints_and_all_are_satisfied) {

			// Arrange
			using Should_Not_ThrowConstraintException = snct::Constrained<double, ValidConstraint_One, ValidConstraint_Two>;
			bool ctor_threw_snct_ConstraintException = false;
			bool ctor_threw_other_exception = false;

			// Act
			try {
				Should_Not_ThrowConstraintException{ 2.2 /*any arbitrary value of the constrained type */ };
			}
			catch (snct::Constraint_Exception const&) {
				ctor_threw_snct_ConstraintException = true;
			}
			catch (...) {
				ctor_threw_other_exception = true;
			}


			// Assert
			Assert::IsFalse(ctor_threw_snct_ConstraintException);
			Assert::IsFalse(ctor_threw_other_exception);

		}
	};


	TEST_CLASS(factory_returns_nullopt)	{


		TEST_METHOD(when_there_is_one_constraint_and_it_is_not_satisfied) {

			// Arrange
			using ShouldReturnNullopt = snct::Constrained<double, InvalidConstraint_One>;

			// Act
			auto opt = ShouldReturnNullopt::factory(2.2 /*any arbitrary value of the constrained type */);

			// Assert
			Assert::IsFalse(opt.has_value());
		}



		TEST_METHOD(when_there_are_several_constraints_and_none_are_satisfied) {

			// Arrange
			using ShouldReturnNullopt = snct::Constrained<double, InvalidConstraint_One, InvalidConstraint_Two>;

			// Act
			auto opt = ShouldReturnNullopt::factory(2.2 /*any arbitrary value of the constrained type */);

			// Assert
			Assert::IsFalse(opt.has_value());
		}


		TEST_METHOD(when_there_are_several_constraints_and_just_one_is_not_satisfied) {

			// Arrange
			using ShouldReturnNullopt = snct::Constrained<double, ValidConstraint_One, ValidConstraint_Two, InvalidConstraint_One>;

			// Act
			auto opt = ShouldReturnNullopt::factory(2.2 /*any arbitrary value of the constrained type */);

			// Assert
			Assert::IsFalse(opt.has_value());
		}

		TEST_METHOD(when_any_constraint_is_not_satisfied_even_if_the_last_constraint_is_satisfied) {
			
			// Arrange
			using ShouldReturnNullopt = snct::Constrained<double, InvalidConstraint_One, ValidConstraint_One>;

			// Act
			auto opt = ShouldReturnNullopt::factory(2.2 /*any arbitrary value of the constrained type */);

			// Assert
			Assert::IsFalse(opt.has_value());
		}
	};

	TEST_CLASS(factory_returns_valid_optional) {


		TEST_METHOD(when_there_is_one_constraint_and_it_is_satisfied) {

			// Arrange
			using Should_Not_ReturnNullopt = snct::Constrained<double, ValidConstraint_One>;

			// Act
			auto opt = Should_Not_ReturnNullopt::factory(2.2 /*any arbitrary value of the constrained type */);

			// Assert
			Assert::IsTrue(opt.has_value());
		}



		TEST_METHOD(when_there_are_several_constraints_and_all_are_satisfied) {

			// Arrange
			using Should_Not_ReturnNullopt = snct::Constrained<double, ValidConstraint_One, ValidConstraint_Two>;

			// Act
			auto opt = Should_Not_ReturnNullopt::factory(2.2 /*any arbitrary value of the constrained type */);

			// Assert
			Assert::IsTrue(opt.has_value());
		}
	};
}