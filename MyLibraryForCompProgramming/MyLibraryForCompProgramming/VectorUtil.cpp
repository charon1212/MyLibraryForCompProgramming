#include <vector>
#include <algorithm>

template<typename T> inline std::vector<std::vector<T>> construct_vector_2d(int n, int m, T initialValue) {
    auto r = std::vector<std::vector<T>>(n);
    for (int i = 0; i < m; i++) r[i] = std::vector<T>(m, initialValue);
    return r;
}

template<typename T> inline std::vector<std::vector<std::vector<T>>> construct_vector_3d(int n, int m, int l, T initialValue) {
    auto r = std::vector<std::vector<std::vector<T>>>(n);
    for (int i = 0; i < n; i++) {
        r[i] = std::vector<std::vector<T>>(m);
        for (int j = 0; j < m; j++) r[i][j] = std::vector<T>(l, initialValue);
    }
    return r;
}

template<typename T> inline typename std::vector<T>::iterator find_binary_search(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, T value) {

    auto it = std::lower_bound(begin, end, value);
    if ((*it) == value) return it;
    return end;

}