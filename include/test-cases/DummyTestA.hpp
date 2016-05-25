#include "TestCase.hpp"

class DummyTestA : public TestCase
{
public:
    std::string run()
    {
        return "This dummy test failed!";
    }

    std::string getTestName() const
    {
        return "DummyTestA";
    }

};
