#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "TestSuite.hpp"
#include "mocks/MockTestCase.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::DefaultValue;
using ::testing::NiceMock;

class TestSuiteTest : public ::testing::Test
{
protected:
    NiceMock<MockTestCase> firstMockTestCase_;

    virtual void SetUp()
    {
        ON_CALL(firstMockTestCase_, name())
            .WillByDefault(Return("FirstTestCase"));
    }

    virtual void TearDown()
    {

    }
};

TEST_F(TestSuiteTest, nameTest)
{
    std::string expected =  "testSuite";
    auto testSuite = TestSuite({}, expected);
    EXPECT_EQ(testSuite.name(), expected);
}


TEST_F(TestSuiteTest, failString)
{
    auto testSuite = TestSuite({&firstMockTestCase_}, "_");
    std::string expected = "FAILURE\nPASSED";
    EXPECT_CALL(firstMockTestCase_, run())
        .WillOnce(Return(expected));
    std::string actual = testSuite.runTestCase(0);
    EXPECT_EQ(expected, actual);
}


TEST_F(TestSuiteTest, manyTests)
{
    EXPECT_CALL(firstMockTestCase_, run())
        .WillOnce(Return(" "));

    NiceMock<MockTestCase> secondMockTestCase;
    EXPECT_CALL(secondMockTestCase, run())
        .WillOnce(Return("FAILURE"));
    ON_CALL(secondMockTestCase, name())
        .WillByDefault(Return("SecondTestCase"));

    NiceMock<MockTestCase> thirdMockTestCase;
    EXPECT_CALL(thirdMockTestCase, run())
        .WillOnce(Return(" "));
    ON_CALL(thirdMockTestCase, name())
        .WillByDefault(Return("ThirdTestCase"));

    auto testSuite = TestSuite({&firstMockTestCase_, &secondMockTestCase, &thirdMockTestCase}, "_");
    for(int i = 0; i < testSuite.totalTestCases(); i++)
    {
        testSuite.runTestCase(i);
    }
}

TEST_F(TestSuiteTest, outOfBoundName)
{
    auto testSuite = TestSuite({&firstMockTestCase_}, "_");

    auto expected = "testCaseName index out of range : 1\n1 existing test cases";
    auto actual = testSuite.testCaseName(1);
    EXPECT_EQ(expected, actual);
}

TEST_F(TestSuiteTest, outOfBoundRun)
{
    auto testSuite = TestSuite({&firstMockTestCase_}, "_");

    auto expected = "runTest index out of range : 1\n1 existing test cases";
    auto actual = testSuite.runTestCase(1);
    EXPECT_EQ(expected, actual);
}