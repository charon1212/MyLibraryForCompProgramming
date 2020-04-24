#include <vector>
#include <algorithm>

template<typename T> inline std::vector<std::vector<T>> construct_vector_2d(int arraySize1, int arraySize2, T initialValue) {
    auto r = std::vector<std::vector<T>>(arraySize1);
    for (int i = 0; i < arraySize1; i++) r[i] = std::vector<T>(arraySize2, initialValue);
    return r;
}

template<typename T> inline std::vector<std::vector<std::vector<T>>> construct_vector_3d(int arraySize1, int arraySize2, int arraySize3, T initialValue) {
    auto r = std::vector<std::vector<std::vector<T>>>(arraySize1);
    for (int i = 0; i < arraySize1; i++) {
        r[i] = std::vector<std::vector<T>>(arraySize2);
        for (int j = 0; j < arraySize2; j++) r[i][j] = std::vector<T>(arraySize3, initialValue);
    }
    return r;
}

template<typename T> inline typename std::vector<T>::iterator find_binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T value) {

    auto it = std::lower_bound(first, last, value);
    if ((*it) == value) return it;
    return end;

}