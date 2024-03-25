#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * @param g adjacency-matrix pair<adjacent-vertex, cost>
 * @return minimum cost
*/
ll kruskal(vector<vector<P>> g){
    vector<tuple<ll,ll,ll>> edges;
    rep(i,(ll)g.size()) for(P p : g[i]) edges.emplace_back(p.second, i, p.first);
    sort(edges.begin(), edges.end());
    dsu uf(g.size());
    ll sum=0;
    for(auto e : edges){
        ll cost=get<0>(e);
        ll u=get<1>(e);
        ll v=get<2>(e);
        if(!uf.same(u,v)){
            uf.merge(u,v);
            sum+=cost;
        }
    }
    return sum;
}

/**
 * @param g adjacency-matrix pair<adjacent-vertex, cost>
 * @return pair<mst, minimum cost>
*/
pair<vector<vector<P>>,ll> minimum_spanning_tree(vector<vector<P>> g){
    vector<vector<P>> mst(g.size());
    vector<tuple<ll,ll,ll>> edges;
    rep(i,(ll)g.size()) for(P p : g[i]) edges.emplace_back(p.second, i, p.first);
    sort(edges.begin(), edges.end());
    dsu uf(g.size());
    ll sum=0;
    rep(i,(ll)edges.size()){
        tuple<ll,ll,ll> e = edges[i];
        ll cost=get<0>(e);
        ll u=get<1>(e);
        ll v=get<2>(e);
        if(!uf.same(u,v)){
            uf.merge(u,v);
            mst[u].emplace_back(v,cost);
            mst[v].emplace_back(u,cost);
            sum+=cost;
        }
    }
    return make_pair(mst,sum);
}

// AOJ Minimum Spanning Tree : https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja
int main() {
    ll v,e; cin>>v>>e;
    vector<vector<P>> g(v);
    rep(i,e) {
        ll a, b, cost; cin>>a>>b>>cost;
        g[a].emplace_back(b,cost);
        g[b].emplace_back(a,cost);
    }
    cout<<kruskal(g)<<endl;
}
