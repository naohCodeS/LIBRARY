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
 * 最長共通部分列(Longest Common Subsequence) O(nm)
 * dp[i][j] := s_0...s_iとt_0...t_jに対するLCSの長さ
*/
ll lcs(string s, string t){
    ll n = (ll)s.size();
    ll m = (ll)t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    rep(i,n){
        rep(j,m){
            if(s[i]==t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    out(dp);
    return dp[n][m];
}

int main(){
    string s = "abcd";
    string t = "becd";
    cout << lcs(s, t) << endl;
    return 0;
}

/*
コンテストフォルダ作成 : acc new [コンテスト名] --template cpp
回答 : 問題を開いてmain.cppを編集
テスト : oj test -c ./a.out -d ./tests
提出 : acc submit
*/