#include <vector>
#include <queue>
using namespace std;

class bfs_graph {
    private:
        int _n;
        vector<vector<int>> _adj;
    public:
        bfs_graph(int n) : _n(n), _adj(n) {}
        void directed(int u, int v) {
            _adj[u].push_back(v);
        }
        void edge(int u, int v) {
            directed(u, v);
            directed(v, u);
        }
        vector<int> dist(int start) {
            vector<int> result(_n, -1);
            result[start] = 0;
            queue<int> que;
            que.push(start);
            while (!que.empty()) {
                int pos = que.front();
                que.pop();
                for (int nex: _adj[pos]) {
                    if (result[nex] == -1) {
                        result[nex] = result[pos] + 1;
                        que.push(nex);
                    }
                }
            }
            return result;
        }
};
