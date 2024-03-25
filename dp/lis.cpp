#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 最長増加部分列問題（LIS:Longest Increasing Subsequence）O(n log n)
*/
ll lis(const vector<ll> &a) {
    const ll INF = 1LL<<62;
    ll n = (ll)a.size();
    vector<ll> dp(n+1, INF);
    rep(i,n) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main(){
    ll n; cin>>n;
    vector<ll> a(n); rep(i,n)cin>>a[i];
    cout<<lis(a)<<endl;
    return 0;
}