#include <vector>
#include <algorithm>

/// <summary>
/// 既定の初期値を持った2次元ベクトルを生成する。
/// </summary>
/// <param name="T">ベクトル要素の型を指定。</param>
/// <param name="arraySize1">2次元ベクトルの第1引数の最大値+1を指定。</param>
/// <param name="arraySize2">2次元ベクトルの第2引数の最大値+1を指定。</param>
/// <param name="initialValue">初期値を指定。</param>
/// <return>初期値initialValueを持った、サイズarraySize1×arraySize2の2次元ベクトルを返す。</return>
template<typename T> inline std::vector<std::vector<T>> construct_vector_2d(int arraySize1, int arraySize2, T initialValue) {

    auto r = std::vector<std::vector<T>>(arraySize1);
    for (int i = 0; i < arraySize1; i++) r[i] = std::vector<T>(arraySize2, initialValue);
    return r;

}

/// <summary>
/// 既定の初期値を持った3次元ベクトルを生成する。
/// </summary>
/// <param name="T">ベクトル要素の型を指定。</param>
/// <param name="arraySize1">3次元ベクトルの第1引数の最大値+1を指定。</param>
/// <param name="arraySize2">3次元ベクトルの第2引数の最大値+1を指定。</param>
/// <param name="arraySize3">3次元ベクトルの第3引数の最大値+1を指定。</param>
/// <param name="initialValue">初期値を指定。</param>
/// <return>初期値initialValueを持った、サイズarraySize1×arraySize2×arraySize3の3次元ベクトルを返す。</return>
template<typename T> inline std::vector<std::vector<std::vector<T>>> construct_vector_3d(int arraySize1, int arraySize2, int arraySize3, T initialValue) {

    auto r = std::vector<std::vector<std::vector<T>>>(arraySize1);
    for (int i = 0; i < arraySize1; i++) {
        r[i] = std::vector<std::vector<T>>(arraySize2);
        for (int j = 0; j < arraySize2; j++) r[i][j] = std::vector<T>(arraySize3, initialValue);
    }
    return r;

}

/// <summary>
/// 二分探索を用いて、要素に一致するイテレータを検索する。
/// </summary>
/// <param name="T">ベクトルに格納するデータ型を指定。</param>
/// <param name="first">検索範囲の最初のイテレータを指定。(vector.begin())</param>
/// <param name="last">検索範囲の最後のイテレータを指定。(vector.end())</param>
/// <param name="value">検索値を指定。</param>
/// <return>検索値に初めて一致する要素のイテレータを返す。存在しない場合、lastを返す。</return>
template<typename T> inline typename std::vector<T>::iterator find_binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T value) {

    auto it = std::lower_bound(first, last, value);
    if ((*it) == value) return it;
    return end;

}