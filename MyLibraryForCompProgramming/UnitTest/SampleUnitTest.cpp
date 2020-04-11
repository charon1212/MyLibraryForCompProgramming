#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/MyLibraryForCompProgramming.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::literals::string_literals; //std::stringのリテラル用

// サンプルテスト
// テスト周りのAPIリファレンス：https://docs.microsoft.com/ja-jp/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019
namespace SampleUnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {

            auto c1 = MySample::SampleClass(5);
            Assert::AreEqual(5, c1.getNum(), L"numberが5であることを確認。");
            c1.increment();
            Assert::AreEqual(6, c1.getNum(), L"incrementでnumberが増えることを確認。");
            Assert::AreEqual(""s, c1.getMessage(), L"messageの初期化を確認。");

            auto c2 = MySample::SampleClass("testtest"s);
            Assert::AreEqual("testtest"s, c2.getMessage());

        }
    };
}
