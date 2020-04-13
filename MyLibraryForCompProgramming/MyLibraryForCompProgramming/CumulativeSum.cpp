// https://ei1333.github.io/luzhiled/snippets/dp/cumulative-sum.html

#include <vector>

class CumulativeSum1D {

private:
    //入力データa[0]～a[n-1]に対し、
    // source[0] = 0
    // source[i] = a[0] + … + a[i-1]
    //とする。
    std::vector<long long> data;

public:
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
    long long query(int start, int end) {
        return data[end] - data[start];
    }

};

class CumulativeSum2D {
private:
    // 入力データa[u,v]に対し、
    // data[u,v] = Σ_{u'<u, v'<v} a[u',v']
    // とする。
    std::vector<std::vector<long long>> data;

public:
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

    long long query(int startU, int startV, int endU, int endV) {
        return data[endU][endV] - data[endU][startV] - data[startU][endV] + data[startU][startV];
    }
};

class CumulativeSum3D {
private:
    std::vector<std::vector<std::vector<long long>>> data;

public:
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

    long long query(int startU, int startV, int startW, int endU, int endV, int endW) {
        return data[endU][endV][endW]
            - data[startU][endV][endW] + data[endU][startV][startW]
            - data[endU][startV][endW] + data[startU][endV][startW]
            - data[endU][endV][startW] + data[startU][startV][endW]
            - data[startU][startV][startW];
        return data[endU][endV][endW] - data[startU][startV][startW];
    }
};
