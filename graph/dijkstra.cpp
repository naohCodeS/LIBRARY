#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * ダイクストラ法
 * @param start 開始頂点番号
 * @param g 隣接行列
 * @return <各頂点までの最短距離, 各頂点までの最短経路>
*/
pair<vector<ll>, vector<ll>> dijkstra(ll start, vector<vector<P>> g){
    ll n = g.size();
    vector<ll> dist(n, 1LL<<62);
    vector<ll> prev(n, -1);
    priority_queue<P, vector<P>, greater<P>> pq;//first:最短距離,second:頂点番号
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        P p=pq.top(); pq.pop();
        ll v=p.second; //現在の頂点番号
        if(dist[v]<p.first) continue; //最短経路上でなければ処理しない
        for(P e : g[v]){ //到達可能な全ての頂点について
            ll u=e.first; //次の頂点
            ll cost=dist[v]+e.second; //この経路を通る場合のコスト
            if(dist[u]<=cost) continue; //最短経路でなければ処理しない
            dist[u]=cost; //最短距離を更新
            prev[u]=v; //現在の頂点から次の頂点へ辺を張る
            pq.emplace(dist[u],u);
        }
    }
    return make_pair(dist, prev);
}

/**
 * startからgoalまでの最短経路復元
 * @param start 開始頂点番号
 * @param goal 目標頂点番号
*/
vector<ll> restore(ll start, ll goal, vector<ll> prev){
    vector<ll> path;
    for(ll i=goal; i!=start; i=prev[i]) path.push_back(i);
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

/**
 * グリッド上のダイクストラ法
 * @param start 開始座標
 * @param g グリッド
 * @param h グリッドの高さ
 * @param w グリッドの幅
 * @return <各座標までの最短距離, 各座標までの最短経路上の直前座標>
*/
pair<vector<vector<ll>>, vector<vector<P>>> dijkstra_grid(P start, vector<vector<ll>> g, ll h, ll w){
    P mv[4] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    vector<vector<ll>> dist(h, vector<ll>(w,1LL<<62));
    vector<vector<P>> prev(h, vector<P>(w, P(-1,-1)));
    priority_queue<pair<ll,P>, vector<pair<ll,P>>, greater<pair<ll,P>>> pq;//first:最短距離,second:頂点座標
    dist[start.first][start.second] = 0;
    pq.push(make_pair(dist[start.first][start.second], start));
    while (!pq.empty()) {
        pair<ll,P> p=pq.top(); pq.pop();
        P v=p.second; //現在の頂点座標
        if(dist[v.first][v.second]<p.first) continue; //最短経路上でなければ処理しない
        rep(i,4){
            P u=P(v.first+mv[i].first, v.second+mv[i].second); //次の座標
            if(u.first<0||u.first>=h||u.second<0||u.second>=w) continue;
            ll cost=dist[v.first][v.second]+g[u.first][u.second]; //この経路を通る場合のコスト
            if(dist[u.first][u.second]<=cost) continue;
            dist[u.first][u.second]=cost;
            prev[u.first][u.second]=v;
            pq.emplace(dist[u.first][u.second], u);
        }
    }
    return make_pair(dist, prev);
}

/**
 * グリッド上のstartからgoalまでの最短経路復元
 * @param start 開始座標
 * @param goal 目標座標
 * @param prev 各座標までの最短経路上の直前座標
 * @return startからgoalまでの最短経路の座標配列
*/
vector<P> restore_grid(P start, P goal, vector<vector<P>> prev){
    vector<P> path;
    for(P i=goal; i!=start; i=prev[i.first][i.second]) path.push_back(i);
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    
}