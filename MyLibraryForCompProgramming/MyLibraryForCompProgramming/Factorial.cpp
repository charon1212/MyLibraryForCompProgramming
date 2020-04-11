#include <vector>
typedef long long ll;
// �Q�l�Fhttps://atcoder.jp/contests/abc160/submissions/11287086

/// <summary>
/// �K��v�Z�������N���X�B
/// �K��𗘗p���Čv�Z�ł��鑼�̒l�����p����B
/// �e���v���[�g�����Ŗ@���w�肷��B
/// �@�ɂ�2,147,483,624�ȉ��̔񕉂̑f�����w�肷�邱�ƁB
/// (2���long long�𒴂����A�t�������߂邽�߁B)
/// </summary>
template<unsigned MOD_> class Factorial {
private:
    // fact[i] = i! (mod MOD_)
    vector<ll> fact;
    // inv[i] = 1/(i!) (mod MOD_)
    vector<ll> inv;
    /// <summary>
    /// �����w���v�Z
    /// </summary>
    /// <param name='a'>����w�肷��B</param>
    /// <param name='b'>�w�����w�肷��B</param>
    /// <returns>a^b���v�Z����</returns>
    /// <remarks>�v�Z�I�[�_�[��O(log b)</remarks>
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
    /// Factorial�N���X�̃R���X�g���N�^�B
    /// i!��(1/i!)���v�Z����B(0 <= i <= n)
    /// </summary>
    /// <param name='n'>�K��v�Z�̏�����w�肷��B</param>
    /// <remarks>�v�Z�I�[�_�[��O(n + log(MOD_))�B</remarks>
    Factorial(int n) {
        ++n;
        fact = inv = vector<ll>(n);
        fact[0] = inv[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD_;
        }
        // �@MOD_�̂��Ƃ�1/fact[n-1]���v�Z����B
        // Fermat�̏��藝( a^(p-1) = 1 (mod p) )�𗘗p����B
        // a��p���݂��ɑf�ł��邱�Ƃ��K�v�����ł���_�ɒ��ӁB
        inv[n - 1] = quick_pow(fact[n - 1], MOD_ - 2);
        for (int i = n - 2; i >= 0; i--) {
            inv[i] = (inv[i + 1] * (i + 1)) % MOD_;
        }
    }
    /// <summary>
    /// n!��@MOD_�̂��ƂŎ擾����B
    /// </summary>
    /// <param name='n'>n�̒l���w�肷��B</param>
    /// <returns>n! % MOD_</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)</remarks>
    ll get(int n) {
        return fact[n];
    }
    /// <summary>
    /// 1/n!��@MOD_�̂��ƂŎ擾����B
    /// </summary>
    /// <param name='n'>n�̒l���w�肷��B</param>
    /// <returns>(n! ^ (MOD_ - 2)) % MOD_</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)</remarks>
    ll get_inv(int n) {
        return inv[n];
    }
    /// <summary>
    /// ����nPr���v�Z����B
    /// </summary>
    /// <param name='n'>nPr��n�̒l���w�肷��B</param>
    /// <param name='r'>nPr��r�̒l���w�肷��B</param>
    /// <returns>nPr % MOD_</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)</remarks>
    ll permutation(int n, int r) {
        return (fact[n] * inv[n - r]) % MOD_;
    }
    /// <summary>
    /// �g�ݍ��킹�̒ʂ萔nCr���v�Z����B
    /// </summary>
    /// <param name='n'>nCr��n�̒l���w�肷��B</param>
    /// <param name='r'>nCr��r�̒l���w�肷��B</param>
    /// <returns>nCr % MOD_</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)</remarks>
    ll combination(int n, int r) {
        return (permutation(n, r) * inv[r]) % MOD_;
    }
};
