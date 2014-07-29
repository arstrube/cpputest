#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/OrderedTest.h"

TEST_GROUP(AllTestsCount2)
{
};
TEST_ORDERED(AllTestsCount2, CountIsCorrect, 0xFFFFu)
{
    unsigned expected_number_of_tests = 179;
    LONGS_EQUAL(expected_number_of_tests, TestRegistry::getCurrentRegistry()->countTests());
}
