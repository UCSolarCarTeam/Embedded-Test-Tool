#include <memory>

#include "EmVer.hpp"
#include "EmVerWriter.hpp"
#include "TestSuite.hpp"

#include "ExampleTestA.hpp"
#include "ExampleTestB.hpp"

int main()
{
    ExampleTestA A;
    ExampleTestB B;
    std::shared_ptr<TestSuite> exampleSuite(new TestSuite({&A, &B}, "Example"));
    std::vector<std::shared_ptr<I_TestSuite>> tests {exampleSuite};
    EmVerWriter writer;
    EmVer e(tests, writer);
    e.start();
}
