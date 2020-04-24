#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/VectorUtil.cpp"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::literals::string_literals; //std::stringのリテラル用

// サンプルテスト
// テスト周りのAPIリファレンス：https://docs.microsoft.com/ja-jp/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019
namespace VectorUtilTest
{
    TEST_CLASS(VectorUtilTest)
    {
    public:

        TEST_METHOD(VectorUtilTestMethod_Construct2d)
        {
            std::vector<std::vector<int>> vec1 = construct_vector_2d(2, 5, 7);
            Assert::AreEqual((size_t)2, vec1.size());
            for (int i = 0; i < 2; i++) Assert::AreEqual((size_t)5, vec1[i].size());
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 5; j++) Assert::AreEqual(7, vec1[i][j]);
            }
        }
        TEST_METHOD(VectorUtilTestMethod_Construct3d)
        {
            std::vector<std::vector<std::vector<int>>> vec1 = construct_vector_3d(2, 5, 7, 13);
            Assert::AreEqual((size_t)2, vec1.size());
            for (int i = 0; i < 2; i++) {
                Assert::AreEqual((size_t)5, vec1[i].size());
                for (int j = 0; j < 5; j++) Assert::AreEqual((size_t)7, vec1[i][j].size());
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 7; k++) Assert::AreEqual(13, vec1[i][j][k]);
                }
            }
        }
        TEST_METHOD(VectorUtilTestMethod_Find)
        {
            std::vector<int> vec1 = std::vector<int>({ 1,3,5,7,9 });
            std::vector<int>::iterator it;
            it = find_binary_search(vec1.begin(), vec1.end(), 0);
            Assert::IsTrue(it == vec1.end());
            it = find_binary_search(vec1.begin(), vec1.end(), 1);
            Assert::IsTrue((*it) == 1);
            it = find_binary_search(vec1.begin(), vec1.end(), 2);
            Assert::IsTrue(it == vec1.end());
            it = find_binary_search(vec1.begin(), vec1.end(), 3);
            Assert::IsTrue((*it) == 3);
            it = find_binary_search(vec1.begin(), vec1.end(), 4);
            Assert::IsTrue(it == vec1.end());
            it = find_binary_search(vec1.begin(), vec1.end(), 5);
            Assert::IsTrue((*it) == 5);
            it = find_binary_search(vec1.begin(), vec1.end(), 6);
            Assert::IsTrue(it == vec1.end());
            it = find_binary_search(vec1.begin(), vec1.end(), 7);
            Assert::IsTrue((*it) == 7);
            it = find_binary_search(vec1.begin(), vec1.end(), 8);
            Assert::IsTrue(it == vec1.end());
            it = find_binary_search(vec1.begin(), vec1.end(), 9);
            Assert::IsTrue((*it) == 9);
            it = find_binary_search(vec1.begin(), vec1.end(), 10);
            Assert::IsTrue(it == vec1.end());
        }
    };
}
