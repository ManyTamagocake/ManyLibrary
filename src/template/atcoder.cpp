#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const ll inf = 1LL<<60;
const ld pi = 3.141592653589793;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const vector<int> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};
const vector<int> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = 1; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define lla(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back
#define Yes cout << "Yes\n"
#define No cout << "No\n"
using mint = modint998244353;
const ll MOD = 998244353;
// using mint = modint1000000007;
// const ll MOD = 1000000007;
template<class T> void vcin(vector<T> &v) { for (int i = 0; i < int(v.size()); ++i) cin >> v[i];}
template<class T, class U> void vcin(vector<T> &v, vector<U> &w) { for (int i = 0; i < int(v.size()); ++i) cin >> v[i] >> w[i];}
template<class T> void vcin(vector<vector<T>> &v) { for (int i = 0; i < int(v.size()); ++i) for (int j = 0; j < int(v[i].size()); ++j) cin >> v[i][j];}
template<class T> void vcout(vector<T> &v) { for (int i = 0; i < int(v.size()); ++i) { cout << v[i] << " ";} cout << "\n";}
template<class T> void vcout(vector<vector<T>> &v) { for (int i = 0; i < int(v.size()); ++i) { for (int j = 0; j < int(v[i].size()); ++j) { cout << v[i][j] << " ";}cout << "\n";}}
template<class T, class U> bool chmax(T &a, U b) { if (a < b) {a = b; return true;} else { return false;}}
template<class T, class U> bool chmin(T &a, U b) { if (a > b) {a = b; return true;} else { return false;}}
void Init(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
}

int main(){
    Init();
}
