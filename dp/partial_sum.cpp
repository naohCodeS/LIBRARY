#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

void out(const vector<vector<ll>> &dp){
    cout<<"----------------------------"<<endl;
    for(auto v : dp){
        for(auto e : v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
}

/**
 * 個数制限付き部分和 O(nx)
 * dp[i+1][j] := i番目まででjを作る際に余る最大のiの個数
 * 個数制限なしナップサック問題の拡張だと考えるとわかりやすい
 * @param n 種類数
 * @param a 種類
 * @param b b_i := a_iの個数
 * @param x 目標部分和
*/
bool partial_sum(ll n, const vector<ll>& a, const vector<ll>& b, ll x){
    vector<vector<ll>> dp(n+1, vector<ll>(x+1, -1));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,x+1){
            if(dp[i][j] >= 0) dp[i+1][j] = b[i]; //i-1番目まででjを作れるなら、i番目をb[i]個残してjを作れる
            else if(j - a[i] >= 0 && dp[i+1][j-a[i]] > 0) dp[i+1][j] = dp[i+1][j-a[i]] - 1; //i番目まででj-a[i]を作るときにi番目をk(>0)個残せるなら、i番目をk-1個残してjを作れる
            else dp[i+1][j] = -1; 
        }
    }
    return dp[n][x] >= 0;
}

/**
 * 個数制限付き部分和 O(xΣb)
 * dp[i+1][j] := i番目まででjが作れるか
 * @param n 種類数
 * @param a 種類
 * @param b b_i := a_iの個数
 * @param x 目標部分和
*/
bool partial_sum_slow(ll n, const vector<ll>& a, const vector<ll>& b, ll x){
    vector<vector<bool>> dp(n+1, vector<bool>(x+1, false));
    dp[0][0] = true;
    rep(i,n){
        rep(j, x+1){
            for(ll k=0; k<=b[i] && k*a[i] <= j; k++){
                if(dp[i][j-k*a[i]]) dp[i+1][j] = true;
            }
        }
    }
    return dp[n][x];
}

int main(){
    ll n, x; cin>>n>>x;
    vector<ll> a(n), b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    cout<<partial_sum_slow(n, a, b, x)<<endl;
    cout<<partial_sum(n, a, b, x)<<endl;
}