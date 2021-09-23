/// <summary>
/// @NoUnitTest
/// �x���Z�O�����g��
/// 
/// �����Q�l: https://algo-logic.info/segment-tree/
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T, T(*e)(), T(*op)(T, T)>
class LazySegtree {

public:
    int n; // Segtree�̗t�̐��B�f�[�^��16�Ȃ�n=16, 17�Ȃ�n=32�B
    std::vector<T> data; // �T�C�Y��2*n-1�̔z��B�v�Z�l�{�́B
    std::vector<T> lazy; // �x���]���p�B�X�V�f�[�^���ꎞ�I�ɓ���Ă����B

    LazySegtree(int size) {
        n = 1;
        while (n < size) n *= 2;
        data = std::vector<T>(2 * n - 1);
        lazy = std::vector<T>(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; i++) {
            data[i] = e();
            lazy[i] = e();
        }
    }

    init(std::vector<T> arr) {
        // data��[n-1,2*n-1)�ɁA�w�肵���f�[�^������B
        for (int i = 0; i < arr.size(); i++) data[i + n - 1] = arr[i];
        // [0,n-1)�ɂ��āA�v�Z���Ȃ����B
        for (int i = n - 2; i >= 0; --i)
            data[i] = op(data[2 * i + 1], data[2 * i + 2]);
        // �x���]���p�̍X�V�f�[�^�͂��ׂď���������B
        for (int i = 0; i < 2 * n - 1; i++) lazy[i] = e();
    }

    void eval(int k) {
        if (lazy[k] == e()) return;
        if (k < n - 1) { // �q��������΁A�`�d����B
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // ���g�̍ĕ]��
        data[k] = lazy[k];
        lazy[k] = e();
    }

    void update(int a, int b, T x) {

    }

};
