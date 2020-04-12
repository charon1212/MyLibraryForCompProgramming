#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/ModInt.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ModIntTest
{
    TEST_CLASS(ModIntTest)
    {
    public:

        template<typename T> void ConstructorTest(T value, int expected) {
            ModInt<23> a = value;
            Assert::AreEqual((unsigned)expected, a.get());
            auto b = ModInt<23>(value);
            Assert::AreEqual((unsigned)expected, b.get());
        }
        TEST_METHOD(ModIntTestMethod_Constructor) {
            ConstructorTest((int)10, 10);
            ConstructorTest((int)30, 7);
            ConstructorTest((int)60, 14);
            ConstructorTest((int)-10, 13);
            ConstructorTest((int)22, 22);
            ConstructorTest((int)23, 0);
            ConstructorTest((int)24, 1);
            ConstructorTest((long long)10, 10);
            ConstructorTest((long long)30, 7);
            ConstructorTest((long long)60, 14);
            ConstructorTest((long long)-10, 13);
            ConstructorTest((long long)22, 22);
            ConstructorTest((long long)23, 0);
            ConstructorTest((long long)24, 1);
            ConstructorTest((long long)1000000000000000, 5);
        }

        void ArithmeticTest(int a, int b, unsigned add, unsigned diff, unsigned multi) {
            ModInt<23> c, d;
            c = a;
            d = b;
            Assert::AreEqual(add, (c + d).get());
            Assert::AreEqual(add, (c += d).get());
            c = a;
            d = b;
            Assert::AreEqual(diff, (c - d).get());
            Assert::AreEqual(diff, (c -= d).get());
            c = a;
            d = b;
            Assert::AreEqual(multi, (c * d).get());
            Assert::AreEqual(multi, (c *= d).get());
            c = a;
            d = b;
            unsigned numerator = ((a % 23) + 23) % 23;
            unsigned denominator = ((b % 23) + 23) % 23;
            Assert::AreEqual(numerator, (c / d).get() * denominator % 23);
            Assert::AreEqual(numerator, (c /= d).get() * denominator % 23);
        }
        TEST_METHOD(ModIntTestMethod_ArithmeticOperator)
        {
            ArithmeticTest(2, 3, 5, 22, 6);
            ArithmeticTest(17, 12, 6, 5, 20);
            ArithmeticTest(-6, 15, 9, 2, 2);
            ArithmeticTest(20, -5, 15, 2, 15);
            ArithmeticTest(-4, -17, 2, 13, 22);
        }

        TEST_METHOD(ModIntTestMethod_Nan)
        {
            ModInt<23> a;
            a.undef();
            Assert::AreEqual((unsigned)-1, a.get());
            Assert::IsTrue(a.is_nan());
            a = 4;
            Assert::IsFalse(a.is_nan());
        }

        TEST_METHOD(ModIntTestMethod_Compare)
        {
            ModInt<23> a, b;
            a = 5;
            b = 17;
            Assert::IsTrue(a < b);
            Assert::IsFalse(b < a);
            Assert::IsFalse(a < a);
            Assert::IsTrue(a <= b);
            Assert::IsFalse(b <= a);
            Assert::IsTrue(a <= a);
            Assert::IsTrue(a == a);
            Assert::IsFalse(a != a);
            Assert::IsFalse(a == b);
            Assert::IsTrue(a != b);
        }

        TEST_METHOD(ModIntTestMethod_Other)
        {
            ModInt<23> a;
            a = 5;
            Assert::AreEqual((unsigned)18, (-a).get());
            a = 0;
            Assert::AreEqual((unsigned)0, (-a).get());
            a = 5;
            a = a.inverse();
            Assert::AreEqual((unsigned)1, (a.get() * 5) % 23);
            a = 5;
            a = a.quick_pow(3);
            Assert::AreEqual((unsigned)10, a.get());
        }
        // I/O streamは、動作確認のみとし、自動単体テストは実施しない。

    };
}
