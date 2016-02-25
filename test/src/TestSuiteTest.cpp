#include <map>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TestSuite.hpp"
#include "mocks/MockTestCase.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::DefaultValue;

class TestSuiteTest : public ::testing::Test {
protected:
    MockTestCase* mockTestCase_;

    virtual void SetUp() {
        mockTestCase_ = new MockTestCase();
        ON_CALL(*mockTestCase_, getTestName())
            .WillByDefault(Return("FirstTestCase"));
    }

    virtual void TearDown() {
    }
};

TEST_F(TestSuiteTest, runsTestCase){
    EXPECT_CALL(*mockTestCase_, run())
        .WillOnce(Return(PASSED));
    
    TestSuite testSuite;
    testSuite.addTestCase(mockTestCase_); 
    testSuite.runTests();

    delete mockTestCase_;
}
