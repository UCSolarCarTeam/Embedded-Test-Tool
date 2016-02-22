#include "TestSuite.hpp"

std::string TestSuite::runTests()
{
    std::string retString;

    for (unsigned int i = 0; i < testCases.size(); i++)
    {
        retString.append(testCases[i]->getTestName() + " :");
        testCases[i]->run() == 0 ? retString.append("PASSED\n") : retString.append("FAILED\n");
    }

    return retString;
}
