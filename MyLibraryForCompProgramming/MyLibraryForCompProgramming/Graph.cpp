// �Q�l�Fhttps://atcoder.jp/contests/abc160/submissions/11280884

#include <vector>

/// <summary>
/// �O���t�̍\����\���N���X
/// </summary>
/// <example>
/// ���[�v�̃T���v���F
/// <code>
/// Graph g; //g�ɕӂ�o�^���鏈���͏ȗ��B
/// int u = 3; //�n�_u
/// for(int e = g.head[u]; e; e = g.next[e]){
///     // �n�_u����o�Ă���ӂɂ��ă��[�v����B
///     // g.from[e]�Ŏn�_���Ag.to[e]�ŏI�_���擾�ł���B
/// }
/// </code>
/// </example>
class Graph {
private:
    // �o�^����Ă���ӂ̑�����\���B
    int cnt;

public:
    // head[v]�́A���_v����o�Ă���ӂ�edgeID�̂����A�ő�̒l��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> head;
    // from[e]�́A��ID��e�̕ӂ̎n�_��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> from;
    // to[e]�́A��ID��e�̕ӂ̏I�_��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> to;
    // next[e]�́AedgeID��e�̕ӂ̎n�_u����o�Ă���ӂ̂����AedgeID��e�̎��ɏ������ӂ�edgeID��\���B
    // �ł��������ꍇ�́A0��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> next;

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^�B
    /// ���̃R���X�g���N�^�ō쐬�����C���X�^���X�̊֐��͂قƂ�Ǘ��p�ł��Ȃ����ߒ��ӁB
    /// </summary>
    Graph() {
        head = std::vector<int>(0);
        to = std::vector<int>(0);
        from = std::vector<int>(0);
        next = std::vector<int>(0);
        cnt = 0;
    }

    /// <summary>
    /// �R���X�g���N�^�B
    /// </summary>
    /// <param name='vertexMax'>���_�̍ő�o�^�����w�肷��BGraph.resize�Ōォ��ύX�ł���B</param>
    /// <param name='edgeMax'>�ӂ̍ő�o�^�����w�肷��BGraph.resize�Ōォ��ύX�ł���B</param>
    Graph(int vertexMax, int edgeMax) {
        edgeMax++;
        head = std::vector<int>(vertexMax, 0);
        to = std::vector<int>(edgeMax, 0);
        from = std::vector<int>(edgeMax, 0);
        next = std::vector<int>(edgeMax, 0);
        cnt = 0;
    }

    /// <summary>
    /// �L���O���t�̕ӂ�o�^����B
    /// </summary>
    /// <param name='from_'>�ӂ̎n�_��0����n�܂鐮���Ŏw�肷��B</param>
    /// <param name='to_'>�ӂ̏I�_��0����n�܂鐮���Ŏw�肷��B</param>
    void add_directed_edge(int from_, int to_) {
        // �ӂ̐���1�𑫂��B��������̒l���A���ꂩ��o�^����ӂ�edgeID�ƂȂ�B
        cnt++;
        // from��o�^����B
        from[cnt] = from_;
        // to��o�^����B
        to[cnt] = to_;
        // ���̕ӂ̎���edgeID���������ӂ�edgeID�́Ahead[from_]�ɓo�^����Ă���B
        next[cnt] = head[from_];
        // �n�_from_����o�Ă���ӂ�edgeID�ōő�̂��̂́A���o�^����cnt�B
        head[from_] = cnt;
    }

    /// <summary>
    /// �����O���t�̕ӂ�o�^����B
    /// </summary>
    /// <param name='from_'>�ӂ̎n�_��0����n�܂鐮���Ŏw�肷��B</param>
    /// <param name='to_'>�ӂ̏I�_��0����n�܂鐮���Ŏw�肷��B</param>
    void add_undirected_edge(int from_, int to_) {
        add_directed_edge(from_, to_);
        add_directed_edge(to_, from_);
    }

    /// <summary>
    /// �o�^���ꂽ�ӂ̑������擾����B
    /// </summary>
    /// <returns>�o�^���ꂽ�ӂ̑����B</returns>
    int get_edge_length() {
        return cnt;
    }

    /// <summary>
    /// ���_�ƕӂ̓o�^���̏����ύX����B
    /// </summary>
    /// <param name='vertexMax'>���_�̍ő�o�^�����w�肷��B</param>
    /// <param name='edgeMax'>�ӂ̍ő�o�^�����w�肷��B</param>
    void resize(int vertexMax, int edgeMax) {
        edgeMax++;
        head.resize(vertexMax);
        to.resize(edgeMax);
        from.resize(edgeMax);
        next.resize(edgeMax);
    }

};

/// <summary>
/// �d�ݕt���O���t�̍\����\���N���X
/// </summary>
/// <param name="T">�d�݂�\���f�[�^�^���w��B</param>
template<typename T> class WeightedGraph {
private:
    // �o�^����Ă���ӂ̑�����\���B
    int cnt;

public:
    // head[v]�́A���_v����o�Ă���ӂ�edgeID�̂����A�ő�̒l��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> head;
    // from[e]�́A��ID��e�̕ӂ̎n�_��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> from;
    // to[e]�́A��ID��e�̕ӂ̏I�_��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> to;
    // next[e]�́AedgeID��e�̕ӂ̎n�_u����o�Ă���ӂ̂����AedgeID��e�̎��ɏ������ӂ�edgeID��\���B
    // �ł��������ꍇ�́A0��\���B
    // edgeID��1����n�܂�A�o�^���ɍ̔Ԃ����B
    std::vector<int> next;
    // weight[e]�́A��ID��e�̕ӂ̏d�݂�\���B
    std::vector<T> weight;

    /// <summary>
    /// �f�t�H���g�R���X�g���N�^�B
    /// ���̃R���X�g���N�^�ō쐬�����C���X�^���X�̊֐��͂قƂ�Ǘ��p�ł��Ȃ����ߒ��ӁB
    /// </summary>
    WeightedGraph() {
        head = std::vector<int>(0);
        to = std::vector<int>(0);
        from = std::vector<int>(0);
        next = std::vector<int>(0);
        weight = std::vector<int>(0);
        cnt = 0;
    }

    /// <summary>
    /// �R���X�g���N�^�B
    /// </summary>
    /// <param name='vertexMax'>���_�̍ő�o�^�����w�肷��BGraph.resize�Ōォ��ύX�ł���B</param>
    /// <param name='edgeMax'>�ӂ̍ő�o�^�����w�肷��BGraph.resize�Ōォ��ύX�ł���B</param>
    WeightedGraph(int vertexMax, int edgeMax) {
        edgeMax++;
        head = std::vector<int>(vertexMax, 0);
        to = std::vector<int>(edgeMax, 0);
        from = std::vector<int>(edgeMax, 0);
        next = std::vector<int>(edgeMax, 0);
        weight = std::vector<int>(edgeMax, 0);
        cnt = 0;
    }

    /// <summary>
    /// �L���O���t�̕ӂ�o�^����B
    /// </summary>
    /// <param name='from_'>�ӂ̎n�_��0����n�܂鐮���Ŏw�肷��B</param>
    /// <param name='to_'>�ӂ̏I�_��0����n�܂鐮���Ŏw�肷��B</param>
    /// <param name='weight_'>�ӂ̏d�݂��w�肷��B</param>
    void add_directed_edge(int from_, int to_, T weight_) {
        // �ӂ̐���1�𑫂��B��������̒l���A���ꂩ��o�^����ӂ�edgeID�ƂȂ�B
        cnt++;
        // from��o�^����B
        from[cnt] = from_;
        // to��o�^����B
        to[cnt] = to_;
        // ���̕ӂ̎���edgeID���������ӂ�edgeID�́Ahead[from_]�ɓo�^����Ă���B
        next[cnt] = head[from_];
        // �n�_from_����o�Ă���ӂ�edgeID�ōő�̂��̂́A���o�^����cnt�B
        head[from_] = cnt;
        // �d�݂�o�^����B
        weight[cnt] = weight_;
    }

    /// <summary>
    /// �����O���t�̕ӂ�o�^����B
    /// </summary>
    /// <param name='from_'>�ӂ̎n�_��0����n�܂鐮���Ŏw�肷��B</param>
    /// <param name='to_'>�ӂ̏I�_��0����n�܂鐮���Ŏw�肷��B</param>
    /// <param name='weight_'>�ӂ̏d�݂��w�肷��B</param>
    void add_undirected_edge(int from_, int to_, T weight_) {
        add_directed_edge(from_, to_, weight_);
        add_directed_edge(to_, from_, weight_);
    }

    /// <summary>
    /// �o�^���ꂽ�ӂ̑������擾����B
    /// </summary>
    /// <returns>�o�^���ꂽ�ӂ̑����B</returns>
    int get_edge_length() {
        return cnt;
    }

    /// <summary>
    /// ���_�ƕӂ̓o�^���̏����ύX����B
    /// </summary>
    /// <param name='vertexMax'>���_�̍ő�o�^�����w�肷��B</param>
    /// <param name='edgeMax'>�ӂ̍ő�o�^�����w�肷��B</param>
    void resize(int vertexMax, int edgeMax) {
        edgeMax++;
        head.resize(vertexMax);
        to.resize(edgeMax);
        from.resize(edgeMax);
        next.resize(edgeMax);
    }

};
