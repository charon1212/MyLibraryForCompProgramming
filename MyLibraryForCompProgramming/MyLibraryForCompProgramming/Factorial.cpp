// 参考：https://atcoder.jp/contests/abc160/submissions/11287086

#include <vector>

/// <summary>
/// 階乗計算を扱うクラス。
/// 階乗を利用して計算できる他の値も利用する。
/// テンプレート引数で法を指定する。
/// 法には2,147,483,624以下の非負の素数を指定すること。
/// (2乗でlong longを超えず、逆元を求めるため。)
/// </summary>
template<unsigned MOD_> class Factorial {
private:
    // fact[i] = i! (mod MOD_)
    std::vector<long long> fact;
    // inv[i] = 1/(i!) (mod MOD_)
    std::vector<long long> inv;
    /// <summary>
    /// 高速指数計算
    /// </summary>
    /// <param name='a'>基数を指定する。</param>
    /// <param name='b'>指数を指定する。</param>
    /// <returns>a^bを計算する。</returns>
    /// <remarks>計算オーダーはO(log b)。</remarks>
    long long quick_pow(long long a, long long b) {
        a %= MOD_;
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD_;
            a = (a * a) % MOD_;
            b >>= 1;
        }
        return res;
    }

public:
    /// <summary>
    /// Factorialクラスのコンストラクタ。
    /// i!と(1/i!)を計算する。(0 &lt;= i &lt;= n)
    /// </summary>
    /// <param name='n'>階乗計算の上限を指定する。</param>
    /// <remarks>計算オーダーはO(n + log(MOD_))。</remarks>
    Factorial(int n) {
        ++n;
        fact = inv = std::vector<long long>(n);
        fact[0] = inv[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD_;
        }
        // 法MOD_のもとで1/fact[n-1]を計算する。
        // Fermatの小定理( a^(p-1) = 1 (mod p) )を利用する。
        // aとpが互いに素であることが必要条件である点に注意。
        inv[n - 1] = quick_pow(fact[n - 1], MOD_ - 2);
        for (int i = n - 2; i >= 0; i--) {
            inv[i] = (inv[i + 1] * (i + 1)) % MOD_;
        }
    }
    /// <summary>
    /// n!を法MOD_のもとで取得する。
    /// </summary>
    /// <param name='n'>nの値を指定する。</param>
    /// <returns>n! % MOD_。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long get(int n) {
        return fact[n];
    }
    /// <summary>
    /// 1/n!を法MOD_のもとで取得する。
    /// </summary>
    /// <param name='n'>nの値を指定する。</param>
    /// <returns>(n! ^ (MOD_ - 2)) % MOD_。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long get_inv(int n) {
        return inv[n];
    }
    /// <summary>
    /// 順列nPrを計算する。
    /// </summary>
    /// <param name='n'>nPrのnの値を指定する。</param>
    /// <param name='r'>nPrのrの値を指定する。</param>
    /// <returns>nPr % MOD_。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long permutation(int n, int r) {
        return (fact[n] * inv[n - r]) % MOD_;
    }
    /// <summary>
    /// 組み合わせの通り数nCrを計算する。
    /// </summary>
    /// <param name='n'>nCrのnの値を指定する。</param>
    /// <param name='r'>nCrのrの値を指定する。</param>
    /// <returns>nCr % MOD_。</returns>
    /// <remarks>計算オーダーはO(1)。</remarks>
    long long combination(int n, int r) {
        return (permutation(n, r) * inv[r]) % MOD_;
    }
};
