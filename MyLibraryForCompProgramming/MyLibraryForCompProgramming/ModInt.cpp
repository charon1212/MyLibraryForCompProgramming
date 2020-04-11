// 参考：https://ei1333.github.io/luzhiled/snippets/math/mod-int.html

#include<iostream>

/// <summary>
/// 剰余類環(ある数で割った数値で議論するやつ)を扱うクラス。
/// </summary>
/// <param name="MOD_">法数を指定する。int型の範囲内の正の素数を指定すること。</param>

template <unsigned MOD_> struct ModInt {

private:
    // MOD_で割った余りを表す。数値データの本体。
    unsigned value;

public:
    // <<<< GET >>>>
    unsigned get() const {
        return value;
    }

    // <<<< CONSTRUCTOR >>>>
    ModInt() { value = 0; }
    ModInt(const ModInt& y) { value = y.value; }
    ModInt(int y) {
        if (y < 0 || MOD_ <= y) y %= (int)MOD_;
        if (y < 0) y += MOD_;
        value = y;
    }
    ModInt(unsigned y) {
        if (MOD_ <= y) {
            value = y % MOD_;
        }
        else {
            value = y;
        }
    }
    ModInt(long long y) {
        if (y < 0 || MOD_ <= y) y %= MOD_;
        if (y < 0) y += MOD_;
        value = y;
    }
    ModInt(unsigned long long y) {
        if (MOD_ <= y) {
            value = y % MOD_;
        }
        else {
            value = y;
        }
    }

    // <<<< REPRESENTATION OF NAN >>>>
    void undef() { value = (unsigned)-1; }
    bool is_nan() const { return value == (unsigned)-1; }

    // <<<< ARITHMETIC >>>>
    ModInt& operator+=(const ModInt y) { if ((value += y.value) >= MOD_) value -= MOD_; return *this; }
    ModInt& operator-=(const ModInt y) { if ((value -= y.value) & (1u << 31)) value += MOD_; return *this; }
    ModInt& operator*=(const ModInt y) { value = (unsigned long long)value * y.value % MOD_; return *this; }
    ModInt& operator/=(const ModInt y) { value = (unsigned long long)value * y.inv().value % MOD_; return *this; }
    ModInt operator +(const ModInt y) const { return ModInt(*this) += y; }
    ModInt operator -(const ModInt y) const { return ModInt(*this) -= y; }
    ModInt operator *(const ModInt y) const { return ModInt(*this) *= y; }
    ModInt operator /(const ModInt y) const { return ModInt(*this) *= y.inverse(); }

    // <<<< COMPARISON OPERATOR >>>>
    bool operator<(const ModInt y) const { return value < y.value; }
    bool operator==(const ModInt y) const { return value == y.value; }
    bool operator!=(const ModInt y) const { return value != y.value; }

    // <<<< OTHER METHOD >>>>
    ModInt operator-() const { return (value ? MOD_ - value : 0); }
    ModInt inverse() const {
        return quick_pow(MOD_ - 2);
    }
    ModInt quick_pow(long long y) const {
        ModInt b = *this;
        ModInt r = 1;
        if (y < 0) { b = b.inverse(); y = -y; }
        for (; y; y >>= 1) {
            if (y & 1) r *= b;
            b *= b;
        }
        return r;
    }

    // <<<< I/O STREAM >>>>
    friend std::ostream& operator <<(std::ostream& os, const ModInt& p) { return os << p.value; }
    friend std::istream& operator >>(std::istream& is, ModInt& a) {
        long long t;
        is >> t;
        a = ModInt<MOD_>(t);
        return (is);
    }

};