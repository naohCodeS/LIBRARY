#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 素因数分解O(√n)
*/
map<ll,ll> factorize(ll n){
    map<ll,ll> res;
    for(ll i=2; i*i<=n; i++) {
        while(n%i==0){
            res[i]++;
            n /= i;
        }
    }
    if(n!=1) res[n]=1;
    return res;
}

int main() {
    map<ll,ll> mp = factorize(28);
    for(auto i:mp) {
        cout<<i.first<<" "<<i.second<<endl;
    }
}