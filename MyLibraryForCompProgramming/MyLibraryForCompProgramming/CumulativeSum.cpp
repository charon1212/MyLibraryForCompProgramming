// https://ei1333.github.io/luzhiled/snippets/dp/cumulative-sum.html

#include <vector>

/// <summary>
/// 1�����ݐϘa�������N���X�B
/// </summary>
class CumulativeSum1D {

private:
    //���̓f�[�^a[0]�`a[n-1]�ɑ΂��A
    // source[0] = 0
    // source[k] = a[0] + �c + a[k-1]
    std::vector<long long> data;

public:
    /// <summary>
    /// �R���X�g���N�^
    /// 1�����ݐϘa�̂��߂̏������������{����B
    /// </summary>
    /// <param name='source'>�ݐϘa���Ƃ�Ώۂ̐�����w�肷��B</param>
    /// <remarks>�v�Z�I�[�_�[��O(N)�B�iN��source�̔z�񒷁j</remarks>
    CumulativeSum1D(std::vector<long long> source) {
        int n = source.size();
        data = std::vector<long long>(n + 1);
        data[0] = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += source[i];
            data[i + 1] = sum;
        }
    }

    /// <summary>
    /// �ݐϘa���v�Z����B
    /// </summary>
    /// <param name='start'>�ݐϘa���Ƃ��Ԃ̍ŏ��̓Y�������A0����n�܂鐮���Ŏw�肷��B
    /// 0 &lt;= start &lt;= N�Ŏw�肷��B(N�̓R���X�g���N�^�Ŏw�肵��source�̔z�񒷁B)</param>
    /// <param name='end'>�ݐϘa���Ƃ��Ԃ̍Ō�̓Y����+1���A0����n�܂鐮���Ŏw�肷��B
    /// 0 &lt;= end &lt;= N�Ŏw�肷��B(N�̓R���X�g���N�^�Ŏw�肵��source�̔z�񒷁B)</param>
    /// <returns>�R���X�g���N�^�Ŏw�肵������source[i]�ɑ΂��A
    /// source[start] + �c + source[end - 1]��Ԃ��B</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)�B</remarks>
    long long query(int start, int end) {
        return data[end] - data[start];
    }

};

/// <summary>
/// 2�����ݐϘa�������N���X�B
/// </summary>
class CumulativeSum2D {
private:
    // ���̓f�[�^a[u][v]�ɑ΂��A
    // data[u][v] = ��_{u'<u, v'<v} a[u'][v']
    std::vector<std::vector<long long>> data;

public:
    /// <summary>
    /// �R���X�g���N�^
    /// 2�����ݐϘa�̂��߂̏������������{����B
    /// </summary>
    /// <param name='source'>�ݐϘa���Ƃ�Ώۂ̐�����w�肷��B</param>
    /// <remarks>�v�Z�I�[�_�[��O(H�~W)�B�iH,D�͂��ꂼ��Asource�z��̑�1�����A��2�����Ɋւ���z�񒷁j</remarks>
    CumulativeSum2D(std::vector<std::vector<long long>> source) {
        int h, w;
        h = source.size();
        w = source[0].size();
        data = std::vector<std::vector<long long>>(h + 1);
        for (int i = 0; i <= h; i++) data[i] = std::vector<long long>(w + 1);
        for (int u = 1; u <= h; u++) {
            for (int v = 1; v <= w; v++) {
                data[u][v] = data[u - 1][v] - data[u - 1][v - 1] + data[u][v - 1] + source[u - 1][v - 1];
            }
        }
    }

    /// <summary>
    /// �ݐϘa���v�Z����B
    /// </summary>
    /// <param name='startU'>�ݐϘa���Ƃ��Ԃ́A��1�����̍ŏ��l���w�肷��B�͈͂�0&lt;=startU&lt;=H�Ŏw�肷��B�iH�̓R���X�g���N�^�Ŏw�肵��source�̑�1�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='startV'>�ݐϘa���Ƃ��Ԃ́A��2�����̍ŏ��l���w�肷��B�͈͂�0&lt;=startV&lt;=W�Ŏw�肷��B�iW�̓R���X�g���N�^�Ŏw�肵��source�̑�2�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='endU'>�ݐϘa���Ƃ��Ԃ́A��1�����̍ő�l+1���w�肷��B�͈͂�0&lt;=endU&lt;=H�Ŏw�肷��B�iH�̓R���X�g���N�^�Ŏw�肵��source�̑�1�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='endV'>�ݐϘa���Ƃ��Ԃ́A��2�����̍ő�l+1���w�肷��B�͈͂�0&lt;=endV&lt;=W�Ŏw�肷��B�iW�̓R���X�g���N�^�Ŏw�肵��source�̑�2�����ɂ��Ă̔z�񒷁B�j</param>
    /// <returns>�R���X�g���N�^�Ŏw�肵��source[i][j]�ɑ΂��AstartU &lt;= i &lt; endU�AstartV &lt;= j &lt; endV�𖞂���source[i][j]�̘a��Ԃ��B</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)�B</remarks>
    long long query(int startU, int startV, int endU, int endV) {
        return data[endU][endV] - data[endU][startV] - data[startU][endV] + data[startU][startV];
    }
};

/// <summary>
/// 3�����ݐϘa�������N���X�B
/// </summary>
class CumulativeSum3D {
private:
    // ���̓f�[�^a[u][v][w]�ɑ΂��A
    // data[u][v][w] = ��_{u'<u, v'<v,w'<w} a[u'][v'][w']
    std::vector<std::vector<std::vector<long long>>> data;

public:
    /// <summary>
    /// �R���X�g���N�^
    /// 3�����ݐϘa�̂��߂̏������������{����B
    /// </summary>
    /// <param name='source'>�ݐϘa���Ƃ�Ώۂ̐�����w�肷��B</param>
    /// <remarks>�v�Z�I�[�_�[��O(H�~W�~D)�B�iH,W,D�͂��ꂼ��Asource�z��̑�1�����A��2�����A��3�����Ɋւ���z�񒷁j</remarks>
    CumulativeSum3D(std::vector<std::vector<std::vector<long long>>> source) {
        int h, w, d;
        h = source.size();
        w = source[0].size();
        d = source[0][0].size();
        data = std::vector<std::vector<std::vector<long long>>>(h + 1);
        for (int i = 0; i <= h; i++) {
            data[i] = std::vector<std::vector<long long>>(w + 1);
            for (int j = 0; j <= w; j++) data[i][j] = std::vector<long long>(d + 1);
        }
        for (int u = 1; u <= h; u++) {
            for (int v = 1; v <= w; v++) {
                for (int x = 1; x <= d; x++) {
                    data[u][v][x] = data[u - 1][v][x] - data[u - 1][v - 1][x]
                        + data[u][v - 1][x] - data[u][v - 1][x - 1]
                        + data[u][v][x - 1] - data[u - 1][v][x - 1]
                        + data[u - 1][v - 1][x - 1] + source[u - 1][v - 1][x - 1];
                }
            }
        }
    }

    /// <summary>
    /// �ݐϘa���v�Z����B
    /// </summary>
    /// <param name='startU'>�ݐϘa���Ƃ��Ԃ́A��1�����̍ŏ��l���w�肷��B�͈͂�0&lt;=startU&lt;=H�Ŏw�肷��B�iH�̓R���X�g���N�^�Ŏw�肵��source�̑�1�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='startV'>�ݐϘa���Ƃ��Ԃ́A��2�����̍ŏ��l���w�肷��B�͈͂�0&lt;=startV&lt;=W�Ŏw�肷��B�iW�̓R���X�g���N�^�Ŏw�肵��source�̑�2�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='startW'>�ݐϘa���Ƃ��Ԃ́A��2�����̍ŏ��l���w�肷��B�͈͂�0&lt;=startW&lt;=W�Ŏw�肷��B�iD�̓R���X�g���N�^�Ŏw�肵��source�̑�3�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='endU'>�ݐϘa���Ƃ��Ԃ́A��1�����̍ő�l+1���w�肷��B�͈͂�0&lt;=endU&lt;=H�Ŏw�肷��B�iH�̓R���X�g���N�^�Ŏw�肵��source�̑�1�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='endV'>�ݐϘa���Ƃ��Ԃ́A��2�����̍ő�l+1���w�肷��B�͈͂�0&lt;=endV&lt;=W�Ŏw�肷��B�iW�̓R���X�g���N�^�Ŏw�肵��source�̑�2�����ɂ��Ă̔z�񒷁B�j</param>
    /// <param name='endW'>�ݐϘa���Ƃ��Ԃ́A��2�����̍ő�l+1���w�肷��B�͈͂�0&lt;=endW&lt;=W�Ŏw�肷��B�iD�̓R���X�g���N�^�Ŏw�肵��source�̑�3�����ɂ��Ă̔z�񒷁B�j</param>
    /// <returns>�R���X�g���N�^�Ŏw�肵��source[i][j][k]�ɑ΂��AstartU &lt;= i &lt; endU�AstartV &lt;= j &lt; endV�AstartW &lt;= k &lt; endW�𖞂���source[i][j][k]�̘a��Ԃ��B</returns>
    /// <remarks>�v�Z�I�[�_�[��O(1)�B</remarks>
    long long query(int startU, int startV, int startW, int endU, int endV, int endW) {
        return data[endU][endV][endW]
            - data[startU][endV][endW] + data[endU][startV][startW]
            - data[endU][startV][endW] + data[startU][endV][startW]
            - data[endU][endV][startW] + data[startU][startV][endW]
            - data[startU][startV][startW];
        return data[endU][endV][endW] - data[startU][startV][startW];
    }
};
