#include <vector>

/// <summary>
/// @NoUnitTest
/// Union-Find���Ǘ�����N���X�B
/// �����Q�l�Fhttps://ei1333.github.io/luzhiled/snippets/structure/union-find.html
/// �{�N���X�̃R�����g�ɂ����āA�ux�����Ƃ���؁v���ux�؁v�ƌĂԁB
/// </summary>
/// <typeparam name="T">�Ǘ��Ώۂ̐��l�f�[�^�^�B�ʏ��int���w��B</typeparam>
template <typename T = int>
class UnionFind {
public:
    // �e�v�f�̐e�E���ł��邩�E�W���T�C�Y�����ׂĊǗ�����f�[�^�B
    // ���̒l�ł���΁A���ł��邱�Ƃ�\���B
    // ���̑傫���́A���������Ƃ���UnionFind�؂̃T�C�Y��\���B
    // ���̒l�ł���΁A�e��index��\���B
    std::vector<T> data;

    UnionFind(T size) {
        data = std::vector<T>(size, -1); // �ŏ��͑S�č��ŁA���̏W���T�C�Y��1�B
    }

    /// <summary>
    /// �v�fx�̍���index (0-origin)���擾����B
    /// x�����ł���΁Ax��ԋp����B
    /// </summary>
    T root(T x) {
        if (data[x] < 0) return x; // ���ł���΁A������Index��ԋp����B
        return (data[x] = root(data[x])); // ���łȂ���΁A�e�̍���Index��ԋp���A���̒l���L������B
    }

    /// <summary>
    /// �v�fx�̑�����؂Ɨv�fy�̑�����؂�ڑ�����B
    /// </summary>
    /// <returns>�ڑ������{�����ꍇ��true�A���{���Ȃ��ix��y�����X�����؂ɑ����Ă����j�ꍇ��false�B</returns>
    bool merge(T x, T y) {
        x = root(x);
        y = root(y);
        if (x == y) return false; // ���������ꍇ�́A�������Ȃ�
        if (data[x] > data[y]) std::swap(x, y); // x�̂ق����T�C�Y���������ꍇ�A��������B����ŁAx�̂ق����T�C�Y���傫���Ȃ�B
        // y�؂��Ax�؂ɂȂ���B
        data[x] += data[y]; // x�؂̃T�C�Y��y�؂̃T�C�Y�𑫂��B (x=-6) + (y=-3) -> (x=-9) �݂����ɁB
        data[y] = x; // y�؂̍���x�؂̍��ɐڑ�����B
        return true;
    }

    /// <summary>
    /// �v�fx,y�������؂ɑ����邩���肷��B
    /// </summary>
    bool same(T x, T y) {
        return root(x) == root(y);
    }

    /// <summary>
    /// �v�fx�̑�����؂̏W���T�C�Y���擾����B
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    T size(T x) {
        return -(data[root(x)]); // x�̍���data�l���A�u(-1)*(x�؂̃T�C�Y)�v�Ȃ̂ŁA�����(-1)��������B
    }

};