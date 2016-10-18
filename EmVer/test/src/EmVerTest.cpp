#include <iostream>
#include <memory>
#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "EmVer.hpp"
#include "mocks/MockTestSuite.hpp"
#include "mocks/MockEmVerWriter.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::NiceMock;

class EmVerTest : public ::testing::Test
{
protected:
    MockEmVerWriter writer_;

    virtual void SetUp()
    {
        writer_ = MockEmVerWriter();
    }

    virtual void TearDown()
    {
    }
};

TEST_F(EmVerTest, mixedTest)
{
    std::shared_ptr<NiceMock<MockTestSuite>> badSuite(new NiceMock<MockTestSuite>);
    EXPECT_CALL(*badSuite, totalTestCases())
    .WillRepeatedly(Return(2));
    EXPECT_CALL(*badSuite, name())
    .WillRepeatedly(Return("Bad Test Suite"));
    EXPECT_CALL(*badSuite, testCaseName(0))
    .WillRepeatedly(Return("Test Case 1"));
    EXPECT_CALL(*badSuite, runTestCase(0))
    .WillRepeatedly(Return(""));
    EXPECT_CALL(*badSuite, testCaseName(1))
    .WillRepeatedly(Return("Test Case 2"));
    EXPECT_CALL(*badSuite, runTestCase(1))
    .WillRepeatedly(Return("Failure Message"));
    std::shared_ptr<NiceMock<MockTestSuite>> goodSuite(new NiceMock<MockTestSuite>);
    EXPECT_CALL(*goodSuite, totalTestCases())
    .WillRepeatedly(Return(2));
    EXPECT_CALL(*goodSuite, name())
    .WillRepeatedly(Return("Good Test Suite"));
    EXPECT_CALL(*goodSuite, testCaseName(0))
    .WillRepeatedly(Return("Test Case 3"));
    EXPECT_CALL(*goodSuite, runTestCase(0))
    .WillRepeatedly(Return(""));
    EXPECT_CALL(*goodSuite, testCaseName(1))
    .WillRepeatedly(Return("Test Case 4"));
    EXPECT_CALL(*goodSuite, runTestCase(1))
    .WillRepeatedly(Return(""));
    std::vector<std::shared_ptr<I_TestSuite>> tests {badSuite, goodSuite};
    EmVer e(tests, writer_);
    e.start();
    std::string expected =
        "|===| EMVER START |===|\n"
        "Running Test Suite : Bad Test Suite\n"
        "> Running Test Case: Test Case 1 [PASS]\n"
        "> Running Test Case: Test Case 2 [FAIL]\n"
        "    Failure Message\n"
        "Running Test Suite : Good Test Suite\n"
        "> Running Test Case: Test Case 3 [PASS]\n"
        "> Running Test Case: Test Case 4 [PASS]\n"
        "\n"
        "|===| SUMMARY |===|\n"
        "[FAIL] Bad Test Suite 1/2\n"
        "[PASS] Good Test Suite 2/2\n"
        "\n"
        "1/2 Test Suites Passed\n";
    EXPECT_EQ(writer_.output(), expected);
}

TEST_F(EmVerTest, multiLineFailureMessage)
{
    std::shared_ptr<NiceMock<MockTestSuite>> badSuite(new NiceMock<MockTestSuite>);
    EXPECT_CALL(*badSuite, totalTestCases())
    .WillRepeatedly(Return(1));
    EXPECT_CALL(*badSuite, name())
    .WillRepeatedly(Return("Bad Test Suite"));
    EXPECT_CALL(*badSuite, testCaseName(0))
    .WillRepeatedly(Return("Test Case 1"));
    EXPECT_CALL(*badSuite, runTestCase(0))
    .WillRepeatedly(Return("Multi Line\nFailure"));
    std::vector<std::shared_ptr<I_TestSuite>> tests {badSuite};
    EmVer e(tests, writer_);
    e.start();
    std::string expected =
        "|===| EMVER START |===|\n"
        "Running Test Suite : Bad Test Suite\n"
        "> Running Test Case: Test Case 1 [FAIL]\n"
        "    Multi Line\n"
        "    Failure\n"
        "\n"
        "|===| SUMMARY |===|\n"
        "[FAIL] Bad Test Suite 0/1\n"
        "\n"
        "0/1 Test Suites Passed\n";
    EXPECT_EQ(writer_.output(), expected);
}
