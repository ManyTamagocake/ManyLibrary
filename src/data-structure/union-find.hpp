#include <vector>
using namespace std;

class UnionFind {
private:
    int _n;
    vector<int> _size;
    vector<int> _par;
    vector<int> _edge;
public:
    UnionFind(int n) : _n(n), _size(n, 1), _par(n, -1), _edge(n, 0) {}
    int root(int v) {
        if (_par[v] == -1) {
            return v;
        }
        else {
            return _par[v] = root(_par[v]);
        }
    }
    int size(int v) {
        return _size[root(v)];
    }
    bool same(int u, int v) {
        return root(u) == root(v);
    }
    bool merge(int u, int v) {
        if (root(u) == root(v)) {
            _edge[root(u)]++;
            return false;
        }
        if (_size[root(u)] > _size[root(v)]) {
            swap(u, v);
        }
        _size[root(v)] += _size[root(u)];
        _edge[root(v)] += _edge[root(u)] + 1;
        _par[root(u)] = root(v);
        return true;
    }
};
