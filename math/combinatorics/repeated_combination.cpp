#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 重複組み合わせ O(nm)
 * dp[i+1][j] := i番目までからj個選ぶ組み合わせの総数
 * dp[i+1][j] - dp[i+1][j-1] = dp[i][j] - (j-a[i]!=0?dp[i][j-1-a[i]]:0)
 * @param a a[i]:=i番目の個数
 * @param m m個選ぶ
 * @return n種類の品物（i番目はa[i]個ある）からm個選ぶ組み合わせ総数
*/
ll repeated_combination(const vector<ll>& a, ll m){
    ll n = (ll)a.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    rep(i,n+1) dp[i][0] = 1;
    rep(i,n)
        for(ll j=1; j<=m; j++)
            dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - (j-1-a[i]<0?0:dp[i][j-1-a[i]]);
    return dp[n][m];
}

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    cout<<repeated_combination(a, m)<<endl;
}