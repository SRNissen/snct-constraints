#include "CppUnitTest.h"
#include "snct_constraints.hpp"
#include <string_view>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace snct_constraints
{
    TEST_CLASS(will_reject)
    {
    public:

        TEST_METHOD(banned_values)
        {

            // ARRANGE
            std::string expected;
            std::string actual;
            
            bool failed_to_throw = false;
            bool entered_Constraint_Exception_block = false;
            bool entered_catch_all_block = false;

            // ACT
            try
            {
                using ban_zero = snct::Constrained<int, snct::Not<0>>;

                auto Zero = ban_zero{ 0 };

                failed_to_throw = true;
            }
            catch (snct::Constraint_Exception const& e)
            {
                entered_Constraint_Exception_block = true;
                expected = snct::Not<0>::error_message();
                actual = e.what();
            }
            catch (...)
            {
                entered_catch_all_block = true;
            }

            // ASSERT
            if(failed_to_throw)
                Assert::Fail(L"ban_zero failed to throw on zero assignment");
            
            if(entered_Constraint_Exception_block)
                Assert::AreEqual(expected, actual, L"ban_zero threw strange message on zero assignment");

            if (entered_catch_all_block)
                Assert::Fail(L"ban_zero threw wrong exception type on zero assignment");
        }
    };
}

