#include "mbed.h"
#include "TestAssertions.hpp"
#include "TestSuite.hpp"
#include "DummyTestA.hpp"
#include "DummyTestB.hpp"

char commandBuf[256];
TestSuite testAll;
DummyTestA A;
DummyTestB B;

int main(void)
{
    // Stub for main loop
    bool running = true;
    Serial pc(USBTX, USBRX); // tx, rx
    pc.baud(9600);

    char inputChar;
    int commandBufIdx = 0;

    testAll.addTestCase(&A);
    testAll.addTestCase(&B);

    while (running)
    {
        if (commandBufIdx == 0)
        {
            pc.printf("Select a test case or enter ':q' to quit\r\n");
            for (auto i = testAll.getBegin(); i != testAll.getEnd(); i++)
            {
                pc.printf("%s\r\n",i->first.c_str());
            }
        }
        else if(commandBufIdx == 256)
        {
            commandBufIdx = 0;
        }

        inputChar = pc.getc();
        pc.putc(inputChar);

        if (inputChar == '\n' || inputChar == '\r')
        {
            if (strcmp(commandBuf, ":q") == 0)
            {
                running = false;
                pc.printf("Ending program, goodbye!\r\n");
            }
            else
            {
                std::vector<std::string> res = testAll.runTest(std::string(commandBuf));

                // Start of result printing
                pc.printf("\r\n");

                for (auto it = res.begin(); it != res.end(); it++)
                {
                    pc.printf("%s\r\n", it->c_str());
                }

                // End of result printing
                pc.printf("\r\n");

                memset(commandBuf, 0, sizeof(commandBuf));
                commandBufIdx = 0;
            }
        }
        else
        {
            commandBuf[commandBufIdx] = inputChar;
            commandBufIdx++;
        }
    }
    return 0;
}
