#include "TestSuite.hpp"

std::vector<std::string> TestSuite::runTests() const
{
    std::vector<std::string> retVector;

    retVector.emplace_back("----TEST RESULTS----");

    for (auto i = testCases.cbegin(); i != testCases.cend(); i++)
    {
        std::string resultString = i->second->run();

        if (resultString.compare(" ") == 0)
        {
            retVector.emplace_back(i->first + ": PASSED");
        }
        else
        {
            retVector.emplace_back(i->first + ": FAILED");
            retVector.emplace_back(resultString);
        }
    }

    return retVector;
}

std::vector<std::string> TestSuite::runTest(std::string name)
{
    std::vector<std::string> retVector;

    if (name.compare("all") == 0 )
    {
        return runTests();
    }
    else
    {
        auto found = testCases.find(name);

        if (found != testCases.end())
        {
            retVector.emplace_back(name + ": ");
            retVector.emplace_back(testCases[name]->run());
        }
        else
        {
            retVector.emplace_back("Error: no such test named: " + name);
        }
        return retVector;
    }
}

void TestSuite::addTestCase(TestCase *testCase)
{
    testCases.insert(std::pair<std::string, TestCase*>(testCase->getTestName(), testCase));
}

std::map<std::string, TestCase*>::const_iterator TestSuite::getBegin() const
{
    return testCases.cbegin();
}

std::map<std::string, TestCase*>::const_iterator TestSuite::getEnd() const
{
    return testCases.cend();
}
