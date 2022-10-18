#include "CppUnitTest.h"
#include "snct_constrained.hpp"
#include "snct_constraints.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace constraint_relation_between
{
    TEST_CLASS(GreaterThan_and_Not)
    {
    public:
        
        TEST_METHOD(is_narrower_when_GT_is_greater_than_Not)
        {
            static_assert(snct::constraint_relation<snct::GreaterThan<1>, snct::Not<0>>::narrower == true);
            static_assert(snct::constraint_relation<snct::GreaterThan<1>, snct::Not<0>>::wider == false);
            static_assert(snct::constraint_relation<snct::GreaterThan<1>, snct::Not<0>>::equivalent == false);
        }

        TEST_METHOD(is_narrower_when_GT_is_equal_to_Not)
        {
            static_assert(snct::constraint_relation<snct::GreaterThan<0>, snct::Not<0>>::narrower == true);
            static_assert(snct::constraint_relation<snct::GreaterThan<0>, snct::Not<0>>::wider == false);
            static_assert(snct::constraint_relation<snct::GreaterThan<0>, snct::Not<0>>::equivalent == false);
        }

        TEST_METHOD(is_wider_when_GT_is_smaller_than_to_Not)
        {
            static_assert(snct::constraint_relation<snct::GreaterThan<-1>, snct::Not<0>>::narrower == false);
            static_assert(snct::constraint_relation<snct::GreaterThan<-1>, snct::Not<0>>::wider == true);
            static_assert(snct::constraint_relation<snct::GreaterThan<-1>, snct::Not<0>>::equivalent == false);
        }
    };
}
