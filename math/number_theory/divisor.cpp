#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * 約数列挙O(√n)
*/
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1; i*i<=n; i++) {
        if(n%i==0) {
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<ll> divisors = divisor(100);
    for(auto i : divisors) {
        cout<<i<<" ";
    }
    cout<<endl;
}