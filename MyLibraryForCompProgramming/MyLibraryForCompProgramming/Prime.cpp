#include<map>

// �f������
inline bool is_prime(long long x) {
    for (long long i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

// �f��������
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

// �񐔂̑������擾
inline int calc_divisor_count(long long x) {
    auto pFactor = calc_prime_factor(x);
    int ret = 1;
    for (auto it = pFactor.begin(); it != pFactor.end(); it++) { ret *= (it->second + 1); }
    return ret;
}
