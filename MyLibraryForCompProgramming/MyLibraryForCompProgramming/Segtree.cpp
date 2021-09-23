#include <vector>
#include <limits>

/// <summary>
/// セグメント木。
/// ある1次元配列(サイズN)と集約関数 op:(T,T)=>T に対し、下記の操作を実行できるデータ構造。
///   - 初期化…O(N)
///   - 1点の更新…O(log N)
///   - 区間の集約…O(log N)
/// 
/// ※集約関数は、性質 op(T1, T2, T3) = op(T1, op(T2, T3)) を満たすとする。合計・最小・最大などがこれに該当する。
/// 実装参考: https://algo-logic.info/segment-tree/
/// </summary>
/// <typeparam name="T">配列で管理するデータ型。通常はintかlong longを想定。opは集約関数を指定する。eは単位元を指定する。</typeparam>
template <typename T, T(*e)(), T(*op)(T, T)>
class Segtree {

public:
    int n; // Segtreeの葉の数。データが16個ならn=16, 17個ならn=32。
    /// <summary>
    /// セグメント木のデータ構造を管理する配列。
    /// サイズは2*n-1となる。
    /// i番目のセルに対し、
    ///   - 親セル → (i-1)/2
    ///   - 子セル → 2*i+1, 2*i+2
    /// となる。
    /// 参考: https://algo-logic.info/segment-tree/
    /// </summary>
    std::vector<T> data; // サイズが2*n-1の配列。

    Segtree(std::vector<T> init) {
        int s = init.size();
        n = 1;
        while (s > n) n *= 2;
        data = std::vector<T>(2 * n - 1);
        for (int i = 0; i < n; ++i) {
            if (i < s)
                data[i + n - 1] = init[i];
            else
                data[i + n - 1] = e();
        }
        for (int i = n - 2; i >= 0; --i)
            data[i] = op(data[2 * i + 1], data[2 * i + 2]);
    }

    /// <summary>
    /// ある点の値をvに更新する。
    /// </summary>
    /// <param name="i">更新する点の添え字(0-origin)。</param>
    /// <param name="v">更新する値。</param>
    void update(int i, T v) {
        i += n - 1;
        data[i] = v;
        while (i > 0) {
            i = (i - 1) / 2; // SegmentTreeの親をたどる。
            data[i] = op(data[2 * i + 1], data[2 * i + 2]);
        }
    }

    /// <summary>
    /// 区間[a,b)の集約値を求める。
    /// </summary>
    /// <param name="a">区間の開始点を表す0-originのインデックス。計算区間はこの添え字を含む。0以上n未満。</param>
    /// <param name="b">区間の終了店を表す0-originのインデックス。計算区間はこの添え字を含まない。1以上n以下。</param>
    /// <returns></returns>
    T query(int a, int b) {
        return query_sub(a, b, 0, 0, n);
    }
    /// <summary>
    /// 再帰処理のためのサブクエリ。
    /// 区間[a,b)の集約値を求めるため、位置「posi = [pl,pr)」にいるときの処理を規定する。
    /// posiの区間が[a,b)に含まれる場合は、data[posi]を返却する。
    /// a < pl < b < prのように一部含まれる場合は、左右のサブクエリ結果を集約して返却する。
    /// 全く含まれていない場合は、単位元e()を返却する。
    /// </summary>
    T query_sub(int a, int b, int posi, int pl, int pr) {
        if (pr <= a || pl >= b) {
            return e();
        }
        else if (a <= pl && pr <= b) {
            return data[posi];
        }
        else {
            int vl = query_sub(a, b, posi * 2 + 1, pl, (pl + pr) / 2);
            int vr = query_sub(a, b, posi * 2 + 2, (pl + pr) / 2, pr);
            return op(vl, vr);
        }
    }

};

// ■Range Minimum Query
template <typename T> T e_segtree_min() { return std::numeric_limits<T>::max(); }
template <typename T> T op_segtree_min(T a, T b) { return std::min(a, b); }
template <typename T> using SegtreeMin = Segtree<T, e_segtree_min, op_segtree_min>;
// ■Range Maximum Query
template <typename T> T e_segtree_max() { return std::numeric_limits<T>::min(); }
template <typename T> T op_segtree_max(T a, T b) { return std::max(a, b); }
template <typename T> using SegtreeMax = Segtree<T, e_segtree_max, op_segtree_max>;
// ■Sum
template <typename T> T e_segtree_sum() { return 0; }
template <typename T> T op_segtree_sum(T a, T b) { return a + b; }
template <typename T> using SegtreeSum = Segtree<T, e_segtree_sum, op_segtree_sum>;
