#include "TestCase.hpp"

class DummyTestB : public TestCase
{
public:
    std::string run()
    {
        return " ";
    }

    std::string getTestName() const
    {
        return "DummyTestB";
    }

};
