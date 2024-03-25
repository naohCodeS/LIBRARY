#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 全点対最短路
 * @param g graph
 * @return distance
*/
vector<vector<ll>> warshall_floyd(const vector<vector<P>>& g){
    const ll INF = 1LL<<62;
    ll n = g.size();
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(from,n){
        dist[from][from] = 0;
        for(P edge : g[from]){
            ll to = edge.first;
            ll cost = edge.second;
            dist[from][to] = cost;
        }
    }

    rep(via, n)
        rep(from, n)
            rep(to, n)
                dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);

}

bool find_neg_loop(const vector<vector<ll>> &dist){
    rep(i, (ll)dist.size()) if(dist[i][i] < 0) return true;
    return false;
}

int main() {
    
}
