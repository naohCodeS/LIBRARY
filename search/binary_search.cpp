#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

// めぐる式二分探索 https://qiita.com/drken/items/97e37dd6143e33a64c8c

/**
 * judge
*/
bool isOK(const vector<ll>& a, ll index, ll key){
    if(a[index] >= key) return true;
    else return false;
}

/**
 * 二分探索 O(log n)
 * isOK(a,index,key)となるような最小のindexを求める
*/
ll binary_search(const vector<ll>& a, ll key){
    ll ng = -1;
    ll ok = (ll)a.size();
    while(abs(ok-ng)>1){
        ll mid = (ng+ok)/2;
        if(isOK(a, mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll n, key; cin>>n>>key;
    vector<ll> a(n); rep(i, n) cin>>a[i];
    cout<<binary_search(a, key)<<endl;
    return 0;
}