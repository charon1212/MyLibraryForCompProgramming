// https://ei1333.github.io/luzhiled/snippets/dp/cumulative-sum.html

#include <vector>

/// <summary>
/// 1次元累積和を扱うクラス。
/// </summary>
class CumulativeSum1D {

private:
    //入力データa[0]～a[n-1]に対し、
    // source[0] = 0
    // source[k] = a[0] + … + a[k-1]
    std::vector<long long> data;

public:
    /// <summary>
    /// コンストラクタ
    /// 1次元累積和のための準備処理を実施する。
    /// </summary>
    /// <param name='source'>累積和をとる対象の数列を指定する。</param>
    /// <remarks>計算オーダーはO(N)。（Nはsourceの配列長）</remarks>
    CumulativeSum1D(std::vector<long long> source) {
        int n = source.size();
        data = std::vector<long long>(n + 1);
        data[0] = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += source[i];
            data[i + 1] = sum;
        }
    }

    /// <summary>
    /// 累積和を計算する。
    /// </summary>
    /// <param name='start'>累積和をとる区間の最初の添え字を、0から始まる整数で指定する。
    /// 0 &lt;= start &lt;= Nで指定する。(Nはコンストラクタで指定したsourceの配列長。)</param>
    /// <param name='end'>累積和をとる区間の最後の添え字+1を、0から始まる整数で指定する。
    /// 0 &lt;= end &lt;= Nで指定する。(Nはコンストラクタで指定したsourceの配列長。)</param>
    /// <returns>コンストラクタで指定した数列source[i]に対し、
    /// source[start] + … + source[end - 1]を返す。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long query(int start, int end) {
        return data[end] - data[start];
    }

};

/// <summary>
/// 2次元累積和を扱うクラス。
/// </summary>
class CumulativeSum2D {
private:
    // 入力データa[u][v]に対し、
    // data[u][v] = Σ_{u'<u, v'<v} a[u'][v']
    std::vector<std::vector<long long>> data;

public:
    /// <summary>
    /// コンストラクタ
    /// 2次元累積和のための準備処理を実施する。
    /// </summary>
    /// <param name='source'>累積和をとる対象の数列を指定する。</param>
    /// <remarks>計算オーダーはO(H×W)。（H,Dはそれぞれ、source配列の第1引数、第2引数に関する配列長）</remarks>
    CumulativeSum2D(std::vector<std::vector<long long>> source) {
        int h, w;
        h = source.size();
        w = source[0].size();
        data = std::vector<std::vector<long long>>(h + 1);
        for (int i = 0; i <= h; i++) data[i] = std::vector<long long>(w + 1);
        for (int u = 1; u <= h; u++) {
            for (int v = 1; v <= w; v++) {
                data[u][v] = data[u - 1][v] - data[u - 1][v - 1] + data[u][v - 1] + source[u - 1][v - 1];
            }
        }
    }

    /// <summary>
    /// 累積和を計算する。
    /// </summary>
    /// <param name='startU'>累積和をとる区間の、第1引数の最小値を指定する。範囲は0&lt;=startU&lt;=Hで指定する。（Hはコンストラクタで指定したsourceの第1引数についての配列長。）</param>
    /// <param name='startV'>累積和をとる区間の、第2引数の最小値を指定する。範囲は0&lt;=startV&lt;=Wで指定する。（Wはコンストラクタで指定したsourceの第2引数についての配列長。）</param>
    /// <param name='endU'>累積和をとる区間の、第1引数の最大値+1を指定する。範囲は0&lt;=endU&lt;=Hで指定する。（Hはコンストラクタで指定したsourceの第1引数についての配列長。）</param>
    /// <param name='endV'>累積和をとる区間の、第2引数の最大値+1を指定する。範囲は0&lt;=endV&lt;=Wで指定する。（Wはコンストラクタで指定したsourceの第2引数についての配列長。）</param>
    /// <returns>コンストラクタで指定したsource[i][j]に対し、startU &lt;= i &lt; endU、startV &lt;= j &lt; endVを満たすsource[i][j]の和を返す。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long query(int startU, int startV, int endU, int endV) {
        return data[endU][endV] - data[endU][startV] - data[startU][endV] + data[startU][startV];
    }
};

/// <summary>
/// 3次元累積和を扱うクラス。
/// </summary>
class CumulativeSum3D {
private:
    // 入力データa[u][v][w]に対し、
    // data[u][v][w] = Σ_{u'<u, v'<v,w'<w} a[u'][v'][w']
    std::vector<std::vector<std::vector<long long>>> data;

public:
    /// <summary>
    /// コンストラクタ
    /// 3次元累積和のための準備処理を実施する。
    /// </summary>
    /// <param name='source'>累積和をとる対象の数列を指定する。</param>
    /// <remarks>計算オーダーはO(H×W×D)。（H,W,Dはそれぞれ、source配列の第1引数、第2引数、第3引数に関する配列長）</remarks>
    CumulativeSum3D(std::vector<std::vector<std::vector<long long>>> source) {
        int h, w, d;
        h = source.size();
        w = source[0].size();
        d = source[0][0].size();
        data = std::vector<std::vector<std::vector<long long>>>(h + 1);
        for (int i = 0; i <= h; i++) {
            data[i] = std::vector<std::vector<long long>>(w + 1);
            for (int j = 0; j <= w; j++) data[i][j] = std::vector<long long>(d + 1);
        }
        for (int u = 1; u <= h; u++) {
            for (int v = 1; v <= w; v++) {
                for (int x = 1; x <= d; x++) {
                    data[u][v][x] = data[u - 1][v][x] - data[u - 1][v - 1][x]
                        + data[u][v - 1][x] - data[u][v - 1][x - 1]
                        + data[u][v][x - 1] - data[u - 1][v][x - 1]
                        + data[u - 1][v - 1][x - 1] + source[u - 1][v - 1][x - 1];
                }
            }
        }
    }

    /// <summary>
    /// 累積和を計算する。
    /// </summary>
    /// <param name='startU'>累積和をとる区間の、第1引数の最小値を指定する。範囲は0&lt;=startU&lt;=Hで指定する。（Hはコンストラクタで指定したsourceの第1引数についての配列長。）</param>
    /// <param name='startV'>累積和をとる区間の、第2引数の最小値を指定する。範囲は0&lt;=startV&lt;=Wで指定する。（Wはコンストラクタで指定したsourceの第2引数についての配列長。）</param>
    /// <param name='startW'>累積和をとる区間の、第2引数の最小値を指定する。範囲は0&lt;=startW&lt;=Wで指定する。（Dはコンストラクタで指定したsourceの第3引数についての配列長。）</param>
    /// <param name='endU'>累積和をとる区間の、第1引数の最大値+1を指定する。範囲は0&lt;=endU&lt;=Hで指定する。（Hはコンストラクタで指定したsourceの第1引数についての配列長。）</param>
    /// <param name='endV'>累積和をとる区間の、第2引数の最大値+1を指定する。範囲は0&lt;=endV&lt;=Wで指定する。（Wはコンストラクタで指定したsourceの第2引数についての配列長。）</param>
    /// <param name='endW'>累積和をとる区間の、第2引数の最大値+1を指定する。範囲は0&lt;=endW&lt;=Wで指定する。（Dはコンストラクタで指定したsourceの第3引数についての配列長。）</param>
    /// <returns>コンストラクタで指定したsource[i][j][k]に対し、startU &lt;= i &lt; endU、startV &lt;= j &lt; endV、startW &lt;= k &lt; endWを満たすsource[i][j][k]の和を返す。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long query(int startU, int startV, int startW, int endU, int endV, int endW) {
        return data[endU][endV][endW]
            - data[startU][endV][endW] + data[endU][startV][startW]
            - data[endU][startV][endW] + data[startU][endV][startW]
            - data[endU][endV][startW] + data[startU][startV][endW]
            - data[startU][startV][startW];
        return data[endU][endV][endW] - data[startU][startV][startW];
    }
};
