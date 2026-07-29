#include <vector>
#include <utility>
#include <queue>
using namespace std;

class dijkstra_graph {
    private:
        int _n;
        vector<vector<pair<int, long long>>> _adj;
    public:
        dijkstra_graph(int n) : _n(n), _adj(n) {}
        void directed(int u, int v, long long w) {
            _adj[u].push_back(make_pair(v, w));
        }
        void edge(int u, int v, long long w) {
            directed(u, v, w);
            directed(v, u, w);
        }
        vector<long long> dist(int start) {
            vector<long long> result(_n, -1);
            result[start] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
            que.push(make_pair(0, start));
            while (!que.empty()) {
                pair<long long, int> current = que.top();
                int current_pos = current.second;
                long long current_dist = current.first;
                que.pop();
                for (pair<int, long long> edge: _adj[current_pos]) {
                    int next_pos = edge.first;
                    long long next_dist = current_dist + edge.second;
                    if (result[next_pos] == -1 || result[next_pos] > next_dist) {
                        result[next_pos] = next_dist;
                        que.push(make_pair(next_dist, next_pos));
                    }
                }
            }
            return result;
        }
};
