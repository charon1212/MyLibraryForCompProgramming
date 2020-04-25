#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/Graph.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::literals::string_literals; //std::string�̃��e�����p

namespace GraphTest
{
    TEST_CLASS(GraphTest)
    {
    public:

        // �K���Ȗ����O���t��\���ł��邱�Ƃ��m���߂�B
        // �O���t�̊T�v�́A/Docs/GraphTest1.drawio���Q�ƁB�������A�����O���t�Ƃ��Ĉ����A�ӂ̏d�݂͖�������B
        TEST_METHOD(GraphTestMethod_UndirectedGraph)
        {

            auto g = Graph(5, 14);
            g.add_undirected_edge(0, 1);
            g.add_undirected_edge(0, 2);
            g.add_undirected_edge(1, 2);
            g.add_undirected_edge(1, 3);
            g.add_undirected_edge(2, 3);
            g.add_undirected_edge(2, 4);
            g.add_undirected_edge(3, 4);

            Assert::AreEqual(14, g.get_edge_length());

            // 0����n�܂�ӂ�0-1��0-2��2�B�o�^������A����edgeID��1,5�ł���B(edgeID���͓̂��������̓s���Ȃ̂ŁA�A�T�[�g�̑ΏۊO)
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0); // ���[�v���I����edgeID��0�ƂȂ�B
            // 1����n�܂�ӂ́A1-0,1-2,1-3��3�B
            int e1 = g.head[1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(3, g.to[e1]);
            e1 = g.next[e1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(2, g.to[e1]);
            e1 = g.next[e1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(0, g.to[e1]);
            e1 = g.next[e1];
            Assert::AreEqual(0, e1);
            // 2����n�܂�ӂ́A2-0,2-1,2-3,2-4��4�B
            int e2 = g.head[2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(4, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(3, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(1, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(0, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(0, e2);
            // 3����n�܂�ӂ́A3-1,3-2,3-4��3�B
            int e3 = g.head[3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(4, g.to[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(2, g.to[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(1, g.to[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(0, e3);
            // 4����n�܂�ӂ́A4-2,4-3��2�B
            int e4 = g.head[4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(3, g.to[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(2, g.to[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(0, e4);

        }

        // �K���ȗL���O���t��\���ł��邱�Ƃ��m���߂�B
        // �O���t�̊T�v�́A/Docs/GraphTest1.drawio���Q�ƁB�������A�ӂ̏d�݂͖�������B
        TEST_METHOD(GraphTestMethod_DirectedGraph)
        {

            auto g = Graph(5, 7);
            g.add_directed_edge(0, 1);
            g.add_directed_edge(0, 2);
            g.add_directed_edge(2, 1);
            g.add_directed_edge(2, 3);
            g.add_directed_edge(2, 4);
            g.add_directed_edge(3, 1);
            g.add_directed_edge(4, 3);

            Assert::AreEqual(7, g.get_edge_length());

            // 0����n�܂�ӂ́A0-1,0-2��2�B
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0);
            // 1����n�܂�ӂ͂Ȃ��B
            int e1 = g.head[1];
            Assert::AreEqual(0, e1);
            // 2����n�܂�ӂ́A2-1,2-3,2-4��3�B
            int e2 = g.head[2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(4, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(3, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(1, g.to[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(0, e2);
            // 3����n�܂�ӂ́A3-1�̂݁B
            int e3 = g.head[3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(1, g.to[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(0, e3);
            // 4����n�܂�ӂ́A4-3�̂݁B
            int e4 = g.head[4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(3, g.to[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(0, e4);

        }

        // �K���ȏd�ݕt�������O���t��\���ł��邱�Ƃ��m���߂�B
        // �O���t�̊T�v�́A/Docs/GraphTest1.drawio���Q�ƁB�������A�����O���t�Ƃ��Ĉ����B
        TEST_METHOD(GraphTestMethod_UndirectedWeightedGraph)
        {

            auto g = WeightedGraph<int>(5, 14);
            g.add_undirected_edge(0, 1, 13);
            g.add_undirected_edge(0, 2, 5);
            g.add_undirected_edge(1, 2, 8);
            g.add_undirected_edge(1, 3, 4);
            g.add_undirected_edge(2, 3, 2);
            g.add_undirected_edge(2, 4, 3);
            g.add_undirected_edge(3, 4, 8);

            Assert::AreEqual(14, g.get_edge_length());

            // 0����n�܂�ӂ�0-1��0-2��2�B�o�^������A����edgeID��1,5�ł���B(edgeID���͓̂��������̓s���Ȃ̂ŁA�A�T�[�g�̑ΏۊO)
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            Assert::AreEqual(5, g.weight[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            Assert::AreEqual(13, g.weight[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0); // ���[�v���I����edgeID��0�ƂȂ�B
            // 1����n�܂�ӂ́A1-0,1-2,1-3��3�B
            int e1 = g.head[1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(3, g.to[e1]);
            Assert::AreEqual(4, g.weight[e1]);
            e1 = g.next[e1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(2, g.to[e1]);
            Assert::AreEqual(8, g.weight[e1]);
            e1 = g.next[e1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(0, g.to[e1]);
            Assert::AreEqual(13, g.weight[e1]);
            e1 = g.next[e1];
            Assert::AreEqual(0, e1);
            // 2����n�܂�ӂ́A2-0,2-1,2-3,2-4��4�B
            int e2 = g.head[2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(4, g.to[e2]);
            Assert::AreEqual(3, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(3, g.to[e2]);
            Assert::AreEqual(2, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(1, g.to[e2]);
            Assert::AreEqual(8, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(0, g.to[e2]);
            Assert::AreEqual(5, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(0, e2);
            // 3����n�܂�ӂ́A3-1,3-2,3-4��3�B
            int e3 = g.head[3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(4, g.to[e3]);
            Assert::AreEqual(8, g.weight[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(2, g.to[e3]);
            Assert::AreEqual(2, g.weight[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(1, g.to[e3]);
            Assert::AreEqual(4, g.weight[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(0, e3);
            // 4����n�܂�ӂ́A4-2,4-3��2�B
            int e4 = g.head[4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(3, g.to[e4]);
            Assert::AreEqual(8, g.weight[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(2, g.to[e4]);
            Assert::AreEqual(3, g.weight[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(0, e4);

        }

        // �K���ȏd�ݕt���L���O���t��\���ł��邱�Ƃ��m���߂�B
        // �O���t�̊T�v�́A/Docs/GraphTest1.drawio���Q�ƁB
        TEST_METHOD(GraphTestMethod_DirectedWeightedGraph)
        {

            auto g = WeightedGraph<int>(5, 7);
            g.add_directed_edge(0, 1, 13);
            g.add_directed_edge(0, 2, 5);
            g.add_directed_edge(2, 1, 8);
            g.add_directed_edge(2, 3, 2);
            g.add_directed_edge(2, 4, 3);
            g.add_directed_edge(3, 1, 4);
            g.add_directed_edge(4, 3, 8);

            Assert::AreEqual(7, g.get_edge_length());

            // 0����n�܂�ӂ́A0-1,0-2��2�B
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            Assert::AreEqual(5, g.weight[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            Assert::AreEqual(13, g.weight[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0);
            // 1����n�܂�ӂ͂Ȃ��B
            int e1 = g.head[1];
            Assert::AreEqual(0, e1);
            // 2����n�܂�ӂ́A2-1,2-3,2-4��3�B
            int e2 = g.head[2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(4, g.to[e2]);
            Assert::AreEqual(3, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(3, g.to[e2]);
            Assert::AreEqual(2, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(1, g.to[e2]);
            Assert::AreEqual(8, g.weight[e2]);
            e2 = g.next[e2];
            Assert::AreEqual(0, e2);
            // 3����n�܂�ӂ́A3-1�̂݁B
            int e3 = g.head[3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(1, g.to[e3]);
            Assert::AreEqual(4, g.weight[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(0, e3);
            // 4����n�܂�ӂ́A4-3�̂݁B
            int e4 = g.head[4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(3, g.to[e4]);
            Assert::AreEqual(8, g.weight[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(0, e4);

        }

        TEST_METHOD(GraphTestMethod_WeightedGraph_StringWeight)
        {
            auto g = WeightedGraph<std::string>(3, 3);
            g.add_directed_edge(0, 1, "aaa");
            g.add_directed_edge(1, 2, "bbb");
            g.add_directed_edge(2, 0, "ccc");

            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            Assert::AreEqual("aaa"s, g.weight[e0]);
            Assert::AreEqual(0, g.next[e0]);
            int e1 = g.head[1];
            Assert::AreEqual(1, g.from[e1]);
            Assert::AreEqual(2, g.to[e1]);
            Assert::AreEqual("bbb"s, g.weight[e1]);
            Assert::AreEqual(0, g.next[e1]);
            int e2 = g.head[2];
            Assert::AreEqual(2, g.from[e2]);
            Assert::AreEqual(0, g.to[e2]);
            Assert::AreEqual("ccc"s, g.weight[e2]);
            Assert::AreEqual(0, g.next[e2]);
        }

    };
}
