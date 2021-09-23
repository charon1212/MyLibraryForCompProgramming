#include <vector>

/// <summary>
/// @NoUnitTest
/// Union-Findを管理するクラス。
/// 実装参考：https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
/// 本クラスのコメントにおいて、「xを根とする木」を「x木」と呼ぶ。
/// </summary>
/// <typeparam name="T">管理対象の数値データ型。通常はintを指定。</typeparam>
template <typename T = int>
class UnionFind {
public:
    // 各要素の親・根であるか・集合サイズをすべて管理するデータ。
    // 負の値であれば、根であることを表す。
    // 負の大きさは、自分を根とするUnionFind木のサイズを表す。
    // 正の値であれば、親のindexを表す。
    std::vector<T> data;

    UnionFind(T size) {
        data = std::vector<T>(size, -1); // 最初は全て根で、その集合サイズは1。
    }

    /// <summary>
    /// 要素xの根のindex (0-origin)を取得する。
    /// xが根であれば、xを返却する。
    /// </summary>
    T root(T x) {
        if (data[x] < 0) return x; // 根であれば、自分のIndexを返却する。
        return (data[x] = root(data[x])); // 根でなければ、親の根のIndexを返却しつつ、その値を記憶する。
    }

    /// <summary>
    /// 要素xの属する木と要素yの属する木を接続する。
    /// </summary>
    /// <returns>接続を実施した場合はtrue、実施しない（xとyが元々同じ木に属していた）場合はfalse。</returns>
    bool merge(T x, T y) {
        x = root(x);
        y = root(y);
        if (x == y) return false; // 根が同じ場合は、結合しない
        if (data[x] > data[y]) std::swap(x, y); // xのほうがサイズが小さい場合、交換する。これで、xのほうがサイズが大きくなる。
        // y木を、x木につなげる。
        data[x] += data[y]; // x木のサイズにy木のサイズを足す。 (x=-6) + (y=-3) -> (x=-9) みたいに。
        data[y] = x; // y木の根をx木の根に接続する。
        return true;
    }

    /// <summary>
    /// 要素x,yが同じ木に属するか判定する。
    /// </summary>
    bool same(T x, T y) {
        return root(x) == root(y);
    }

    /// <summary>
    /// 要素xの属する木の集合サイズを取得する。
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    T size(T x) {
        return -(data[root(x)]); // xの根のdata値が、「(-1)*(x木のサイズ)」なので、それに(-1)をかける。
    }

};