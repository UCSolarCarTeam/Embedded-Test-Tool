#include "EmVer.hpp"
#include "TestSuite.hpp"

#include "ExampleTestA.hpp"
#include "ExampleTestB.hpp"

int main() 
{
	TestSuite exampleSuite;
	ExampleTestA A;
	ExampleTestB B;
	exampleSuite.addTestCase(&A);
	exampleSuite.addTestCase(&B);
	
	std::vector<TestSuite> tests {exampleSuite};
	EmVer e(tests);
	e.start();
}