#include "pch.h"
#include "CppUnitTest.h"
#include"..\claslab10.1\lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {

    public:

        TEST_METHOD(TestChange)
        {
             
            const char* input = "no one knows who is who";

             
            char* result = Change(input);

           
            Assert::AreEqual("** one k**ws who is who", result);  

            
        }
    };
}