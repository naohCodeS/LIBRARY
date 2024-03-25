/*
二部グラフ判定
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

bool dfs(const vector<vector<ll>>& g, ll v, ll color, vector<ll>& colors){
    colors[v] = color;
    for(auto nv : g[v]) {
        if(colors[nv] == 0) { // 中かっこ必要
            if(!dfs(g, nv, -color, colors)) return false; // 次のノードが未探索
        }
        else if(colors[nv] != -color) return false; //探索済み
    }
    return true;
}

/**
 * @param g graph
 * @return true or false
*/
bool is_bipartite(const vector<vector<ll>>& g){
    bool res = true;
    ll n = (ll)g.size();
    vector<ll> colors(n, 0); // 0:未探索
    rep(v,n){
        if(colors[v] != 0) continue;
        if(!dfs(g, v, 1, colors)) res = false;
    }
    return res;
}

int main() {
    
}