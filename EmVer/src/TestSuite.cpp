#include <string>
#include <sstream>

#include "TestSuite.hpp"


TestSuite::TestSuite(std::vector<TestCase*> testCases, std::string name)
    : testCases_(testCases)
    , name_(name)
{}

int TestSuite::totalTestCases() const
{
    return testCases_.size();
}

std::string TestSuite::name() const
{
    return name_;
}

std::string TestSuite::testCaseName(unsigned int i) const
{
    if (i >= testCases_.size())
    {
        std::ostringstream outOfRangeStream;
        outOfRangeStream << "testCaseName index out of range : " << i << "\n"
                         << testCases_.size() << " existing test cases";
        return outOfRangeStream.str();
    }
    else
    {
        return testCases_[i]->name();
    }
}

std::string TestSuite::runTestCase(unsigned int i) const
{
    if (i >= testCases_.size())
    {
        std::ostringstream outOfRangeStream;
        outOfRangeStream << "runTest index out of range : " << i << "\n"
                         << testCases_.size() << " existing test cases";
        return outOfRangeStream.str();
    }
    else
    {
        return testCases_[i]->run();
    }
}