#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include <array>
#include <unordered_map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace individual_constraint
{
	enum class Double
	{
		signalling_NaN,
		quiet_NaN,
		positive_infinity,
		negative_infinity,
		positive_lowest,
		negative_lowest,
		minimum,
		maximum,
		zero,
		one
	};

	auto Doubles = std::unordered_map<Double, double>
	{
		{Double::signalling_NaN, std::numeric_limits<double>::signaling_NaN()},
		{Double::quiet_NaN, std::numeric_limits<double>::quiet_NaN()},
		{Double::positive_infinity, std::numeric_limits<double>::infinity()},
		{Double::negative_infinity, std::numeric_limits<double>::infinity() * -1.0},
		{Double::positive_lowest, std::numeric_limits<double>::lowest()},
		{Double::negative_lowest, std::numeric_limits<double>::lowest() * -1.0},
		{Double::minimum, std::numeric_limits<double>::min()},
		{Double::maximum, std::numeric_limits<double>::max()},
		{Double::zero, 0.0},
		{Double::one, 1.0},
	};

	TEST_CLASS(snct_finite)
	{
	public:

		using Finite = snct::Constrained<double, snct::Finite>;

		TEST_METHOD(can_not_be_constructed_with_non_finite_values)
		{
			auto non_finite_values = std::to_array({
				Doubles[Double::signalling_NaN],
				Doubles[Double::quiet_NaN],
				Doubles[Double::positive_infinity],
				Doubles[Double::negative_infinity]
				}
			);

			bool threw_on_all_values = true;

			for (auto value : non_finite_values)
			{
				try
				{
					auto should_throw = Finite{ value };
					threw_on_all_values = false;
				}
				catch (snct::Constraint_Exception const&)
				{

				}
			}

			Assert::IsTrue(threw_on_all_values, L"snct::Finite Failed to throw an exception on assignment of a non-finite value");
		}

		TEST_METHOD(can_be_constructed_with_finite_values)
		{
			auto finite_values = std::to_array(
				{
					Doubles[Double::positive_lowest],
					Doubles[Double::negative_lowest],
					Doubles[Double::minimum],
					Doubles[Double::maximum],
					Doubles[Double::zero],
					Doubles[Double::one]
				}
			);

			bool did_not_throw = true;

			try
			{
				for (auto value : finite_values)
				{
					auto should_not_throw = Finite{ value };
				}
			}
			catch (snct::Constraint_Exception const&)
			{
				did_not_throw = false;
			}

			Assert::IsTrue(did_not_throw, L"snct::Finite threw an exception on assignment of a finite value");
		}
	};

	TEST_CLASS(snct_NotNaN)
	{
	public:

		using NotNaN = snct::Constrained<double, snct::NotNaN>;

		TEST_METHOD(can_not_be_constructed_with_NaN_values)
		{
			auto NaN_values = std::to_array(
				{
				Doubles[Double::signalling_NaN],
				Doubles[Double::quiet_NaN]
				}
			);

			bool threw_on_all_values = true;

			for (auto value : NaN_values)
			{
				try
				{
					auto should_throw = NotNaN{ value };
					threw_on_all_values = false;
				}
				catch (snct::Constraint_Exception const&)
				{

				}
			}

			Assert::IsTrue(threw_on_all_values, L"snct::NotNaN Failed to throw an exception on assignment of a NaN value");
		}

		TEST_METHOD(can_be_constructed_with_values_that_are_not_NaN)
		{
			auto not_NaN_values = std::to_array
			(
				{
					Doubles[Double::positive_infinity],
					Doubles[Double::negative_infinity],
					Doubles[Double::positive_lowest],
					Doubles[Double::negative_lowest],
					Doubles[Double::minimum],
					Doubles[Double::maximum],
					Doubles[Double::zero],
					Doubles[Double::one]
				}
			);

			bool did_not_throw_on_any_values = true;

			for (auto value : not_NaN_values)
			{
				try
				{
					auto should_not_throw = NotNaN{ value };
				}
				catch (snct::Constraint_Exception const&)
				{
					did_not_throw_on_any_values = false;
				}
			}

			Assert::IsTrue(did_not_throw_on_any_values, L"snct::NotNaN threw an exception on assignment of a value that was not NaN");
		}
	};

	TEST_CLASS(snct_Not_double)
	{
	public:

		using Not_double = snct::Constrained<double, snct::Not<5.5>>;

		TEST_METHOD(can_not_be_constructed_with_specified_double)
		{
			bool rejected_specified_double = false;
			try
			{
				auto should_throw = Not_double{ 5.5 };
			}
			catch (snct::Constraint_Exception const&)
			{
				rejected_specified_double = true;
			}
			Assert::IsTrue(rejected_specified_double, L"Not_double failed to reject specified double");
		}

		TEST_METHOD(can_be_constructed_with_other_doubles)
		{
			bool no_rejections = true;
			{
				try
				{
					for (auto const& [name, value] : Doubles)
					{
						Not_double{ value };
					}
				}
				catch (snct::Constraint_Exception const&)
				{
					no_rejections = false;
				}
				Assert::IsTrue(no_rejections, L"Not_double rejected a value that was not the specified value");
			}
		}

	};

	TEST_CLASS(snct_Not_nullptr) 
	{

		using Not_const_nullptr = snct::Constrained<const char*, snct::Not<nullptr>>;

		TEST_METHOD(can_not_be_constructed_with_const_nullptr)
		{
			bool rejected_specified_const_pointer = false;
			try
			{
				auto should_throw = Not_const_nullptr{ nullptr };
			}
			catch (snct::Constraint_Exception const&)
			{
				rejected_specified_const_pointer = true;
			}
			Assert::IsTrue(rejected_specified_const_pointer, L"Not_pointer failed to reject specified pointer");
		}

		TEST_METHOD(can_be_constructed_with_other_const_pointers)
		{
			bool no_rejections = true;
			{
				try
				{
					auto test = Not_const_nullptr{ "Test" };

				}
				catch (snct::Constraint_Exception const&)
				{
					no_rejections = false;
				}
				Assert::IsTrue(no_rejections, L"Not_pointer rejected a const pointer that was not the specified const pointer");
			}
		}


		using Not_nullptr = snct::Constrained<char*, snct::Not<nullptr>>;

		TEST_METHOD(can_not_be_constructed_with_nonconst_nullptr)
		{
			bool rejected_specified_pointer = false;
			try
			{
				auto should_throw = Not_nullptr{ nullptr };
			}
			catch (snct::Constraint_Exception const&)
			{
				rejected_specified_pointer = true;
			}
			Assert::IsTrue(rejected_specified_pointer, L"Not_pointer failed to reject specified pointer");
		}

		TEST_METHOD(can_be_constructed_with_other_nonconst_pointers)
		{
			bool no_rejections = true;
			{
				try
				{
					char test = 't';
					auto Test = Not_nullptr{ &test };

				}
				catch (snct::Constraint_Exception const&)
				{
					no_rejections = false;
				}
				Assert::IsTrue(no_rejections, L"Not_pointer rejected a pointer that was not the specified pointer");
			}
		}
	};

	TEST_CLASS(snct_LessThan_int_10)
	{
	public:
		
		using LessThanTen = snct::Constrained<int, snct::LessThan<10>>;
		TEST_METHOD(can_not_be_constructed_with_int_10)
		{
			try
			{
				LessThanTen{ 10 };
				Assert::Fail(L"Integer value 10 was not rejected");
			}
			catch(snct::Constraint_Exception const &){ }
		}

		TEST_METHOD(can_not_be_constructed_with_int_11)
		{
			try
			{
				LessThanTen{ 11 };
				Assert::Fail(L"Integer value 10 was not rejected");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_not_be_constructed_with_int_max)
		{

			try
			{
				LessThanTen{ std::numeric_limits<int>::max()};
				Assert::Fail(L"Integer value wildly above 10 was not rejected");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_be_constructed_with_int_9)
		{
			bool did_not_throw = false;
			try
			{
				LessThanTen{ 9 };
				did_not_throw = true;
			}
			catch (snct::Constraint_Exception const&) {}
			
			Assert::IsTrue(did_not_throw, L"LessThanTen threw on 9 despite 9 being less than ten");
		}

		TEST_METHOD(can_be_constructed_with_int_min)
		{
			bool did_not_throw = false;
			try
			{
				LessThanTen{ std::numeric_limits<int>::min()};
				did_not_throw = true;
			}
			catch (snct::Constraint_Exception const&) {}

			Assert::IsTrue(did_not_throw, L"LessThanTen threw on int_min despite int_min being less than ten");
		}
	};

	TEST_CLASS(snct_GreaterThan_int_10)
	{
	public:

		using GreaterThanTen = snct::Constrained<int, snct::GreaterThan<10>>;
		TEST_METHOD(can_not_be_constructed_with_int_10)
		{
			try
			{
				GreaterThanTen{ 10 };
				Assert::Fail(L"GreaterThanTen failed to throw on 10");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_not_be_constructed_with_int_min)
		{
			try
			{
				GreaterThanTen{ std::numeric_limits<int>::min()};
				Assert::Fail(L"GreaterThanTen failed to throw on int_min");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_not_be_constructed_with_int_9)
		{
			try
			{
				GreaterThanTen{ 9 };
				Assert::Fail(L"GreaterThanTen was constructed with value 9");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_be_constructed_with_11)
		{
			bool did_not_throw = false;
			try
			{
				GreaterThanTen{ 11 };
				did_not_throw = true;

			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"GreaterThanTen failed to construct with value 11");
		}

		TEST_METHOD(can_be_constructed_with_int_max)
		{
			bool did_not_throw = false;
			try
			{
				GreaterThanTen{ std::numeric_limits<int>::max()};
				did_not_throw = true;

			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"GreaterThanTen failed to construct with value int_max");
		}
	};

	TEST_CLASS(snct_Minimum_int_11)
	{
	public:

		using MinimumEleven = snct::Constrained<int, snct::Minimum<11>>;

		TEST_METHOD(can_not_be_constructed_with_int_10)
		{
			try
			{
				MinimumEleven{ 10 };
				Assert::Fail(L"MinimumEleven failed to throw on 10");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_not_be_constructed_with_int_min)
		{
			try
			{
				MinimumEleven{ std::numeric_limits<int>::min() };
				Assert::Fail(L"MinimumEleven failed to throw on int_min");
			}
			catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_be_constructed_with_int_12)
		{
			bool did_not_throw = false;
			try
			{
				MinimumEleven{ 12 };
				did_not_throw = true;

			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"MinimumEleven failed to construct with value 12");
		}

		TEST_METHOD(can_be_constructed_with_int_11)
		{
			bool did_not_throw = false;
			try
			{
				MinimumEleven{ 11 };
				did_not_throw = true;

			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"MinimumEleven failed to construct with value 11");
		}

		TEST_METHOD(can_be_constructed_with_int_max)
		{
			bool did_not_throw = false;
			try
			{
				MinimumEleven{ std::numeric_limits<int>::max() };
				did_not_throw = true;

			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"MinimumEleven failed to construct with value int_max");
		}
	};

	TEST_CLASS(snct_Maximum_int_20)
	{
	public:

		using MaxTwenty = snct::Constrained<int, snct::Maximum<20>>;

		TEST_METHOD(can_be_constructed_with_int_19)
		{
			bool did_not_throw = false;
			try
			{
				MaxTwenty{19};
				did_not_throw = true;
			}
			catch(snct::Constraint_Exception const &) {}
			Assert::IsTrue(did_not_throw, L"MaxTwenty failed to construct with value int_");
		}

		TEST_METHOD(can_be_constructed_with_int_20)
		{
			bool did_not_throw = false;
			try
			{
				MaxTwenty{20};
				did_not_throw = true;
			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"MaxTwenty failed to construct with value int_");
		}

		TEST_METHOD(can_not_be_constructed_with_int_21)
		{
			try
			{
				MaxTwenty{21};
				Assert::Fail(L"MaxTwenty failed to reject int_");
			} catch (snct::Constraint_Exception const&) {}
		}

		TEST_METHOD(can_be_constructed_with_int_min)
		{
			bool did_not_throw = false;
			try
			{
				MaxTwenty{20};
				did_not_throw = true;
			}
			catch (snct::Constraint_Exception const&) {}
			Assert::IsTrue(did_not_throw, L"MaxTwenty failed to construct with value int_");
		}

		TEST_METHOD(can_not_be_constructed_with_int_max)
		{
			try
			{
				MaxTwenty{std::numeric_limits<int>::max()};
				Assert::Fail(L"MaxTwenty failed to reject int_");
			}
			catch (snct::Constraint_Exception const&) {}
		}
	};


}
