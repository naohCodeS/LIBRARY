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
 * ナップサック問題 O(nw)
 * dp[i][j] := i番目までの要素から重さの総和がj以下となるように選んだ時の価値の総和の最大値
 * @param n 要素数
 * @param w 重さ制限
*/
ll knapsack(ll n, ll w, const vector<ll>& weights, const vector<ll>& values){
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
    rep(i,n){
        rep(j,w+1){
            if(j-weights[i] < 0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j - weights[i]] + values[i]);
        }
    }
    out(dp);
    return dp[n][w];
}

/**
 * ナップサック問題 O(nΣv)
 * O(nw)が間に合わない場合、価値の総和を列にする
 * dp[i][j] := i番目の要素から価値の総和がj以下となるように選んだ時の重さの最小値
*/
ll knapsack2(ll n, ll w, const vector<ll>& weights, const vector<ll>& values){
    const ll MAX_V = 100;
    const ll INF = 1LL<<62;
    vector<vector<ll>> dp(n+1, vector<ll>(n*MAX_V+1, INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,n*MAX_V+1){
            if(j-values[i] < 0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i][j], dp[i][j - values[i]] + weights[i]);
        }
    }
    out(dp);
    ll ans = -1;
    rep(i,n*MAX_V+1) if(dp[n][i] <= w) ans = i;
    return ans;
}

/**
 *  個数制限なしナップサック O(nw)
*/
ll knapsack_nolimit(ll n, ll w, const vector<ll>& weights, const vector<ll>& values){
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
    rep(i,n){
        rep(j,w+1){
            if(j-weights[i] < 0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i+1][j - weights[i]] + values[i]); //ここだけ違う
        }
    }
    out(dp);
    return dp[n][w];
}

/**
 * W,V巨大ナップサック O(2^(n/2) n)
*/
ll knapsack_huge(ll n, ll w, const vector<ll>& weights, const vector<ll>& values){
    vector<P> ps;
    map<ll,ll> mp;
    ll res = 0;
    rep(i,1LL<<n/2){
        ll sw=0,sv=0;
        rep(j,n/2){
            if(i>>j&1){
                sw+=weights[j];
                sv+=values[j];
            }
        }
        ps.emplace_back(sw,sv);
    }
    sort(ps.begin(), ps.end());
    rep(i,1LL<<(n-n/2)){
        ll sw=0,sv=0;
        rep(j,n-n/2){
            if(i>>j&1){
                sw+=weights[n/2+j];
                sv+=values[n/2+j];
            }
        }
        if(sw <= w) {
            ll tv = (lower_bound(ps.begin(), ps.end(), P(w-sw, 1LL<<61))-1)->second;
            res = max(res, sv+tv);
        }
    }
    return res;
}

int main(){
    ll n,w;
    vector<ll> weights, values;
    cin>>n>>w;
    rep(i,n){
        ll weight, value; cin>>weight>>value;
        weights.push_back(weight);
        values.push_back(value);
    }
    cout<<knapsack_huge(n, w, weights, values)<<endl;
    // cout<<knapsack2(n, w, weights, values)<<endl;
    return 0;
}