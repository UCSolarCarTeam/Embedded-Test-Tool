#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include "TestResult.hpp"

class TestCase
{
public:
    virtual TEST_RESULT run() = 0;
protected:
    // virtual void setup() = 0;
    // virtual void tearDown() = 0;
};

#endif // TEST_HPP

