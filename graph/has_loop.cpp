#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

bool has_loop(int now, int prev, const vector<vector<int>>& g, vector<bool>& visited){
    visited[now] = true;
    bool loop = false;
    for(int nxt : g[now]) {
        if(visited[nxt]) {
            if(nxt == prev) continue;
            else loop = true;
        }
        else loop = has_loop(nxt, now, g, visited);
    }
    return loop;
}

bool has_loop(vector<vector<int>>& g){
    dsu uf(g.size());
    vector<P> edges;
    rep(from,(ll)g.size()) for(int to : g[from]) edges.emplace_back(from, to);
    bool loop = false;
    rep(i,(ll)edges.size()) {
        if(uf.same(edges[i].first, edges[i].second)) loop = true;
        uf.merge(edges[i].first, edges[i].second);
    }
    return loop;
}

int main() {
    // ABC231 D (ループ検出だけ)
    int N, M; cin>>N>>M;
    vector<vector<int>> g(N);
    rep(i,M){
        int A, B; cin>>A>>B; A--,B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    
    { // dfs
        bool loop = false;
        vector<bool> visited(N,false);
        rep(i,N) {
            if(visited[i]) ;
            else loop |= has_loop(i,-1, g, visited);
        }
        if(loop) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    { // union find
        bool loop = false;
        loop |= has_loop(g);
        if(loop) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

/*
コンテストフォルダ作成 : acc new [コンテスト名] --template cpp
回答 : 問題を開いてmain.cppを編集
テスト : oj test -c ./a.out -d ./tests
提出 : acc submit
*/