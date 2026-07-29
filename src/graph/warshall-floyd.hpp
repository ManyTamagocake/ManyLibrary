#include <vector>
#include <algorithm>
using namespace std;

class WarshallFloydGraph {
private:
    const long long MAX = 1LL << 60;
    int _n;
    vector<vector<long long>> _dist;
public:
    WarshallFloydGraph(int n) : _n(n) {
        _dist.assign(n, vector<long long>(n, MAX));
        for (int i = 0; i < _n; i++) {
            _dist[i][i] = 0;
        }
    }
    void directed(int u, int v, long long w) {
        _dist[u][v] = min(_dist[u][v], w);
    }
    void edge(int u, int v, long long w) {
        directed(u, v, w);
        directed(v, u, w);
    }
    const vector<vector<long long>>& dist() {
        for (int k = 0; k < _n; k++) {
            for (int i = 0; i < _n; i++) {
                for (int j = 0; j < _n; j++) {
                    _dist[i][j] = min(_dist[i][j], _dist[i][k] + _dist[k][j]);
                }
            }
        }
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _n; j++) {
                if (_dist[i][j] == MAX) {
                    _dist[i][j] = -1;
                }
            }
        }
        return _dist;
    }
};
