#include "pch.h"
#include "CppUnitTest.h"
#include "CppUnitTestLogger.h"
#include "..//MyLibraryForCompProgramming/Factorial.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FactorialTest
{
    TEST_CLASS(FactorialTest)
    {
    public:

        TEST_METHOD(FactorialTestMethod_getFactorialMod1000000007)
        {
            const int MOD = 1e9 + 7;
            auto fact = Factorial<MOD>(20);
            Assert::AreEqual(1ll, fact.get(0));
            Assert::AreEqual(1ll, fact.get(1));
            Assert::AreEqual(2ll, fact.get(2));
            Assert::AreEqual(6ll, fact.get(3));
            Assert::AreEqual(24ll, fact.get(4));
            Assert::AreEqual(120ll, fact.get(5));
            Assert::AreEqual(720ll, fact.get(6));
            Assert::AreEqual(5040ll, fact.get(7));
            Assert::AreEqual(40320ll, fact.get(8));
            Assert::AreEqual(362880ll, fact.get(9));
            Assert::AreEqual(3628800ll, fact.get(10));
            Assert::AreEqual(39916800ll, fact.get(11));
            Assert::AreEqual(479001600ll, fact.get(12));
            Assert::AreEqual(227020758ll, fact.get(13));
            Assert::AreEqual(178290591ll, fact.get(14));
            Assert::AreEqual(674358851ll, fact.get(15));
            Assert::AreEqual(789741546ll, fact.get(16));
            Assert::AreEqual(425606191ll, fact.get(17));
            Assert::AreEqual(660911389ll, fact.get(18));
            Assert::AreEqual(557316307ll, fact.get(19));
            Assert::AreEqual(146326063ll, fact.get(20));
        }

        TEST_METHOD(FactorialTestMethod_getFactorialMod1234567)
        {
            const int MOD = 1234567;
            auto fact = Factorial<MOD>(20);
            Assert::AreEqual(1ll, fact.get(0));
            Assert::AreEqual(1ll, fact.get(1));
            Assert::AreEqual(2ll, fact.get(2));
            Assert::AreEqual(6ll, fact.get(3));
            Assert::AreEqual(24ll, fact.get(4));
            Assert::AreEqual(120ll, fact.get(5));
            Assert::AreEqual(720ll, fact.get(6));
            Assert::AreEqual(5040ll, fact.get(7));
            Assert::AreEqual(40320ll, fact.get(8));
            Assert::AreEqual(362880ll, fact.get(9));
            Assert::AreEqual(1159666ll, fact.get(10));
            Assert::AreEqual(410656ll, fact.get(11));
            Assert::AreEqual(1224171ll, fact.get(12));
            Assert::AreEqual(1099419ll, fact.get(13));
            Assert::AreEqual(577062ll, fact.get(14));
            Assert::AreEqual(13961ll, fact.get(15));
            Assert::AreEqual(223376ll, fact.get(16));
            Assert::AreEqual(93691ll, fact.get(17));
            Assert::AreEqual(451871ll, fact.get(18));
            Assert::AreEqual(1178147ll, fact.get(19));
            Assert::AreEqual(106167ll, fact.get(20));
        }

        TEST_METHOD(FactorialTestMethod_getInverse) {
            const int MOD = 1e9 + 7;
            auto fact = Factorial<MOD>(20);
            // ãtå≥ÇÃèÿñæÇÕÅAMODÇÃê¢äEÇ≈Ç©ÇØÇƒ1Ç…Ç»ÇÈÇ±Ç∆ÅBÇ±ÇÍÇ≈è\ï™ÅB
            Assert::AreEqual(1ll, fact.get_inv(0) * 1ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(1) * 1ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(2) * 2ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(3) * 6ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(4) * 24ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(5) * 120ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(6) * 720ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(7) * 5040ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(8) * 40320ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(9) * 362880ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(10) * 3628800ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(11) * 39916800ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(12) * 479001600ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(13) * 227020758ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(14) * 178290591ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(15) * 674358851ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(16) * 789741546ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(17) * 425606191ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(18) * 660911389ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(19) * 557316307ll % MOD);
            Assert::AreEqual(1ll, fact.get_inv(20) * 146326063ll % MOD);
        }

        TEST_METHOD(FactorialTestMethod_getPermutation) {
            const int MOD = 1e9 + 7;
            auto fact = Factorial<MOD>(20);
            Assert::AreEqual(2ll, fact.permutation(2, 1));
            Assert::AreEqual(20ll, fact.permutation(20, 1));
            Assert::AreEqual(442568110ll, fact.permutation(20, 10));
            Assert::AreEqual(146326063ll, fact.permutation(20, 19));
            Assert::AreEqual(1ll, fact.permutation(0, 0));
            Assert::AreEqual(1ll, fact.permutation(1, 0));
            Assert::AreEqual(1ll, fact.permutation(2, 0));
            Assert::AreEqual(1ll, fact.permutation(3, 0));
            Assert::AreEqual(1ll, fact.permutation(4, 0));
            Assert::AreEqual(1ll, fact.permutation(5, 0));
            Assert::AreEqual(1ll, fact.permutation(6, 0));
            Assert::AreEqual(1ll, fact.permutation(7, 0));
            Assert::AreEqual(1ll, fact.permutation(8, 0));
            Assert::AreEqual(1ll, fact.permutation(9, 0));
            Assert::AreEqual(1ll, fact.permutation(10, 0));
            Assert::AreEqual(1ll, fact.permutation(11, 0));
            Assert::AreEqual(1ll, fact.permutation(12, 0));
            Assert::AreEqual(1ll, fact.permutation(13, 0));
            Assert::AreEqual(1ll, fact.permutation(14, 0));
            Assert::AreEqual(1ll, fact.permutation(15, 0));
            Assert::AreEqual(1ll, fact.permutation(16, 0));
            Assert::AreEqual(1ll, fact.permutation(17, 0));
            Assert::AreEqual(1ll, fact.permutation(18, 0));
            Assert::AreEqual(1ll, fact.permutation(19, 0));
            Assert::AreEqual(1ll, fact.permutation(20, 0));
            Assert::AreEqual(1ll, fact.permutation(1, 1));
            Assert::AreEqual(2ll, fact.permutation(2, 2));
            Assert::AreEqual(6ll, fact.permutation(3, 3));
            Assert::AreEqual(24ll, fact.permutation(4, 4));
            Assert::AreEqual(120ll, fact.permutation(5, 5));
            Assert::AreEqual(720ll, fact.permutation(6, 6));
            Assert::AreEqual(5040ll, fact.permutation(7, 7));
            Assert::AreEqual(40320ll, fact.permutation(8, 8));
            Assert::AreEqual(362880ll, fact.permutation(9, 9));
            Assert::AreEqual(3628800ll, fact.permutation(10, 10));
            Assert::AreEqual(39916800ll, fact.permutation(11, 11));
            Assert::AreEqual(479001600ll, fact.permutation(12, 12));
            Assert::AreEqual(227020758ll, fact.permutation(13, 13));
            Assert::AreEqual(178290591ll, fact.permutation(14, 14));
            Assert::AreEqual(674358851ll, fact.permutation(15, 15));
            Assert::AreEqual(789741546ll, fact.permutation(16, 16));
            Assert::AreEqual(425606191ll, fact.permutation(17, 17));
            Assert::AreEqual(660911389ll, fact.permutation(18, 18));
            Assert::AreEqual(557316307ll, fact.permutation(19, 19));
            Assert::AreEqual(146326063ll, fact.permutation(20, 20));
            Assert::AreEqual(3ll, fact.permutation(3, 1));
            Assert::AreEqual(24ll, fact.permutation(4, 3));
            Assert::AreEqual(120ll, fact.permutation(5, 4));
            Assert::AreEqual(7ll, fact.permutation(7, 1));
            Assert::AreEqual(2520ll, fact.permutation(7, 5));
            Assert::AreEqual(5040ll, fact.permutation(7, 6));
            Assert::AreEqual(1680ll, fact.permutation(8, 4));
            Assert::AreEqual(72ll, fact.permutation(9, 2));
            Assert::AreEqual(332640ll, fact.permutation(11, 6));
            Assert::AreEqual(39916800ll, fact.permutation(11, 10));
            Assert::AreEqual(132ll, fact.permutation(12, 2));
            Assert::AreEqual(3991680ll, fact.permutation(12, 7));
            Assert::AreEqual(2184ll, fact.permutation(14, 3));
            Assert::AreEqual(2162160ll, fact.permutation(14, 6));
            Assert::AreEqual(674358851ll, fact.permutation(15, 14));
            Assert::AreEqual(131623591ll, fact.permutation(16, 13));
            Assert::AreEqual(57120ll, fact.permutation(17, 4));
            Assert::AreEqual(980179200ll, fact.permutation(17, 8));
            Assert::AreEqual(572901910ll, fact.permutation(17, 10));
            Assert::AreEqual(306ll, fact.permutation(18, 2));
            Assert::AreEqual(47466219ll, fact.permutation(19, 8));
            Assert::AreEqual(380ll, fact.permutation(20, 2));
            Assert::AreEqual(79110365ll, fact.permutation(20, 8));
        }

        TEST_METHOD(FactorialTestMethod_getCombination) {
            const int MOD = 1e9 + 7;
            auto fact = Factorial<MOD>(20);
            Assert::AreEqual(2ll, fact.combination(2, 1));
            Assert::AreEqual(20ll, fact.combination(20, 1));
            Assert::AreEqual(184756ll, fact.combination(20, 10));
            Assert::AreEqual(20ll, fact.combination(20, 19));
            Assert::AreEqual(1ll, fact.combination(0, 0));
            Assert::AreEqual(1ll, fact.combination(1, 0));
            Assert::AreEqual(1ll, fact.combination(2, 0));
            Assert::AreEqual(1ll, fact.combination(3, 0));
            Assert::AreEqual(1ll, fact.combination(4, 0));
            Assert::AreEqual(1ll, fact.combination(5, 0));
            Assert::AreEqual(1ll, fact.combination(6, 0));
            Assert::AreEqual(1ll, fact.combination(7, 0));
            Assert::AreEqual(1ll, fact.combination(8, 0));
            Assert::AreEqual(1ll, fact.combination(9, 0));
            Assert::AreEqual(1ll, fact.combination(10, 0));
            Assert::AreEqual(1ll, fact.combination(11, 0));
            Assert::AreEqual(1ll, fact.combination(12, 0));
            Assert::AreEqual(1ll, fact.combination(13, 0));
            Assert::AreEqual(1ll, fact.combination(14, 0));
            Assert::AreEqual(1ll, fact.combination(15, 0));
            Assert::AreEqual(1ll, fact.combination(16, 0));
            Assert::AreEqual(1ll, fact.combination(17, 0));
            Assert::AreEqual(1ll, fact.combination(18, 0));
            Assert::AreEqual(1ll, fact.combination(19, 0));
            Assert::AreEqual(1ll, fact.combination(20, 0));
            Assert::AreEqual(1ll, fact.combination(1, 1));
            Assert::AreEqual(1ll, fact.combination(2, 2));
            Assert::AreEqual(1ll, fact.combination(3, 3));
            Assert::AreEqual(1ll, fact.combination(4, 4));
            Assert::AreEqual(1ll, fact.combination(5, 5));
            Assert::AreEqual(1ll, fact.combination(6, 6));
            Assert::AreEqual(1ll, fact.combination(7, 7));
            Assert::AreEqual(1ll, fact.combination(8, 8));
            Assert::AreEqual(1ll, fact.combination(9, 9));
            Assert::AreEqual(1ll, fact.combination(10, 10));
            Assert::AreEqual(1ll, fact.combination(11, 11));
            Assert::AreEqual(1ll, fact.combination(12, 12));
            Assert::AreEqual(1ll, fact.combination(13, 13));
            Assert::AreEqual(1ll, fact.combination(14, 14));
            Assert::AreEqual(1ll, fact.combination(15, 15));
            Assert::AreEqual(1ll, fact.combination(16, 16));
            Assert::AreEqual(1ll, fact.combination(17, 17));
            Assert::AreEqual(1ll, fact.combination(18, 18));
            Assert::AreEqual(1ll, fact.combination(19, 19));
            Assert::AreEqual(1ll, fact.combination(20, 20));
            Assert::AreEqual(3ll, fact.combination(3, 1));
            Assert::AreEqual(4ll, fact.combination(4, 3));
            Assert::AreEqual(5ll, fact.combination(5, 4));
            Assert::AreEqual(7ll, fact.combination(7, 1));
            Assert::AreEqual(21ll, fact.combination(7, 5));
            Assert::AreEqual(7ll, fact.combination(7, 6));
            Assert::AreEqual(70ll, fact.combination(8, 4));
            Assert::AreEqual(36ll, fact.combination(9, 2));
            Assert::AreEqual(462ll, fact.combination(11, 6));
            Assert::AreEqual(11ll, fact.combination(11, 10));
            Assert::AreEqual(66ll, fact.combination(12, 2));
            Assert::AreEqual(792ll, fact.combination(12, 7));
            Assert::AreEqual(364ll, fact.combination(14, 3));
            Assert::AreEqual(3003ll, fact.combination(14, 6));
            Assert::AreEqual(15ll, fact.combination(15, 14));
            Assert::AreEqual(560ll, fact.combination(16, 13));
            Assert::AreEqual(2380ll, fact.combination(17, 4));
            Assert::AreEqual(24310ll, fact.combination(17, 8));
            Assert::AreEqual(19448ll, fact.combination(17, 10));
            Assert::AreEqual(153ll, fact.combination(18, 2));
            Assert::AreEqual(75582ll, fact.combination(19, 8));
            Assert::AreEqual(190ll, fact.combination(20, 2));
            Assert::AreEqual(125970ll, fact.combination(20, 8));
        }
    };
}
