#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

// 座標圧縮
template <typename T>
pair<vector<T>, vector<T>> compress(const vector<T> &vec) {
    vector<T> inv = vec;
    sort(inv.begin(), inv.end());
    inv.erase(unique(inv.begin(), inv.end()), inv.end());
    vector<T> compressed((int)vec.size());
    for (int i = 0; i < (int)vec.size(); i++) {
        compressed[i] = lower_bound(inv.begin(), inv.end(), vec[i]) - inv.begin();
    }
    return {inv, compressed};
}

int main() {
    // ABC036C
    ll N; cin >> N;
    vector<ll> a(N); rep(i, N) cin >> a[i];
    auto [inv, compressed] = compress(a);
    for (auto x : compressed) cout << x << endl;
    // for (auto x : compressed) cout << inv[x] << endl; // 元の値を復元
    return 0;
}