#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * topological sort (by bfs)
 * result.size() != g.size() なら閉路が存在する(DAGでない)
 * @param g directed graph
 * @return sorted vector
*/
vector<ll> topological_sort(const vector<vector<ll>>& g) {
    vector<ll> result;
    vector<ll> deg(g.size());
    for(const auto& v : g) for(const auto& to : v) deg[to]++;
    queue<ll> que; //list of deg=0
    rep(i, (ll)g.size()) if(deg[i]==0) que.push(i);

    while(!que.empty()){
        ll from=que.front(); que.pop();
        result.push_back(from);
        for(const auto& to : g[from]) 
            if(!--deg[to]) que.push(to);
    }
    return result;
}

/**
 * topological sort (by dfs)
 * @param g directed graph
 * @return sorted vector
*/
vector<ll> topological_sort_dfs(const vector<vector<ll>>& g){
    vector<bool> visited(g.size(), false);
    vector<ll> result;

    auto dfs = [&](auto dfs, ll from) -> void {
        if(visited[from]) return;
        visited[from] = true;
        for(ll to : g[from]) dfs(dfs, to);
        result.push_back(from);
    };
    rep(i,(ll)g.size()) dfs(dfs, i);
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ll n, m; cin>>n>>m;
    vector<vector<ll>> g(n);
    rep(i,m){
        ll a, b; cin>>a>>b, a--, b--;
        g[a].push_back(b);
    }
    for(ll v : topological_sort(g)) cout<<v<<" ";
    cout<<endl;
}