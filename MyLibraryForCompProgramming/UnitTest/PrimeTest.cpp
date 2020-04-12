#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/Prime.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrimeTest
{
    TEST_CLASS(PrimeTest)
    {
    public:

        TEST_METHOD(PrimeTestMethod_RandomTest)
        {
            std::map<long long, int> m;
            // 7 = 7
            Assert::IsTrue(is_prime(7ll));
            Assert::AreEqual(2, calc_divisor_count(7ll));
            m = calc_prime_factor(7ll);
            Assert::AreEqual(1, (int)m.size());
            Assert::AreEqual(1, m[7ll]);

            // 16 = 2^4
            Assert::IsFalse(is_prime(16ll));
            Assert::AreEqual(5, calc_divisor_count(16ll));
            m = calc_prime_factor(16ll);
            Assert::AreEqual(1, (int)m.size());
            Assert::AreEqual(4, m[2ll]);

            // 7604 = 2 * 2 * 1901
            Assert::IsFalse(is_prime(7604ll));
            Assert::AreEqual(6, calc_divisor_count(7604ll));
            m = calc_prime_factor(7604ll);
            Assert::AreEqual(2, (int)m.size());
            Assert::AreEqual(2, m[2ll]);
            Assert::AreEqual(1, m[1901ll]);

            // 162460 = 2 * 2 * 5 * 8123
            Assert::IsFalse(is_prime(162460ll));
            Assert::AreEqual(12, calc_divisor_count(162460ll));
            m = calc_prime_factor(162460ll);
            Assert::AreEqual(3, (int)m.size());
            Assert::AreEqual(2, m[2ll]);
            Assert::AreEqual(1, m[5ll]);
            Assert::AreEqual(1, m[8123ll]);

            // 322001 = 322001
            Assert::IsTrue(is_prime(322001ll));
            Assert::AreEqual(2, calc_divisor_count(322001ll));
            m = calc_prime_factor(322001ll);
            Assert::AreEqual(1, (int)m.size());
            Assert::AreEqual(1, m[322001ll]);

            // 472350 = 2 * 3 * 5 * 5 * 47 * 67
            Assert::IsFalse(is_prime(472350ll));
            Assert::AreEqual(48, calc_divisor_count(472350ll));
            m = calc_prime_factor(472350ll);
            Assert::AreEqual(5, (int)m.size());
            Assert::AreEqual(1, m[2ll]);
            Assert::AreEqual(1, m[3ll]);
            Assert::AreEqual(2, m[5ll]);
            Assert::AreEqual(1, m[47ll]);
            Assert::AreEqual(1, m[67ll]);

            // 5987238 = 2 * 3 * 367 * 2719
            Assert::IsFalse(is_prime(5987238ll));
            Assert::AreEqual(16, calc_divisor_count(5987238ll));
            m = calc_prime_factor(5987238ll);
            Assert::AreEqual(4, (int)m.size());
            Assert::AreEqual(1, m[2ll]);
            Assert::AreEqual(1, m[3ll]);
            Assert::AreEqual(1, m[367ll]);
            Assert::AreEqual(1, m[2719ll]);

            // 279686254 = 2 * 8707 * 16061
            Assert::IsFalse(is_prime(279686254ll));
            Assert::AreEqual(8, calc_divisor_count(279686254ll));
            m = calc_prime_factor(279686254ll);
            Assert::AreEqual(3, (int)m.size());
            Assert::AreEqual(1, m[2ll]);
            Assert::AreEqual(1, m[8707ll]);
            Assert::AreEqual(1, m[16061ll]);

            // 405621077 = 23 * 41 * 430139
            Assert::IsFalse(is_prime(405621077ll));
            Assert::AreEqual(8, calc_divisor_count(405621077ll));
            m = calc_prime_factor(405621077ll);
            Assert::AreEqual(3, (int)m.size());
            Assert::AreEqual(1, m[23ll]);
            Assert::AreEqual(1, m[41ll]);
            Assert::AreEqual(1, m[430139ll]);

            // 4483509103 = 4483509103
            Assert::IsTrue(is_prime(4483509103ll));
            Assert::AreEqual(2, calc_divisor_count(4483509103ll));
            m = calc_prime_factor(4483509103ll);
            Assert::AreEqual(1, (int)m.size());
            Assert::AreEqual(1, m[4483509103ll]);

            // 1332371853643 = 1332371853643
            Assert::IsTrue(is_prime(1332371853643ll));
            Assert::AreEqual(2, calc_divisor_count(1332371853643ll));
            m = calc_prime_factor(1332371853643ll);
            Assert::AreEqual(1, (int)m.size());
            Assert::AreEqual(1, m[1332371853643ll]);

            // 2021955178653 = 3 * 3 * 3 * 3 * 97 * 25734429
            Assert::IsFalse(is_prime(2021955178653ll));
            Assert::AreEqual(20, calc_divisor_count(2021955178653ll));
            m = calc_prime_factor(2021955178653ll);
            Assert::AreEqual(3, (int)m.size());
            Assert::AreEqual(4, m[3ll]);
            Assert::AreEqual(1, m[97ll]);
            Assert::AreEqual(1, m[257344429]);

            // 10497950979626 = 2 * 11 * 471781 * 1011443
            Assert::IsFalse(is_prime(10497950979626ll));
            Assert::AreEqual(16, calc_divisor_count(10497950979626ll));
            m = calc_prime_factor(10497950979626ll);
            Assert::AreEqual(4, (int)m.size());
            Assert::AreEqual(1, m[2ll]);
            Assert::AreEqual(1, m[11ll]);
            Assert::AreEqual(1, m[471781ll]);
            Assert::AreEqual(1, m[1011443ll]);

            // 78383643740599 = 1277 * 61381083587
            Assert::IsFalse(is_prime(78383643740599ll));
            Assert::AreEqual(4, calc_divisor_count(78383643740599ll));
            m = calc_prime_factor(78383643740599ll);
            Assert::AreEqual(2, (int)m.size());
            Assert::AreEqual(1, m[1277ll]);
            Assert::AreEqual(1, m[61381083587ll]);

            // 111831162917644 = 2 * 2 * 19 * 1471462669969
            Assert::IsFalse(is_prime(111831162917644ll));
            Assert::AreEqual(12, calc_divisor_count(111831162917644ll));
            m = calc_prime_factor(111831162917644ll);
            Assert::AreEqual(3, (int)m.size());
            Assert::AreEqual(2, m[2ll]);
            Assert::AreEqual(1, m[19ll]);
            Assert::AreEqual(1, m[1471462669969ll]);

            // 680197279457112 = 2 * 2 * 2 * 3 * 109 * 260014250557
            Assert::IsFalse(is_prime(680197279457112ll));
            Assert::AreEqual(32, calc_divisor_count(680197279457112ll));
            m = calc_prime_factor(680197279457112ll);
            Assert::AreEqual(4, (int)m.size());
            Assert::AreEqual(3, m[2ll]);
            Assert::AreEqual(1, m[3ll]);
            Assert::AreEqual(1, m[109ll]);
            Assert::AreEqual(1, m[260014250557ll]);

            // 2057120490763690 = 2 * 5 * 11 * 199 * 4229 * 22221649
            Assert::IsFalse(is_prime(2057120490763690ll));
            Assert::AreEqual(64, calc_divisor_count(2057120490763690ll));
            m = calc_prime_factor(2057120490763690ll);
            Assert::AreEqual(6, (int)m.size());
            Assert::AreEqual(1, m[2ll]);
            Assert::AreEqual(1, m[5ll]);
            Assert::AreEqual(1, m[11ll]);
            Assert::AreEqual(1, m[199ll]);
            Assert::AreEqual(1, m[4229ll]);
            Assert::AreEqual(1, m[22221649ll]);

            // 16652414841247900 = 2 * 2 * 5 * 5 * 11 * 13 * 307 * 22483 * 168713
            Assert::IsFalse(is_prime(16652414841247900ll));
            Assert::AreEqual(288, calc_divisor_count(16652414841247900ll));
            m = calc_prime_factor(16652414841247900ll);
            Assert::AreEqual(7, (int)m.size());
            Assert::AreEqual(2, m[2ll]);
            Assert::AreEqual(2, m[5ll]);
            Assert::AreEqual(1, m[11ll]);
            Assert::AreEqual(1, m[13ll]);
            Assert::AreEqual(1, m[307ll]);
            Assert::AreEqual(1, m[22483ll]);
            Assert::AreEqual(1, m[168713ll]);

            // 75095548994572300 = 2 * 2 * 5 * 5 * 1427 * 526247715449
            Assert::IsFalse(is_prime(75095548994572300ll));
            Assert::AreEqual(36, calc_divisor_count(75095548994572300ll));
            m = calc_prime_factor(75095548994572300ll);
            Assert::AreEqual(4, (int)m.size());
            Assert::AreEqual(2, m[2ll]);
            Assert::AreEqual(2, m[5ll]);
            Assert::AreEqual(1, m[1427ll]);
            Assert::AreEqual(1, m[526247715449ll]);

            // 786143803760666000 = 2 * 2 * 2 * 2 * 5 * 5 * 5 * 13 * 19 * 83 * 19173303833
            Assert::IsFalse(is_prime(786143803760666000ll));
            Assert::AreEqual(320, calc_divisor_count(786143803760666000ll));
            m = calc_prime_factor(786143803760666000ll);
            Assert::AreEqual(6, (int)m.size());
            Assert::AreEqual(4, m[2ll]);
            Assert::AreEqual(3, m[5ll]);
            Assert::AreEqual(1, m[13ll]);
            Assert::AreEqual(1, m[19ll]);
            Assert::AreEqual(1, m[83ll]);
            Assert::AreEqual(1, m[19173303833ll]);

            // 1000000000000000009 = 1000000000000000009
            Assert::IsTrue(is_prime(1000000000000000009ll));
            Assert::AreEqual(2, calc_divisor_count(1000000000000000009ll));
            m = calc_prime_factor(1000000000000000009ll);
            Assert::AreEqual(1, (int)m.size());
            Assert::AreEqual(1, m[1000000000000000009ll]);

        }
    };
}
