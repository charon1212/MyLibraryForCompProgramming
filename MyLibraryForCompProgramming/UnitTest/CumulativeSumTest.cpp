#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/CumulativeSum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CumulativeSumTest
{
    TEST_CLASS(CumulativeSumTest)
    {
    public:

        TEST_METHOD(CumulativeSumTestMethod_1D)
        {
            auto v = std::vector<long long>({ 1,2,3,4,5,6,7 });
            auto cs1d = CumulativeSum1D(v);
            Assert::AreEqual(28ll, cs1d.query(0, 7));
            Assert::AreEqual(15ll, cs1d.query(0, 5));
            Assert::AreEqual(22ll, cs1d.query(3, 7));
            Assert::AreEqual(9ll, cs1d.query(3, 5));
        }

        TEST_METHOD(CumulativeSumTestMethod_2D)
        {
            auto v = std::vector<std::vector<long long>>({ { 1,2,3,4,5 },{ 3,4,5,6,7 },{ 5,6,7,8,9 },{ 7,8,9,10,11 },{ 9,10,11,12,13 } });
            auto cs2d = CumulativeSum2D(v);
            Assert::AreEqual(175ll, cs2d.query(0, 0, 5, 5));
            Assert::AreEqual(36ll, cs2d.query(0, 0, 3, 3));
            Assert::AreEqual(136ll, cs2d.query(1, 1, 5, 5));
            Assert::AreEqual(22ll, cs2d.query(1, 1, 3, 3));
            Assert::AreEqual(65ll, cs2d.query(0, 1, 5, 3));
            Assert::AreEqual(42ll, cs2d.query(2, 0, 4, 3));
            Assert::AreEqual(21ll, cs2d.query(1, 2, 4, 3));
        }

        TEST_METHOD(CumulativeSumTestMethod_3D)
        {
            auto v = std::vector<std::vector<std::vector<long long>>>(
                { {{1,2,3,4,5},{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45}},
                {{101,102,103,104,105},{111,112,113,114,115},{121,122,123,124,125},{131,132,133,134,135},{141,142,143,144,145}},
                {{201,202,203,204,205},{211,212,213,214,215},{221,222,223,224,225},{231,232,233,234,235},{241,242,243,244,245}},
                {{301,302,303,304,305},{311,312,313,314,315},{321,322,323,324,325},{331,332,333,334,335},{341,342,343,344,345}},
                {{401,402,403,404,405},{411,412,413,414,415},{421,422,423,424,425},{431,432,433,434,435},{441,442,443,444,445}} }
            );
            auto cs3d = CumulativeSum3D(v);
            Assert::AreEqual(27875ll, cs3d.query(0, 0, 0, 5, 5, 5));
            Assert::AreEqual(3024ll, cs3d.query(0, 0, 0, 3, 3, 3));
            Assert::AreEqual(17824ll, cs3d.query(1, 1, 1, 5, 5, 5));
            Assert::AreEqual(1340ll, cs3d.query(1, 1, 1, 3, 3, 3));
            Assert::AreEqual(1436ll, cs3d.query(1, 2, 3, 3, 4, 5));
            Assert::AreEqual(2907ll, cs3d.query(3, 1, 1, 4, 4, 4));
            Assert::AreEqual(0ll, cs3d.query(4, 1, 2, 4, 2, 5));
            Assert::AreEqual(1968ll, cs3d.query(2, 2, 2, 5, 4, 3));
            Assert::AreEqual(124ll, cs3d.query(1, 2, 3, 2, 3, 4));

        }

    };
}
