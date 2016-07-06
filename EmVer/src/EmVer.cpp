#include "mbed.h"

#include "EmVer.hpp"

EmVer::EmVer(std::vector<TestSuite> testSuites)
: testSuites_(testSuites)
{}

void EmVer::start()
{
    // // Stub for main loop
    // bool running = true;
    // Serial pc(USBTX, USBRX); // tx, rx
    // pc.baud(9600);

    // char inputChar;
    // int commandBufIdx = 0;

    // while (running)
    // {
    //     if (commandBufIdx == 0)
    //     {
    //         pc.printf("Select a test case or enter ':q' to quit\r\n");
    //         for (auto i = testSuites_[0].getBegin(); i != testSuites_[0].getEnd(); i++)
    //         {
    //             pc.printf("%s\r\n",i->first.c_str());
    //         }
    //     }
    //     else if(commandBufIdx == 256)
    //     {
    //         commandBufIdx = 0;
    //     }

    //     inputChar = pc.getc();
    //     pc.putc(inputChar);

    //     if (inputChar == '\n' || inputChar == '\r')
    //     {
    //         if (strcmp(commandBuf_, ":q") == 0)
    //         {
    //             running = false;
    //             pc.printf("Ending program, goodbye!\r\n");
    //         }
    //         else
    //         {
    //             std::vector<std::string> res = testSuites_[0].runTest(std::string(commandBuf_));

    //             // Start of result printing
    //             pc.printf("\r\n");

    //             for (auto it = res.begin(); it != res.end(); it++)
    //             {
    //                 pc.printf("%s\r\n", it->c_str());
    //             }

    //             // End of result printing
    //             pc.printf("\r\n");

    //             memset(commandBuf_, 0, sizeof(commandBuf_));
    //             commandBufIdx = 0;
    //         }
    //     }
    //     else
    //     {
    //         commandBuf_[commandBufIdx] = inputChar;
    //         commandBufIdx++;
    //     }
    // }
    LocalFileSystem local("local");
    FILE *fp = fopen("/local/TestResult.txt", "w");
    fprintf(fp, "Beginning Tests...");

    for(auto const& testSuite : testSuites_)
    {
        fprintf(fp, "Running TestSuite...");
        for(int i = 0; i < testSuite.totalTestCases(); i++)
        {
            fprintf(fp, ("Running test : " + testSuite.testCaseName(i) + "\n").c_str());
            fprintf(fp, testSuite.runTestCase(i).c_str());
        }
    }
    fclose(fp);
}