#include <vector>
#include <limits>

/// <summary>
/// �Z�O�����g�؁B
/// ����1�����z��(�T�C�YN)�ƏW��֐� op:(T,T)=>T �ɑ΂��A���L�̑�������s�ł���f�[�^�\���B
///   - �������cO(N)
///   - 1�_�̍X�V�cO(log N)
///   - ��Ԃ̏W��cO(log N)
/// 
/// ���W��֐��́A���� op(T1, T2, T3) = op(T1, op(T2, T3)) �𖞂����Ƃ���B���v�E�ŏ��E�ő�Ȃǂ�����ɊY������B
/// �����Q�l: https://algo-logic.info/segment-tree/
/// </summary>
/// <typeparam name="T">�z��ŊǗ�����f�[�^�^�B�ʏ��int��long long��z��Bop�͏W��֐����w�肷��Be�͒P�ʌ����w�肷��B</typeparam>
template <typename T, T(*e)(), T(*op)(T, T)>
class Segtree {

public:
    int n; // Segtree�̗t�̐��B�f�[�^��16�Ȃ�n=16, 17�Ȃ�n=32�B
    /// <summary>
    /// �Z�O�����g�؂̃f�[�^�\�����Ǘ�����z��B
    /// �T�C�Y��2*n-1�ƂȂ�B
    /// i�Ԗڂ̃Z���ɑ΂��A
    ///   - �e�Z�� �� (i-1)/2
    ///   - �q�Z�� �� 2*i+1, 2*i+2
    /// �ƂȂ�B
    /// �Q�l: https://algo-logic.info/segment-tree/
    /// </summary>
    std::vector<T> data; // �T�C�Y��2*n-1�̔z��B

    Segtree(std::vector<T> init) {
        int s = init.size();
        n = 1;
        while (s > n) n *= 2;
        data = std::vector<T>(2 * n - 1);
        for (int i = 0; i < n; ++i) {
            if (i < s)
                data[i + n - 1] = init[i];
            else
                data[i + n - 1] = e();
        }
        for (int i = n - 2; i >= 0; --i)
            data[i] = op(data[2 * i + 1], data[2 * i + 2]);
    }

    /// <summary>
    /// ����_�̒l��v�ɍX�V����B
    /// </summary>
    /// <param name="i">�X�V����_�̓Y����(0-origin)�B</param>
    /// <param name="v">�X�V����l�B</param>
    void update(int i, T v) {
        i += n - 1;
        data[i] = v;
        while (i > 0) {
            i = (i - 1) / 2; // SegmentTree�̐e�����ǂ�B
            data[i] = op(data[2 * i + 1], data[2 * i + 2]);
        }
    }

    /// <summary>
    /// ���[a,b)�̏W��l�����߂�B
    /// </summary>
    /// <param name="a">��Ԃ̊J�n�_��\��0-origin�̃C���f�b�N�X�B�v�Z��Ԃ͂��̓Y�������܂ށB0�ȏ�n�����B</param>
    /// <param name="b">��Ԃ̏I���X��\��0-origin�̃C���f�b�N�X�B�v�Z��Ԃ͂��̓Y�������܂܂Ȃ��B1�ȏ�n�ȉ��B</param>
    /// <returns></returns>
    T query(int a, int b) {
        return query_sub(a, b, 0, 0, n);
    }
    /// <summary>
    /// �ċA�����̂��߂̃T�u�N�G���B
    /// ���[a,b)�̏W��l�����߂邽�߁A�ʒu�uposi = [pl,pr)�v�ɂ���Ƃ��̏������K�肷��B
    /// posi�̋�Ԃ�[a,b)�Ɋ܂܂��ꍇ�́Adata[posi]��ԋp����B
    /// a < pl < b < pr�̂悤�Ɉꕔ�܂܂��ꍇ�́A���E�̃T�u�N�G�����ʂ��W�񂵂ĕԋp����B
    /// �S���܂܂�Ă��Ȃ��ꍇ�́A�P�ʌ�e()��ԋp����B
    /// </summary>
    T query_sub(int a, int b, int posi, int pl, int pr) {
        if (pr <= a || pl >= b) {
            return e();
        }
        else if (a <= pl && pr <= b) {
            return data[posi];
        }
        else {
            int vl = query_sub(a, b, posi * 2 + 1, pl, (pl + pr) / 2);
            int vr = query_sub(a, b, posi * 2 + 2, (pl + pr) / 2, pr);
            return op(vl, vr);
        }
    }

};

// ��Range Minimum Query
template <typename T> T e_segtree_min() { return std::numeric_limits<T>::max(); }
template <typename T> T op_segtree_min(T a, T b) { return std::min(a, b); }
template <typename T> using SegtreeMin = Segtree<T, e_segtree_min, op_segtree_min>;
// ��Range Maximum Query
template <typename T> T e_segtree_max() { return std::numeric_limits<T>::min(); }
template <typename T> T op_segtree_max(T a, T b) { return std::max(a, b); }
template <typename T> using SegtreeMax = Segtree<T, e_segtree_max, op_segtree_max>;
// ��Sum
template <typename T> T e_segtree_sum() { return 0; }
template <typename T> T op_segtree_sum(T a, T b) { return a + b; }
template <typename T> using SegtreeSum = Segtree<T, e_segtree_sum, op_segtree_sum>;
