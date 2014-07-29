#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/OrderedTest.h"

TEST_GROUP(AllTestsCount2)
{
};
TEST_ORDERED(AllTestsCount2, CountIsCorrect, 0xFFFFu)
{
    unsigned expected_number_of_tests = 237;
#if CPPUTEST_USE_STD_CPP_LIB
#else
    expected_number_of_tests--; // TEST(UtestShell, DestructorIsCalledForLocalObjectsWhenTheTestFails)
    expected_number_of_tests--; // TEST(UnitTestMacros, FailureWithCHECK_THROWS_whenDoesntThrow)
    expected_number_of_tests--; // TEST(UnitTestMacros, SuccessWithCHECK_THROWS)
    expected_number_of_tests--; // TEST(UnitTestMacros, FailureWithCHECK_THROWS_whenWrongThrow)
    expected_number_of_tests--; // TEST(UnitTestMacros, MultipleCHECK_THROWS_inOneScope)
#endif
    LONGS_EQUAL(expected_number_of_tests, TestRegistry::getCurrentRegistry()->countTests());
}
