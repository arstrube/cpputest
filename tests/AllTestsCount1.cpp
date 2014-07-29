#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/OrderedTest.h"

TEST_GROUP(AllTestsCount1)
{
};
TEST_ORDERED(AllTestsCount1, CountIsCorrect, 0xFFFFu)
{
    unsigned expected_number_of_tests = 376;
    LONGS_EQUAL(expected_number_of_tests, TestRegistry::getCurrentRegistry()->countTests());
}
