#include "mbed.h"
#include "TestAssertions.hpp"
#include "TestSuite.hpp"
#include "DummyTestA.hpp"
#include "DummyTestB.hpp"

char command_buf[256];
TestSuite testAll;
DummyTestA A;
DummyTestB B;

int main(void)
{
    // Stub for main loop
    bool running = true;
    Serial pc(USBTX, USBRX); // tx, rx
    pc.baud(9600);

    char c;
    int idx = 0;

    testAll.addTestCase(&A);
    testAll.addTestCase(&B);

    while (running)
    {
        if (idx == 0)
        {
            pc.printf("Select a test case or enter ':q' to quit\r\n");
            for (auto i = testAll.getBegin(); i != testAll.getEnd(); i++)
            {
                pc.printf("%s\r\n",i->first.c_str());
            }
        }

        c = pc.getc();
        pc.putc(c);

        if (c == '\n' || c == '\r')
        {
            if (strcmp(command_buf, ":q") == 0)
            {
                running = false;
                pc.printf("Ending program, goodbye!\r\n");
            }
            else
            {
                std::vector<std::string> res = testAll.runTest(std::string(command_buf));

                // Start of result printing
                pc.printf("\r\n");

                for (auto it = res.begin(); it != res.end(); it++)
                {
                    pc.printf("%s\r\n", it->c_str());
                }

                // End of result printing
                pc.printf("\r\n");

                memset(command_buf, 0, sizeof(command_buf));
                idx = 0;
            }
        }
        else
        {
            command_buf[idx] = c;
            idx++;
        }
    }
    return 0;
}
