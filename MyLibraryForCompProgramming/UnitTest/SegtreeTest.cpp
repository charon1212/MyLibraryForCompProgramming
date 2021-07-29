#include "pch.h"
#include "CppUnitTest.h"
#include "vector"
#include "../MyLibraryForCompProgramming/Segtree.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SegtreeTest
{
    int sum(int a, int b) { return a + b; }
    int e_sum() { return 0; }

    TEST_CLASS(SegtreeTest)
    {
    public:

        TEST_METHOD(SegtreeTestMethod_SumSample1)
        {
            auto init = std::vector<int>(10);
            for (int i = 0; i < 10; i++) init[i] = i;

            auto st = Segtree<int, e_sum, sum >(init);

            assert_st_query(st, init);

            init[3] = 100;
            st.update(3, 100);

            assert_st_query(st, init);

        }

        template<typename T, T(*e)(), T(*op)(T, T)>
        void assert_st_query(Segtree<T, e, op> st, std::vector<T> arr) {

            int n = arr.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j <= n; j++) { // 全区間を試す。
                    T expected = e();
                    for (int k = i; k < j; k++) expected = op(expected, arr[k]); // 期待値は、愚直に計算する。
                    Assert::AreEqual(expected, st.query(i, j));
                }
            }

        }
    };
}
