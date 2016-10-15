#include <memory>
#include <sstream>
#include <string>

#include "EmVer.hpp"
#include "I_EmVerWriter.hpp"

EmVer::EmVer(std::vector<std::shared_ptr<I_TestSuite>>& testSuites, I_EmVerWriter& writer)
    : testSuites_(testSuites)
    , writer_(writer)
{}

void EmVer::start()
{
    std::ostringstream summary;
    int passedTestSuites = 0;
    writer_.println("|===| EMVER START |===|");

    for (auto const& testSuite : testSuites_)
    {
        writer_.println("Running Test Suite : " + testSuite->name());
        int passedTestCases = 0;
        int totalTestCases = testSuite->totalTestCases();

        for (int i = 0; i < totalTestCases; i++)
        {
            auto testCaseName = "> Running Test Case: " + testSuite->testCaseName(i);
            writer_.print(testCaseName);
            auto testResults = testSuite->runTestCase(i);

            if (testResults.empty())
            {
                writer_.println(" [PASS]");
                passedTestCases++;
            }
            else
            {
                writer_.println(" [FAIL]");
                writer_.println(indentMessage(testResults));
            }
        }

        std::string testResult = "[FAIL]";

        if (passedTestCases == totalTestCases)
        {
            testResult = "[PASS]";
            passedTestSuites++;
        }

        summary << testResult << " " << testSuite->name() << " " << passedTestCases << "/" << totalTestCases << std::endl;
    }

    writer_.println("\n|===| SUMMARY |===|");
    writer_.println(summary.str());
    std::ostringstream finalResult;
    finalResult << passedTestSuites << "/" << testSuites_.size() << " Test Suites Passed";
    writer_.println(finalResult.str());
}

std::string EmVer::indentMessage(const std::string& s)
{
    if (!s.size())
    {
        return "";
    }

    std::stringstream ss;
    ss << "    ";

    for (auto c : s)
    {
        ss << c;

        if (c == '\n')
        {
            ss << "    ";
        }
    }

    return ss.str();
}
