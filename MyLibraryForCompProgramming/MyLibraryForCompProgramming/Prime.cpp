#include<map>

// 素数判定
inline bool is_prime(long long x) {
    for (long long i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

// 素因数分解
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

// 約数の総数を取得
inline int calc_divisor_count(long long x) {
    auto pFactor = calc_prime_factor(x);
    int ret = 1;
    for (auto it = pFactor.begin(); it != pFactor.end(); it++) { ret *= (it->second + 1); }
    return ret;
}
