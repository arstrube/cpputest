#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/OrderedTest.h"

TEST_GROUP(AllTestsCount1)
{
};
TEST_ORDERED(AllTestsCount1, CountIsCorrect, 0xFFFFu)
{
    unsigned expected_number_of_tests = 132;
#if CPPUTEST_USE_STD_CPP_LIB
#else
    expected_number_of_tests--; // TEST(MemoryLeakWarningGlobalDetectorTest, turnOffNewOverloadsNoThrowCausesNoAdditionalLeaks)
    expected_number_of_tests--; // TEST(BasicBehavior, bothMallocAndFreeAreOverloaded)
#endif
#ifndef CPPUTEST_USE_MALLOC_MACROS
    expected_number_of_tests--; // TEST(MemoryLeakOverridesToBeUsedInProductionCode, MallocOverrideIsUsed)
#endif
    LONGS_EQUAL(expected_number_of_tests, TestRegistry::getCurrentRegistry()->countTests());
}
