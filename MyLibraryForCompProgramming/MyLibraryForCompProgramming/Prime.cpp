// 参考：https://ei1333.github.io/luzhiled/snippets/math/prime-factor.html

#include<map>

/// <summary>
/// ある数が素数であるかを判定する。
/// </summary>
/// <param name='x'>調べる対象の数値を指定。</param>
/// <returns>素数ならtrue、素数でなければfalseを返す。なお、x=1の場合もtrueとなる。</returns>
/// <remarks>計算オーダーはO(√N)</remarks>
inline bool is_prime(long long x) {
    for (long long i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

/// <summary>
/// ある数を素因数分解する。
/// </summary>
/// <param name='x'>素因数分解する対象の数値を指定。</param>
/// <returns>
/// 素数とその指数を関連付ける連想配列を返す。
/// 例えば、x=12の場合、戻り値の連想配列mはm[2]=2,m[3]=1となる。
/// </returns>
/// <remarks>計算オーダーはO(√N)。xが17桁で約1秒。（当然処理系によるが、競技プロの目安値として。）</remarks>
inline std::map<long long, int> calc_prime_factor(long long x) {
    std::map<long long, int> ret;
    // 2,3を先にやる。
    while (x % 2 == 0) {
        ret[2]++;
        x /= 2;
    }
    while (x % 3 == 0) {
        ret[3]++;
        x /= 3;
    }
    bool sw = true;
    long long factor = 5ll;
    while (factor * factor <= x) {
        while (x % factor == 0) {
            ret[factor]++;
            x /= factor;
        }
        // 6n+1と6n+5のみを対象とするための更新式
        factor += sw ? 2 : 4;
        sw != sw;
    }
    if (x != 1) ret[x] = 1;
    return ret;
}

/// <summary>
/// ある数の約数の総数を取得する。
/// </summary>
/// <param name='x'>約数の総数を調べる対象を指定。</param>
/// <returns>約数の総数。</returns>
/// <remarks>計算オーダーはcalc_prime_factorと同程度。(O(√N))</remarks>
inline int calc_divisor_count(long long x) {
    auto pFactor = calc_prime_factor(x);
    int ret = 1;
    for (auto it = pFactor.begin(); it != pFactor.end(); it++) { ret *= (it->second + 1); }
    return ret;
}
