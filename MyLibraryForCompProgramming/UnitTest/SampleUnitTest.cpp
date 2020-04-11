#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/MyLibraryForCompProgramming.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::literals::string_literals; //std::string�̃��e�����p

// �T���v���e�X�g
// �e�X�g�����API���t�@�����X�Fhttps://docs.microsoft.com/ja-jp/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019
namespace SampleUnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {

            auto c1 = MySample::SampleClass(5);
            Assert::AreEqual(5, c1.getNum(), L"number��5�ł��邱�Ƃ��m�F�B");
            c1.increment();
            Assert::AreEqual(6, c1.getNum(), L"increment��number�������邱�Ƃ��m�F�B");
            Assert::AreEqual(""s, c1.getMessage(), L"message�̏��������m�F�B");

            auto c2 = MySample::SampleClass("testtest"s);
            Assert::AreEqual("testtest"s, c2.getMessage());

        }
    };
}
