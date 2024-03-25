#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 拡張ユークリッドの互除法
 * ax + by = gcd(a,b)
*/
ll extgcd(ll a, ll b, ll& x, ll& y) {
    if(b==0LL) {x=1; y=1; return a;}
    ll d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
    ll a,b; cin>>a>>b;
    ll x,y;
    ll d = extgcd(a,b,x,y);
    cout<<x<<" "<<y<<" "<<d<<endl;
}
