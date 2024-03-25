#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

// 参考 AtCoder Library
// 二項演算op,単位元e
template <typename T, T (*op)(T, T), T (*e)()> 
struct segtree {
    int n; // 葉の数=元の配列の要素数
    vector<T> data; // 完全二分木の配列, 1-indexed
    int log; // ceil(log2(n)) 
    int size; // 2^log 完全二分木のサイズ

    segtree(int n) : segtree(vector<T>(n, e())) {}
    segtree(const vector<T>& v) : n(int(v.size())) {
        log; for (log = 0; (1 << log) < n; log++); 
        size = 1 << log; 
        data = vector<T>(2 * size, e()); // 単位元で初期化
        for (int i = 0; i < n; i++) data[size + i] = v[i]; // 葉に値を入れる
        for (int i = size - 1; i >= 1; i--) update(i); // 下から順に値を計算
    }

    void set(int p, T x) {
        // set(p,x):=k番目の要素にxを代入する
        assert(0 <= p && p < n);
        p += size;
        data[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    T get(int p) {
        // data[p]を返す
        assert(0 <= p && p < n);
        return data[p + size];
    }

    T prod(int l, int r) {
        // prod(l,r):=区間[l,r)の演算結果を返す
        assert(0 <= l && l <= r && r <= n);
        T sml = e(), smr = e(); // 左右から上る
        l += size;
        r += size;
        while(l < r) {
            if(l & 1) sml = op(sml, data[l++]);
            if(r & 1) smr = op(data[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    T all_prod() {
        // all_prod():=区間[0,n)の演算結果を返す
        return data[1];
    }

    void update(int k) {
        // update(k):=k番目の要素を更新する
        data[k] = op(data[2 * k], data[2 * k + 1]);
    }

    template <bool (*f)(T)> 
    int max_right(int l) {
        // max_right(l):=f(op(data[l],data[l+1],...,data[r-1]))=trueとなる最大のrを返す
        return max_right(l, [](T x) { return f(x); });
    }
    template <typename F> 
    int max_right(int l, F f) {
        // max_right(l,f):=f(op(data[l],data[l+1],...,data[r-1]))=trueとなる最大のrを返す
        assert(0 <= l && l <= n);
        assert(f(e()));
        if(l == n) return n;
        l += size;
        T sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, data[l]))) {
                while(l < size) {
                    l = (2 * l);
                    if(f(op(sm, data[l]))) {
                        sm = op(sm, data[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, data[l]);
            l++;
        } while((l & -l) != l);
        return n;
    }

    template <bool (*f)(T)> 
    int min_left(int r) {
        // min_left(r):=f(op(data[l],data[l+1],...,data[r-1]))=trueとなる最小のlを返す
        return min_left(r, [](T x) { return f(x); });
    }
    template <typename F> 
    int min_left(int r, F f) {
        // min_left(r,f):=f(op(data[l],data[l+1],...,data[r-1]))=trueとなる最小のlを返す
        assert(0 <= r && r <= n);
        assert(f(e()));
        if(r == 0) return 0;
        r += size;
        T sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(data[r], sm))) {
                while(r < size) {
                    r = (2 * r + 1);
                    if(f(op(data[r], sm))) {
                        sm = op(data[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(data[r], sm);
        } while((r & -r) != r);
        return 0;
    }
};

// AtCoder Library Practice Contest J - Segment Tree
ll op(ll x, ll y) { return max(x,y); }
ll e() { return -1; }
ll v;
bool f(ll x) {
    return x < v;
}

int main() {
    ll N, Q; cin >> N >> Q;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    segtree<ll, op, e> seg(A);
    // Define a function that returns true if x is less than v

    rep(i, Q) {
        ll q; cin >> q;
        if(q == 1) {
            ll x, v; cin >> x >> v; x--;
            seg.set(x, v);
        }
        else if(q == 2) {
            ll l, r; cin >> l >> r; l--, r--;
            cout << seg.prod(l, r+1) << endl;
        }
        else {
            ll x; cin >> x >> v; x--;
            cout << seg.max_right<f>(x)+1 << endl;
        }
    }
}

// // AOJ DSL_2_A Range Minimum Query
// ll op(ll x, ll y) { return min(x,y); }
// ll e() { return (1<<31)-1; }

// int main() {
//     ll N, Q; cin >> N >> Q;
//     segtree<ll, op, e> seg(N);
//     rep(i, Q) {
//         ll com, x, y; cin >> com >> x >> y;
//         if(com == 0) {
//             seg.set(x, y);
//         } else {
//             cout << seg.prod(x, y+1) << endl;
//         }
//     }
// }