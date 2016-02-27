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
        .WillOnce(Return(PASSED));
    std::string resultString = testSuite.runTests();

    std::string expectedString = "FirstTestCase : PASSED\n";
    EXPECT_EQ(expectedString, resultString);
}

TEST_F(TestSuiteTest, failString)
{
    EXPECT_CALL(firstMockTestCase, run())
        .WillOnce(Return(FAILED));
    std::string resultString = testSuite.runTests();

    std::string expectedString = "FirstTestCase : FAILED\n";
    EXPECT_EQ(expectedString, resultString);
}


TEST_F(TestSuiteTest, mixedResultString)
{
    EXPECT_CALL(firstMockTestCase, run())
        .WillOnce(Return(PASSED));

    NiceMock<MockTestCase> secondMockTestCase;
    EXPECT_CALL(secondMockTestCase, run())
        .WillOnce(Return(FAILED));
    ON_CALL(secondMockTestCase, getTestName())
        .WillByDefault(Return("SecondTestCase"));
    testSuite.addTestCase(&secondMockTestCase);

    NiceMock<MockTestCase> thirdMockTestCase;
    EXPECT_CALL(thirdMockTestCase, run())
        .WillOnce(Return(PASSED ));
    ON_CALL(thirdMockTestCase, getTestName())
        .WillByDefault(Return("ThirdTestCase"));
    testSuite.addTestCase(&thirdMockTestCase);


    std::string expectedString = "FirstTestCase : PASSED\n"
                                 "SecondTestCase : FAILED\n"
                                 "ThirdTestCase : PASSED\n";

    std::string resultString = testSuite.runTests();
    EXPECT_EQ(expectedString, resultString);
}
