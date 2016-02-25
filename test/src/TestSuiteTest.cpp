#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TestSuite.hpp"
#include "mocks/MockTestCase.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::DefaultValue;
using ::testing::NiceMock;

class TestSuiteTest : public ::testing::Test {
protected:
    NiceMock<MockTestCase> firstMockTestCase_;
    TestSuite testSuite_;

    virtual void SetUp() {
        ON_CALL(firstMockTestCase_, getTestName())
            .WillByDefault(Return("FirstTestCase"));

        testSuite_.addTestCase(&firstMockTestCase_);
    }

    virtual void TearDown() {

    }
};

TEST_F(TestSuiteTest, passString) {
    EXPECT_CALL(firstMockTestCase_, run())
        .WillOnce(Return(PASSED));
    std::string resultString = testSuite_.runTests();

    std::string expectedString = "FirstTestCase : PASSED\n";
    EXPECT_EQ(expectedString, resultString);
}

TEST_F(TestSuiteTest, failString) {
    EXPECT_CALL(firstMockTestCase_, run())
        .WillOnce(Return(FAILED));
    std::string resultString = testSuite_.runTests();

    std::string expectedString = "FirstTestCase : FAILED\n";
    EXPECT_EQ(expectedString, resultString);
}


TEST_F(TestSuiteTest, mixedResultString) {
    EXPECT_CALL(firstMockTestCase_, run())
        .WillOnce(Return(PASSED));

    NiceMock<MockTestCase> secondMockTestCase;
    EXPECT_CALL(secondMockTestCase, run())
        .WillOnce(Return(FAILED));
    ON_CALL(secondMockTestCase, getTestName())
        .WillByDefault(Return("SecondTestCase"));
    testSuite_.addTestCase(&secondMockTestCase);

    NiceMock<MockTestCase> thirdMockTestCase;
    EXPECT_CALL(thirdMockTestCase, run())
        .WillOnce(Return(PASSED ));
    ON_CALL(thirdMockTestCase, getTestName())
        .WillByDefault(Return("ThirdTestCase"));
    testSuite_.addTestCase(&thirdMockTestCase);


    std::string expectedString = "FirstTestCase : PASSED\n"
                                 "SecondTestCase : FAILED\n"
                                 "ThirdTestCase : PASSED\n";

    std::string resultString = testSuite_.runTests();
    EXPECT_EQ(expectedString, resultString);
}
