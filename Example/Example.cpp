#include "EmVer.hpp"
#include "TestSuite.hpp"

#include "ExampleTestA.hpp"
#include "ExampleTestB.hpp"

int main()
{
	ExampleTestA A;
	ExampleTestB B;
	TestSuite exampleSuite({&A, &B}, "Example");

	std::vector<TestSuite> tests {exampleSuite};
	EmVer e(tests);
	e.start();
}