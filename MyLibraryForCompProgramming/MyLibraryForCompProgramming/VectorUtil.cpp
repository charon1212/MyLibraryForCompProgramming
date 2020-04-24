#include <vector>
#include <algorithm>

/// <summary>
/// ����̏����l��������2�����x�N�g���𐶐�����B
/// </summary>
/// <param name="T">�x�N�g���v�f�̌^���w��B</param>
/// <param name="arraySize1">2�����x�N�g���̑�1�����̍ő�l+1���w��B</param>
/// <param name="arraySize2">2�����x�N�g���̑�2�����̍ő�l+1���w��B</param>
/// <param name="initialValue">�����l���w��B</param>
/// <return>�����linitialValue���������A�T�C�YarraySize1�~arraySize2��2�����x�N�g����Ԃ��B</return>
template<typename T> inline std::vector<std::vector<T>> construct_vector_2d(int arraySize1, int arraySize2, T initialValue) {

    auto r = std::vector<std::vector<T>>(arraySize1);
    for (int i = 0; i < arraySize1; i++) r[i] = std::vector<T>(arraySize2, initialValue);
    return r;

}

/// <summary>
/// ����̏����l��������3�����x�N�g���𐶐�����B
/// </summary>
/// <param name="T">�x�N�g���v�f�̌^���w��B</param>
/// <param name="arraySize1">3�����x�N�g���̑�1�����̍ő�l+1���w��B</param>
/// <param name="arraySize2">3�����x�N�g���̑�2�����̍ő�l+1���w��B</param>
/// <param name="arraySize3">3�����x�N�g���̑�3�����̍ő�l+1���w��B</param>
/// <param name="initialValue">�����l���w��B</param>
/// <return>�����linitialValue���������A�T�C�YarraySize1�~arraySize2�~arraySize3��3�����x�N�g����Ԃ��B</return>
template<typename T> inline std::vector<std::vector<std::vector<T>>> construct_vector_3d(int arraySize1, int arraySize2, int arraySize3, T initialValue) {

    auto r = std::vector<std::vector<std::vector<T>>>(arraySize1);
    for (int i = 0; i < arraySize1; i++) {
        r[i] = std::vector<std::vector<T>>(arraySize2);
        for (int j = 0; j < arraySize2; j++) r[i][j] = std::vector<T>(arraySize3, initialValue);
    }
    return r;

}

/// <summary>
/// �񕪒T����p���āA�v�f�Ɉ�v����C�e���[�^����������B
/// </summary>
/// <param name="T">�x�N�g���Ɋi�[����f�[�^�^���w��B</param>
/// <param name="first">�����͈͂̍ŏ��̃C�e���[�^���w��B(vector.begin())</param>
/// <param name="last">�����͈͂̍Ō�̃C�e���[�^���w��B(vector.end())</param>
/// <param name="value">�����l���w��B</param>
/// <return>�����l�ɏ��߂Ĉ�v����v�f�̃C�e���[�^��Ԃ��B���݂��Ȃ��ꍇ�Alast��Ԃ��B</return>
template<typename T> inline typename std::vector<T>::iterator find_binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T value) {

    auto it = std::lower_bound(first, last, value);
    if ((*it) == value) return it;
    return end;

}