#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 値の大きい（または小さい）K個の和を高速に取得できる多重集合
*/
template<typename T, typename Compare = less<T>, typename RCompare = greater<T>>
struct multiset_sum {
    multiset<T> x, y;
    T k;
    T sum;

    multiset_sum(T k) : k(k), sum(0) {}

    void set_k(T kk){
        k=kk;
    }
    T get_k(){
        return k;
    }
    T get_sum(){
        return sum;
    }

    void balance(){
        while(x.size()<k && !y.empty()){
            auto iy=y.end(); iy--;
            T ey=*iy;
            x.insert(ey);
            sum+=ey;
            y.erase(iy);
        }
        if(x.empty() || y.empty()) return;
        while(true){
            auto ix=x.begin();
            auto iy=y.end(); iy--;
            T ex=*ix;
            T ey=*iy;
            if(ex>=ey)break;
            sum+=ey-ex;
            x.erase(ix);
            y.erase(iy);
            x.insert(ey);
            y.insert(ex);
        }
    }

    void add(T v){
        y.insert(v);
        balance();
    }

    void erase(T v){
        if(x.find(v)!=x.end()){sum-=v; x.erase(x.find(v));}
        else if(y.find(v)!=y.end()){y.erase(y.find(v));}
        balance();
    }
};

template<typename T>
using multiset_max_sum = multiset_sum<T, greater<T>, less<T>>;
template<typename T>
using multiset_min_sum = multiset_sum<T, less<T>, greater<T>>;


// abc306
int main() {
    ll n, k, q; cin>>n>>k>>q;
    vector<ll> a(n,0);
    multiset_max_sum<ll> ms(k);
    rep(i,q){
        ll x,y; cin>>x>>y; x--;
        ms.add(y);
        ms.erase(a[x]);
        a[x]=y;
        cout<<ms.get_sum()<<endl;
    }
}