#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include "test_doubles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace individual_constraints
{
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
            catch (snct::Constraint_Exception const&) {}
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
                LessThanTen{ std::numeric_limits<int>::max() };
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
                LessThanTen{ std::numeric_limits<int>::min() };
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
                GreaterThanTen{ std::numeric_limits<int>::min() };
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
                GreaterThanTen{ std::numeric_limits<int>::max() };
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
                MaxTwenty{ 19 };
                did_not_throw = true;
            }
            catch (snct::Constraint_Exception const&) {}
            Assert::IsTrue(did_not_throw, L"MaxTwenty failed to construct with value int_");
        }

        TEST_METHOD(can_be_constructed_with_int_20)
        {
            bool did_not_throw = false;
            try
            {
                MaxTwenty{ 20 };
                did_not_throw = true;
            }
            catch (snct::Constraint_Exception const&) {}
            Assert::IsTrue(did_not_throw, L"MaxTwenty failed to construct with value int_");
        }

        TEST_METHOD(can_not_be_constructed_with_int_21)
        {
            try
            {
                MaxTwenty{ 21 };
                Assert::Fail(L"MaxTwenty failed to reject int_");
            }
            catch (snct::Constraint_Exception const&) {}
        }

        TEST_METHOD(can_be_constructed_with_int_min)
        {
            bool did_not_throw = false;
            try
            {
                MaxTwenty{ 20 };
                did_not_throw = true;
            }
            catch (snct::Constraint_Exception const&) {}
            Assert::IsTrue(did_not_throw, L"MaxTwenty failed to construct with value int_");
        }

        TEST_METHOD(can_not_be_constructed_with_int_max)
        {
            try
            {
                MaxTwenty{ std::numeric_limits<int>::max() };
                Assert::Fail(L"MaxTwenty failed to reject int_");
            }
            catch (snct::Constraint_Exception const&) {}
        }
    };


}