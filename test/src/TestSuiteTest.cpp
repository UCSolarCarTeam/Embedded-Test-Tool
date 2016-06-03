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
    NiceMock<MockTestCase> firstMockTestCase;
    TestSuite testSuite;

    virtual void SetUp()
    {
        ON_CALL(firstMockTestCase, getTestName())
            .WillByDefault(Return("FirstTestCase"));

        testSuite.addTestCase(&firstMockTestCase);
    }

    virtual void TearDown()
    {

    }
};

TEST_F(TestSuiteTest, passString)
{
    EXPECT_CALL(firstMockTestCase, run())
        .WillOnce(Return(" "));
    std::vector<std::string> resultStrings = testSuite.runTests();


    std::vector<std::string> expectedStrings;
    expectedStrings.emplace_back("FirstTestCase: PASSED");

    for(auto i = 0; i < expectedStrings.size(); i++)
    {
        EXPECT_EQ(expectedStrings[i], resultStrings[i]);
    }
}

TEST_F(TestSuiteTest, failString)
{
    EXPECT_CALL(firstMockTestCase, run())
        .WillOnce(Return("FAILURE"));
    std::vector<std::string> resultStrings = testSuite.runTests();

    std::vector<std::string> expectedStrings;
    expectedStrings.emplace_back("FirstTestCase: FAILED: FAILURE");

    for(auto i = 0; i < expectedStrings.size(); i++)
    {
        EXPECT_EQ(expectedStrings[i], resultStrings[i]);
    }
}


TEST_F(TestSuiteTest, mixedResultString)
{
    EXPECT_CALL(firstMockTestCase, run())
        .WillOnce(Return(" "));

    NiceMock<MockTestCase> secondMockTestCase;
    EXPECT_CALL(secondMockTestCase, run())
        .WillOnce(Return("FAILURE"));
    ON_CALL(secondMockTestCase, getTestName())
        .WillByDefault(Return("SecondTestCase"));
    testSuite.addTestCase(&secondMockTestCase);

    NiceMock<MockTestCase> thirdMockTestCase;
    EXPECT_CALL(thirdMockTestCase, run())
        .WillOnce(Return(" "));
    ON_CALL(thirdMockTestCase, getTestName())
        .WillByDefault(Return("ThirdTestCase"));
    testSuite.addTestCase(&thirdMockTestCase);

    std::vector<std::string> expectedStrings;
    expectedStrings.emplace_back("FirstTestCase: PASSED");
    expectedStrings.emplace_back("SecondTestCase: FAILED: FAILURE");
    expectedStrings.emplace_back("ThirdTestCase: PASSED");

    std::vector<std::string> resultStrings = testSuite.runTests();

    for(auto i = 0; i < expectedStrings.size(); i++)
    {
        EXPECT_EQ(expectedStrings[i], resultStrings[i]);
    }
}
