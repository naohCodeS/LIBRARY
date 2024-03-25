#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 分割数 O(nm)
 * n個の互いに区別できない品物を、m個以下に分割する方法の総数
 * dp[i][j] := jのi分割の総数
 * dp[i][j] = dp[i][j-i] + dp[i-1][j]
 * 正数i個以下への分割：dp[i][j-i]個
 * ゼロを含む分割：dp[i-1][j]個
 * @param n nを
 * @param m m個以下に分割
 * @param nのm個以下に分割する方法の総数
*/
ll partitions(ll n, ll m, ll mod){
    vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;
    for(ll i=1; i<=m; i++){
        for(ll j=0; j<=n; j++){
            if(j-i>=0) dp[i][j] = (dp[i][j-i] + dp[i-1][j]) % mod;
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

int main(){
    ll n, m; cin>>n>>m;
    cout<<partitions(n, m, 10000)<<endl;
}