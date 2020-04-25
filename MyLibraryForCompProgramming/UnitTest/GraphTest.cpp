#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLibraryForCompProgramming/Graph.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::literals::string_literals; //std::stringのリテラル用

namespace GraphTest
{
    TEST_CLASS(GraphTest)
    {
    public:

        // 適当な無向グラフを表現できることを確かめる。
        // グラフの概要は、/Docs/GraphTest1.drawioを参照。ただし、無向グラフとして扱い、辺の重みは無視する。
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

            // 0から始まる辺は0-1と0-2の2つ。登録順から、そのedgeIDは1,5である。(edgeID自体は内部実装の都合なので、アサートの対象外)
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0); // ループが終わるとedgeIDが0となる。
            // 1から始まる辺は、1-0,1-2,1-3の3つ。
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
            // 2から始まる辺は、2-0,2-1,2-3,2-4の4つ。
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
            // 3から始まる辺は、3-1,3-2,3-4の3つ。
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
            // 4から始まる辺は、4-2,4-3の2つ。
            int e4 = g.head[4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(3, g.to[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(2, g.to[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(0, e4);

        }

        // 適当な有向グラフを表現できることを確かめる。
        // グラフの概要は、/Docs/GraphTest1.drawioを参照。ただし、辺の重みは無視する。
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

            // 0から始まる辺は、0-1,0-2の2つ。
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0);
            // 1から始まる辺はない。
            int e1 = g.head[1];
            Assert::AreEqual(0, e1);
            // 2から始まる辺は、2-1,2-3,2-4の3つ。
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
            // 3から始まる辺は、3-1のみ。
            int e3 = g.head[3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(1, g.to[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(0, e3);
            // 4から始まる辺は、4-3のみ。
            int e4 = g.head[4];
            Assert::AreEqual(4, g.from[e4]);
            Assert::AreEqual(3, g.to[e4]);
            e4 = g.next[e4];
            Assert::AreEqual(0, e4);

        }

        // 適当な重み付き無向グラフを表現できることを確かめる。
        // グラフの概要は、/Docs/GraphTest1.drawioを参照。ただし、無向グラフとして扱う。
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

            // 0から始まる辺は0-1と0-2の2つ。登録順から、そのedgeIDは1,5である。(edgeID自体は内部実装の都合なので、アサートの対象外)
            int e0 = g.head[0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(2, g.to[e0]);
            Assert::AreEqual(5, g.weight[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, g.from[e0]);
            Assert::AreEqual(1, g.to[e0]);
            Assert::AreEqual(13, g.weight[e0]);
            e0 = g.next[e0];
            Assert::AreEqual(0, e0); // ループが終わるとedgeIDが0となる。
            // 1から始まる辺は、1-0,1-2,1-3の3つ。
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
            // 2から始まる辺は、2-0,2-1,2-3,2-4の4つ。
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
            // 3から始まる辺は、3-1,3-2,3-4の3つ。
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
            // 4から始まる辺は、4-2,4-3の2つ。
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

        // 適当な重み付き有向グラフを表現できることを確かめる。
        // グラフの概要は、/Docs/GraphTest1.drawioを参照。
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

            // 0から始まる辺は、0-1,0-2の2つ。
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
            // 1から始まる辺はない。
            int e1 = g.head[1];
            Assert::AreEqual(0, e1);
            // 2から始まる辺は、2-1,2-3,2-4の3つ。
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
            // 3から始まる辺は、3-1のみ。
            int e3 = g.head[3];
            Assert::AreEqual(3, g.from[e3]);
            Assert::AreEqual(1, g.to[e3]);
            Assert::AreEqual(4, g.weight[e3]);
            e3 = g.next[e3];
            Assert::AreEqual(0, e3);
            // 4から始まる辺は、4-3のみ。
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
