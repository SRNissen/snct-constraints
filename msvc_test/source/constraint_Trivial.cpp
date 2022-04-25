#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include "test_doubles.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace trivial::constraint
{
	namespace AlwaysSatisfied
	{
		TEST_CLASS(is_satisfied_by)
		{
			TEST_METHOD(arbitrary_integers)
			{
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(-10000));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(-100));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(-1));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(0));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(1));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(100));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(10000));
			}

			TEST_METHOD(arbitrary_chars)
			{
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 0 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 2 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 4 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 8 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 16 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 32 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 64 }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(char{ 127 }));
			}

			TEST_METHOD(arbitrary_strings)
			{
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(std::string{}));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(std::string{ "short" }));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(std::string{
					"this is a string that is too long to fit into short string optimization and therefore lives on the heap unless you don't have a heap in which case What Are You Doing? because that sounds really interesting"
					}));
				Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied("This isn't even a std::string"));
			}


			TEST_METHOD(arbitrary_doubles)
			{

				for (auto const & Double : Doubles) //all the doubles from numeric limits e.g. NaNs, infinites, plus some extras
				{
					Assert::IsTrue(snct::AlwaysSatisfied::is_satisfied(Double));
				}
			}
		};
	}

	namespace NeverSatisfied
	{
		TEST_CLASS(is_not_satisfied_by)
		{
			TEST_METHOD(arbitrary_integers)
			{
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(-10000));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(-100));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(-1));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(0));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(1));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(100));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(10000));
			}

			TEST_METHOD(arbitrary_chars)
			{
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 0 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 2 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 4 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 8 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 16 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 32 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 64 }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(char{ 127 }));
			}

			TEST_METHOD(arbitrary_strings)
			{
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(std::string{}));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(std::string{ "short" }));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied(std::string{
					"this is a string that is too long to fit into short string optimization and therefore lives on the heap unless you don't have a heap in which case What Are You Doing? because that sounds really interesting"
					}));
				Assert::IsFalse(snct::NeverSatisfied::is_satisfied("This isn't even a std::string"));
			}


			TEST_METHOD(arbitrary_doubles)
			{

				for (auto const& Double : Doubles) //all the doubles from numeric limits e.g. NaNs, infinites, plus some extras
				{
					Assert::IsFalse(snct::NeverSatisfied::is_satisfied(Double));
				}
			}
		};
	}

	namespace Satisfied_true
	{
		TEST_CLASS(is_satisfied_by)
		{
			TEST_METHOD(arbitrary_integers)
			{
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(-10000));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(-100));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(-1));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(0));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(1));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(100));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(10000));
			}

			TEST_METHOD(arbitrary_chars)
			{
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 0 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 2 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 4 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 8 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 16 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 32 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 64 }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(char{ 127 }));
			}

			TEST_METHOD(arbitrary_strings)
			{
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(std::string{}));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(std::string{ "short" }));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied(std::string{
					"this is a string that is too long to fit into short string optimization and therefore lives on the heap unless you don't have a heap in which case What Are You Doing? because that sounds really interesting"
					}));
				Assert::IsTrue(snct::Satisfied<true>::is_satisfied("This isn't even a std::string"));
			}


			TEST_METHOD(arbitrary_doubles)
			{

				for (auto const& Double : Doubles) //all the doubles from numeric limits e.g. NaNs, infinites, plus some extras
				{
					Assert::IsTrue(snct::Satisfied<true>::is_satisfied(Double));
				}
			}
		};
	}

	namespace Satisfied_false
	{
		TEST_CLASS(is_not_satisfied_by)
		{
			TEST_METHOD(arbitrary_integers)
			{
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(-10000));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(-100));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(-1));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(0));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(1));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(100));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(10000));
			}

			TEST_METHOD(arbitrary_chars)
			{
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 0 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 2 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 4 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 8 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 16 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 32 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 64 }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(char{ 127 }));
			}

			TEST_METHOD(arbitrary_strings)
			{
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(std::string{}));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(std::string{ "short" }));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied(std::string{
					"this is a string that is too long to fit into short string optimization and therefore lives on the heap unless you don't have a heap in which case What Are You Doing? because that sounds really interesting"
					}));
				Assert::IsFalse(snct::Satisfied<false>::is_satisfied("This isn't even a std::string"));
			}


			TEST_METHOD(arbitrary_doubles)
			{

				for (auto const& Double : Doubles) //all the doubles from numeric limits e.g. NaNs, infinites, plus some extras
				{
					Assert::IsFalse(snct::Satisfied<false>::is_satisfied(Double));
				}
			}
		};
	}
}