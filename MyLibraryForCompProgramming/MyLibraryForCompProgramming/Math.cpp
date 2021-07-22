/// <summary>
/// @NoUnitTest
/// 組み合わせbit列を表す数値を取得する。
/// </summary>
/// <return>
/// 前の結果を次の引数に代入すると、例えば、
/// 111 → 1011 → 1101 → 1110 → 10011 → 10101 → … → 11100 → 100011 → … 111000 → 1000011 → … (2進数表現)
/// となる。
/// </return>
/// <example>
/// ループのサンプル。この例では2進数表現で、111～11100の組み合わせを取得する。：
/// int n = 5, k = 3;
/// for (int bit = (1 << k) - 1; bit < (1 << n); bit = next_combination(bit)) {
///     // (何らかの処理)
/// }
/// <code>
/// 
/// </code>
/// </example>
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
