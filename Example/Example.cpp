#include "EmVer.hpp"
#include "EmVerWriter.hpp"
#include "TestSuite.hpp"

#include "ExampleTestA.hpp"
#include "ExampleTestB.hpp"

int main()
{
	ExampleTestA A;
	ExampleTestB B;
	TestSuite exampleSuite({&A, &B}, "Example");

	std::vector<TestSuite> tests {exampleSuite};
    EmVerWriter writer = EmVerWriter();
    EmVer e(tests, writer);
	e.start();
}