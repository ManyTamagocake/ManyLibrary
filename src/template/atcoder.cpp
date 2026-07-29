// include and namespace
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// consts
using ll = long long;
using ld = long double;
const ll INF = 1LL<<60;
const ld PI = M_PI;

// grid
const vector<int> dx = {0, -1, 0, 1};
const vector<int> dy = {1, 0, -1, 0};
const vector<int> dx8 = {0, -1, -1, -1, 0, 1, 1, 1};
const vector<int> dy8 = {1, 1, 0, -1, -1, -1, 0, 1};

// macro
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define Yes cout << "Yes\n"
#define No cout << "No\n"

// modulo
using mint = modint998244353;
const ll MOD = 998244353;
// using mint = modint1000000007;
// const ll MOD = 1000000007;


// input and output
template<class T>
void vcin(vector<T> &v){
    for (int i = 0; i < int(v.size()); ++i) cin >> v[i];
    return;
}

template<class T, class U>
void vcin(vector<T> &v, vector<U> &w){
    for (int i = 0; i < int(v.size()); ++i) cin >> v[i] >> w[i];
    return;
}

template<class T> void vcin(vector<vector<T>> &v){
    for (int i = 0; i < int(v.size()); ++i) for (int j = 0; j < int(v[i].size()); ++j) cin >> v[i][j];
    return;
}

template<class T> void vcout(vector<T> &v){
    for (int i = 0; i < int(v.size()); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
    return;
}

template<class T>
void vcout(vector<vector<T>> &v){
    for (int i = 0; i < int(v.size()); ++i) {
        for (int j = 0; j < int(v[i].size()); ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    } 
    return;
}

// max and min
template<class T, class U>
bool chmax(T &a, U b){
    if (a < b) {
        a = b;
        return true;
    }
    else{
        return false;
    }
}

template<class T, class U>
bool chmin(T &a, U b){
    if (a > b) {
        a = b;
        return true;
    }
    else{
        return false;
    }
}

void Init(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
}

int main(){
    Init();
}
