#include "CppUnitTest.h"
#include "snct_constexpr_math.hpp"
#include <array>
#include <utility>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace math_functions
{
	static constexpr double signalling_NaN /*	*/ = std::numeric_limits<double>::signaling_NaN();
	static constexpr double quiet_NaN /*		*/ = std::numeric_limits<double>::quiet_NaN();
	static constexpr double positive_infinity /**/ = std::numeric_limits<double>::infinity();
	static constexpr double negative_infinity /**/ = std::numeric_limits<double>::infinity() * -1.0;
	static constexpr double positive_lowest /*	*/ = std::numeric_limits<double>::lowest();
	static constexpr double negative_lowest /*	*/ = std::numeric_limits<double>::lowest() * -1.0;
	static constexpr double minimum /*			*/ = std::numeric_limits<double>::min();
	static constexpr double maximum /*			*/ = std::numeric_limits<double>::max();
	static constexpr double zero /*				*/ = 0.0;
	static constexpr double one /*				*/ = 1.0;

	TEST_CLASS(snct_constexpr_math_function)
	{
	public:

		TEST_METHOD(is_nan_returns_EXPECTED_on_INPUT)
		{

			using expected = bool;
			using input = double;
			auto pairs = std::array<std::pair<expected, input>, 10>
			{
				{
					{ true, signalling_NaN },
					{ true, quiet_NaN },
					{ false,positive_infinity },
					{ false,negative_infinity },
					{ false,positive_lowest },
					{ false,negative_lowest },
					{ false,minimum },
					{ false,maximum },
					{ false,zero },
					{ false,one }
				}
			};

			for (auto const & [expected, input] : pairs)
			{
				Assert::AreEqual(expected, snct::is_nan(input));
			}
		}

		TEST_METHOD(is_positive_infinite_returns_EXPECTED_on_INPUT)
		{

			using expected = bool;
			using input = double;
			auto pairs = std::array<std::pair<expected, input>, 10>
			{
				{
					{ false,signalling_NaN },
					{ false,quiet_NaN },
					{ true,positive_infinity },
					{ false,negative_infinity },
					{ false,positive_lowest },
					{ false,negative_lowest },
					{ false,minimum },
					{ false,maximum },
					{ false,zero },
					{ false,one }
				}
			};

			for (auto const& [expected, input] : pairs)
			{
				Assert::AreEqual(expected, snct::is_positive_infinite(input));
			}
		}

		TEST_METHOD(is_negative_infinite_returns_EXPECTED_on_INPUT)
		{

			using expected = bool;
			using input = double;
			auto pairs = std::array<std::pair<expected, input>, 10>
			{
				{
					{ false, signalling_NaN },
					{ false,quiet_NaN },
					{ false,positive_infinity },
					{ true,negative_infinity },
					{ false,positive_lowest },
					{ false,negative_lowest },
					{ false,minimum },
					{ false,maximum },
					{ false,zero },
					{ false,one }
				}
			};

			for (auto const& [expected, input] : pairs)
			{
				Assert::AreEqual(expected, snct::is_negative_infinite(input));
			}
		}

		TEST_METHOD(is_infinite_returns_EXPECTED_on_INPUT)
		{

			using expected = bool;
			using input = double;
			auto pairs = std::array<std::pair<expected, input>, 10>
			{
				{
					{ false, signalling_NaN },
					{ false,quiet_NaN },
					{ true,positive_infinity },
					{ true,negative_infinity },
					{ false,positive_lowest },
					{ false,negative_lowest },
					{ false,minimum },
					{ false,maximum },
					{ false,zero },
					{ false,one }
				}
			};

			for (auto const& [expected, input] : pairs)
			{
				Assert::AreEqual(expected, snct::is_infinite(input));
			}
		}

		TEST_METHOD(is_finite_returns_EXPECTED_on_INPUT)
		{

			using expected = bool;
			using input = double;
			auto pairs = std::array<std::pair<expected, input>, 10>
			{
				{
					{ false, signalling_NaN },
					{ false,quiet_NaN },
					{ false,positive_infinity },
					{ false,negative_infinity },
					{ true,positive_lowest },
					{ true,negative_lowest },
					{ true,minimum },
					{ true,maximum },
					{ true,zero },
					{ true,one }
				}
			};

			for (auto const& [expected, input] : pairs)
			{
				Assert::AreEqual(expected, snct::is_finite(input));
			}
		}

	};
}
