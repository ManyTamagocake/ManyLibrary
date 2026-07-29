#include <vector>
using namespace std;

class EulerTour {
    private:
        int _n;
        vector<vector<int>> _adj;
        vector<int> _depth;
        vector<int> _in;
        vector<int> _out;
        vector<int> _tour;
        void _dfs(int pos, int pre, int depth) {
            _in[pos] = _tour.size();
            _tour.push_back(pos);
            _depth[pos] = depth;
            for (int nex: _adj[pos]) {
                if (nex != pre) {
                    _dfs(nex, pos, depth + 1);
                }
            }
            _out[pos] = _tour.size();
        }
    public:
        EulerTour(int n) : _n(n), _adj(n), _depth(n), _in(n), _out(n) {
            _tour.reserve(n);
        }
        void add_edge(int u, int v) {
            _adj[u].push_back(v);
            _adj[v].push_back(u);
        }
        void init(int root = 0) {
            _dfs(root, -1, 0);
        }
        const vector<int>& tour() const {
            return _tour;
        }
        int in(int v) const {
            return _in[v];
        }
        int out(int v) const {
            return _out[v];
        }
        int depth(int v) const {
            return _depth[v];
        }
};
