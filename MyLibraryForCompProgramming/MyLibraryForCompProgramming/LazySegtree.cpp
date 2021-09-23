/// <summary>
/// @NoUnitTest
/// 遅延セグメント木
/// 
/// 実装参考: https://algo-logic.info/segment-tree/
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T, T(*e)(), T(*op)(T, T)>
class LazySegtree {

public:
    int n; // Segtreeの葉の数。データが16個ならn=16, 17個ならn=32。
    std::vector<T> data; // サイズが2*n-1の配列。計算値本体。
    std::vector<T> lazy; // 遅延評価用。更新データを一時的に入れておく。

    LazySegtree(int size) {
        n = 1;
        while (n < size) n *= 2;
        data = std::vector<T>(2 * n - 1);
        lazy = std::vector<T>(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; i++) {
            data[i] = e();
            lazy[i] = e();
        }
    }

    init(std::vector<T> arr) {
        // dataの[n-1,2*n-1)に、指定したデータを入れる。
        for (int i = 0; i < arr.size(); i++) data[i + n - 1] = arr[i];
        // [0,n-1)について、計算しなおし。
        for (int i = n - 2; i >= 0; --i)
            data[i] = op(data[2 * i + 1], data[2 * i + 2]);
        // 遅延評価用の更新データはすべて初期化する。
        for (int i = 0; i < 2 * n - 1; i++) lazy[i] = e();
    }

    void eval(int k) {
        if (lazy[k] == e()) return;
        if (k < n - 1) { // 子供があれば、伝播する。
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身の再評価
        data[k] = lazy[k];
        lazy[k] = e();
    }

    void update(int a, int b, T x) {

    }

};
