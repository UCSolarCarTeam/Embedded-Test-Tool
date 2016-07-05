#include "mbed.h"

#include "EmVer.hpp"
#include "I_EmVerWriter.hpp"

EmVer::EmVer(const std::vector<TestSuite>& testSuites, I_EmVerWriter& writer)
: testSuites_(testSuites)
, writer_(writer)
{}

void EmVer::start()
{
    writer_.println("Beginning Tests...");
    for(auto const& testSuite : testSuites_)
    {
        writer_.println("Running TestSuite...");
        for(int i = 0; i < testSuite.totalTestCases(); i++)
        {
            auto testCaseName = "Running test : " + testSuite.testCaseName(i) + "\n";
            writer_.println(testCaseName);

            auto testResults = testSuite.runTestCase(i);
            writer_.println(testResults);
        }
    }
}