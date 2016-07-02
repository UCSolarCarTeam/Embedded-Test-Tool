#include "EmVer.hpp"
#include "TestSuite.hpp"

#include "DummyTestA.hpp"
#include "DummyTestB.hpp"

int main() 
{
	TestSuite dummySuite;
	DummyTestA A;
	DummyTestB B;
	dummySuite.addTestCase(&A);
	dummySuite.addTestCase(&B);
	
	std::vector<TestSuite> tests {dummySuite};
	EmVer e(tests);
	e.start();
}