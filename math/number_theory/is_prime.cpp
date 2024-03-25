#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 素数判定O(√n)
*/
bool is_prime(ll n){
    for(ll i=2; i*i<=n; i++) if(n%i==0) return false;
    return n!=1;
}

int main() {
    cout<<is_prime(4)<<endl;
    cout<<is_prime(5)<<endl;
}