#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 繰り返し二乗法 O(log n)
 * x^n%modを求める
 * @param x 
 * @param n 
 * @param mod 
 * @return x^n%mod
*/
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n%2) res = res*x % mod;
        x = x*x % mod;
        n >>= 1;
    }
    return res;
}

// ll mod_pow(ll x, ll n, ll mod){
//     if(n==0) return 1;
//     ll res = mod_pow(x*x%mod, n/2, mod);
//     if(n%2) res = res*x%mod;
//     return res;
// }

int main() {
    cout<<mod_pow(312,561,561)<<endl; //312^561%561=312 (カーマイケル数)
}
