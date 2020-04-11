#include <vector>
typedef long long ll;
// 参考：https://atcoder.jp/contests/abc160/submissions/11287086

/// <summary>
/// 概要
/// </summary>
template<unsigned MOD_> class Factorial {
private:
    vector<ll> fact;
    vector<ll> inv;
    ll quick_pow(ll a, ll b) {
        a %= MOD_;
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD_;
            a = (a * a) % MOD_;
            b >>= 1;
        }
        return res;
    }

public:
    /// <summary>
    /// 概要
    /// </summary>
    /// <param name='n'>説明</param>
    /// <param name='m'>説明2</param>
    Factorial(int n, int m) {
        ++n;
        fact = inv = vector<ll>(n);
        fact[0] = inv[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD_;
        }
        inv[n - 1] = quick_pow(fact[n - 1], MOD_ - 2);
        for (int i = n - 2; i >= 0; i--) {
            inv[i] = (inv[i + 1] * (i + 1)) % MOD_;
        }
    }
    ll get(int n) {
        return fact[n];
    }
    ll get_inv(int n) {
        return inv[n];
    }
    ll permutation(int n, int r) {
        return (fact[n] * inv[n - r]) % MOD_;
    }
    ll combination(int n, int r) {
        return (permutation(n, r) * inv[r]) % MOD_;
    }
};
