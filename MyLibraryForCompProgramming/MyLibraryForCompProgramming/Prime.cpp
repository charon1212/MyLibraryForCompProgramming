// �Q�l�Fhttps://ei1333.github.io/luzhiled/snippets/math/prime-factor.html

#include<map>

/// <summary>
/// ���鐔���f���ł��邩�𔻒肷��B
/// </summary>
/// <param name='x'>���ׂ�Ώۂ̐��l���w��B</param>
/// <returns>�f���Ȃ�true�A�f���łȂ����false��Ԃ��B�Ȃ��Ax=1�̏ꍇ��true�ƂȂ�B</returns>
/// <remarks>�v�Z�I�[�_�[��O(��N)</remarks>
inline bool is_prime(long long x) {
    for (long long i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

/// <summary>
/// ���鐔��f������������B
/// </summary>
/// <param name='x'>�f������������Ώۂ̐��l���w��B</param>
/// <returns>
/// �f���Ƃ��̎w�����֘A�t����A�z�z���Ԃ��B
/// �Ⴆ�΁Ax=12�̏ꍇ�A�߂�l�̘A�z�z��m��m[2]=2,m[3]=1�ƂȂ�B
/// </returns>
/// <remarks>�v�Z�I�[�_�[��O(��N)�Bx��17���Ŗ�1�b�B�i���R�����n�ɂ�邪�A���Z�v���̖ڈ��l�Ƃ��āB�j</remarks>
inline std::map<long long, int> calc_prime_factor(long long x) {
    std::map<long long, int> ret;
    // 2,3���ɂ��B
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
        // 6n+1��6n+5�݂̂�ΏۂƂ��邽�߂̍X�V��
        factor += sw ? 2 : 4;
        sw != sw;
    }
    if (x != 1) ret[x] = 1;
    return ret;
}

/// <summary>
/// ���鐔�̖񐔂̑������擾����B
/// </summary>
/// <param name='x'>�񐔂̑����𒲂ׂ�Ώۂ��w��B</param>
/// <returns>�񐔂̑����B</returns>
/// <remarks>�v�Z�I�[�_�[��calc_prime_factor�Ɠ����x�B(O(��N))</remarks>
inline int calc_divisor_count(long long x) {
    auto pFactor = calc_prime_factor(x);
    int ret = 1;
    for (auto it = pFactor.begin(); it != pFactor.end(); it++) { ret *= (it->second + 1); }
    return ret;
}
