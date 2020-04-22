// 参考：https://atcoder.jp/contests/abc160/submissions/11280884

#include <vector>

/// <summary>
/// グラフの構造を表すクラス
/// </summary>
/// <example>
/// ループのサンプル：
/// <code>
/// Graph g; //gに辺を登録する処理は省略。
/// int u = 3; //始点u
/// for(int e = g.head[u]; e; e = g.next[e]){
///     // 始点uから出ている辺についてループする。
///     // g.from[e]で始点を、g.to[e]で終点を取得できる。
/// }
/// </code>
/// </example>
class Graph {
private:
    // 登録されている辺の総数を表す。
    int cnt;

public:
    // head[v]は、頂点vから出ている辺のedgeIDのうち、最大の値を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> head;
    // from[e]は、辺IDがeの辺の始点を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> from;
    // to[e]は、辺IDがeの辺の終点を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> to;
    // next[e]は、edgeIDがeの辺の始点uから出ている辺のうち、edgeIDがeの次に小さい辺のedgeIDを表す。
    // 最も小さい場合は、0を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> next;

    /// <summary>
    /// デフォルトコンストラクタ。
    /// このコンストラクタで作成したインスタンスの関数はほとんど利用できないため注意。
    /// </summary>
    Graph() {
        head = std::vector<int>(0);
        to = std::vector<int>(0);
        from = std::vector<int>(0);
        next = std::vector<int>(0);
        cnt = 0;
    }

    /// <summary>
    /// コンストラクタ。
    /// </summary>
    /// <param name='vertexMax'>頂点の最大登録数を指定する。Graph.resizeで後から変更できる。</param>
    /// <param name='edgeMax'>辺の最大登録数を指定する。Graph.resizeで後から変更できる。</param>
    Graph(int vertexMax, int edgeMax) {
        edgeMax++;
        head = std::vector<int>(vertexMax, 0);
        to = std::vector<int>(edgeMax, 0);
        from = std::vector<int>(edgeMax, 0);
        next = std::vector<int>(edgeMax, 0);
        cnt = 0;
    }

    /// <summary>
    /// 有向グラフの辺を登録する。
    /// </summary>
    /// <param name='from_'>辺の始点を0から始まる整数で指定する。</param>
    /// <param name='to_'>辺の終点を0から始まる整数で指定する。</param>
    void add_directed_edge(int from_, int to_) {
        // 辺の数に1を足す。足した後の値が、これから登録する辺のedgeIDとなる。
        cnt++;
        // fromを登録する。
        from[cnt] = from_;
        // toを登録する。
        to[cnt] = to_;
        // この辺の次にedgeIDが小さい辺のedgeIDは、head[from_]に登録されている。
        next[cnt] = head[from_];
        // 始点from_から出ている辺のedgeIDで最大のものは、今登録したcnt。
        head[from_] = cnt;
    }

    /// <summary>
    /// 無向グラフの辺を登録する。
    /// </summary>
    /// <param name='from_'>辺の始点を0から始まる整数で指定する。</param>
    /// <param name='to_'>辺の終点を0から始まる整数で指定する。</param>
    void add_undirected_edge(int from_, int to_) {
        add_directed_edge(from_, to_);
        add_directed_edge(to_, from_);
    }

    /// <summary>
    /// 登録された辺の総数を取得する。
    /// </summary>
    /// <returns>登録された辺の総数。</returns>
    int get_edge_length() {
        return cnt;
    }

    /// <summary>
    /// 頂点と辺の登録数の上限を変更する。
    /// </summary>
    /// <param name='vertexMax'>頂点の最大登録数を指定する。</param>
    /// <param name='edgeMax'>辺の最大登録数を指定する。</param>
    void resize(int vertexMax, int edgeMax) {
        edgeMax++;
        head.resize(vertexMax);
        to.resize(edgeMax);
        from.resize(edgeMax);
        next.resize(edgeMax);
    }

};

/// <summary>
/// 重み付きグラフの構造を表すクラス
/// </summary>
/// <param name="T">重みを表すデータ型を指定。</param>
template<typename T> class WeightedGraph {
private:
    // 登録されている辺の総数を表す。
    int cnt;

public:
    // head[v]は、頂点vから出ている辺のedgeIDのうち、最大の値を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> head;
    // from[e]は、辺IDがeの辺の始点を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> from;
    // to[e]は、辺IDがeの辺の終点を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> to;
    // next[e]は、edgeIDがeの辺の始点uから出ている辺のうち、edgeIDがeの次に小さい辺のedgeIDを表す。
    // 最も小さい場合は、0を表す。
    // edgeIDは1から始まり、登録順に採番される。
    std::vector<int> next;
    // weight[e]は、辺IDがeの辺の重みを表す。
    std::vector<T> weight;

    /// <summary>
    /// デフォルトコンストラクタ。
    /// このコンストラクタで作成したインスタンスの関数はほとんど利用できないため注意。
    /// </summary>
    WeightedGraph() {
        head = std::vector<int>(0);
        to = std::vector<int>(0);
        from = std::vector<int>(0);
        next = std::vector<int>(0);
        weight = std::vector<int>(0);
        cnt = 0;
    }

    /// <summary>
    /// コンストラクタ。
    /// </summary>
    /// <param name='vertexMax'>頂点の最大登録数を指定する。Graph.resizeで後から変更できる。</param>
    /// <param name='edgeMax'>辺の最大登録数を指定する。Graph.resizeで後から変更できる。</param>
    WeightedGraph(int vertexMax, int edgeMax) {
        edgeMax++;
        head = std::vector<int>(vertexMax, 0);
        to = std::vector<int>(edgeMax, 0);
        from = std::vector<int>(edgeMax, 0);
        next = std::vector<int>(edgeMax, 0);
        weight = std::vector<int>(edgeMax, 0);
        cnt = 0;
    }

    /// <summary>
    /// 有向グラフの辺を登録する。
    /// </summary>
    /// <param name='from_'>辺の始点を0から始まる整数で指定する。</param>
    /// <param name='to_'>辺の終点を0から始まる整数で指定する。</param>
    /// <param name='weight_'>辺の重みを指定する。</param>
    void add_directed_edge(int from_, int to_, T weight_) {
        // 辺の数に1を足す。足した後の値が、これから登録する辺のedgeIDとなる。
        cnt++;
        // fromを登録する。
        from[cnt] = from_;
        // toを登録する。
        to[cnt] = to_;
        // この辺の次にedgeIDが小さい辺のedgeIDは、head[from_]に登録されている。
        next[cnt] = head[from_];
        // 始点from_から出ている辺のedgeIDで最大のものは、今登録したcnt。
        head[from_] = cnt;
        // 重みを登録する。
        weight[cnt] = weight_;
    }

    /// <summary>
    /// 無向グラフの辺を登録する。
    /// </summary>
    /// <param name='from_'>辺の始点を0から始まる整数で指定する。</param>
    /// <param name='to_'>辺の終点を0から始まる整数で指定する。</param>
    /// <param name='weight_'>辺の重みを指定する。</param>
    void add_undirected_edge(int from_, int to_, T weight_) {
        add_directed_edge(from_, to_, weight_);
        add_directed_edge(to_, from_, weight_);
    }

    /// <summary>
    /// 登録された辺の総数を取得する。
    /// </summary>
    /// <returns>登録された辺の総数。</returns>
    int get_edge_length() {
        return cnt;
    }

    /// <summary>
    /// 頂点と辺の登録数の上限を変更する。
    /// </summary>
    /// <param name='vertexMax'>頂点の最大登録数を指定する。</param>
    /// <param name='edgeMax'>辺の最大登録数を指定する。</param>
    void resize(int vertexMax, int edgeMax) {
        edgeMax++;
        head.resize(vertexMax);
        to.resize(edgeMax);
        from.resize(edgeMax);
        next.resize(edgeMax);
    }

};
