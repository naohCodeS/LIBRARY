#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

/**
 * エラトステネスの篩 O(n log log n)
 * @param n [2,n)
 * @return n以下の素数リスト
*/
vector<ll> sieve(ll n){
    vector<bool> isprime(n+1, true);
    vector<ll> primes;
    isprime[0] = isprime[1] = false;
    for(ll i=2; i<=n; i++){
        if(isprime[i]) {
            primes.push_back(i);
            for(ll j=2*i; j<=n; j+=i) isprime[j] = false;
        }
    }
    return primes;
}

/**
 * エラトステネスの区間篩
 * 区間[a,b)間の素数を求める
 * b-aは十分小さくなければならない
 * -----------------------------------------------
 * B以下の合成数を振るい落とすためには√B以下の素数pの倍数を振るい落とせば十分である
 * √b以下の素数を求める：O(√b log log b)
 * A以上B以下のpの倍数を振るい落とす：O((b-a) log log b)
 * -----------------------------------------------
 * @param a 以上
 * @param b 未満
 * @return 区間[a,b)に含まれる素数リスト
*/
vector<ll> segment_sieve(ll a, ll b){
    vector<bool> isprime((ll)sqrt(b)+1, true); //篩
    vector<bool> isprime2(b-a+1, true); //[a,b)のvが素数か
    vector<ll> primes;
    for(ll p=2; p*p<=b; p++){
        if(!isprime[p]) continue;
        for(ll q=p*2; q*q<=b; q+=p) isprime[q] = false;
        for(ll q=max(2LL,(a+p-1)/p)*p; q<b; q+=p) isprime2[q-a] = false;
    }
    for(ll p=a; p<b; p++){
        if(isprime2[p-a]) primes.push_back(p);
    }
    sort(primes.begin(), primes.end());
    return primes;
}

int main() {
    vector<ll> primes = segment_sieve(50, 100);
    for(ll p : primes){
        cout<<p<<" ";
    }
    cout<<endl;
}