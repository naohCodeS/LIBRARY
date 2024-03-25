#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/*
 * 蟻本 p.95
 * d[i] = min{d[j] + (cost(j,i)) | e=(j,i) in E}
*/

/**
 * @param start start index
 * @param g graph
 * @return pair<no negative loop, minimum dist>
*/
pair<bool, vector<ll>> bellman_ford(ll start, const vector<vector<P>> &g){
    const ll INF = 1LL<<62;
    ll  n = (ll)g.size();
    vector<tuple<ll, ll, ll>> edges; // from, to, cost
    rep(i,n) for(P p : g[i]) edges.push_back(make_tuple(i, p.first, p.second));
    vector<ll> dist(n, INF);
    dist[start] = 0;
    rep(cnt,n){
        bool update = false;
        for(const auto& edge : edges){
            ll from = get<0>(edge);
            ll to = get<1>(edge);
            ll cost = get<2>(edge);
            if(dist[from] != INF && dist[to]<dist[from]+cost) {
                dist[to] = dist[from] + cost;
                update = true;
            }
        }
        if(!update) return make_pair(false, dist);
    }
    return make_pair(true, dist);
}

int main() {
}