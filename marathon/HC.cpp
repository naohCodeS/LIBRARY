/**
 * 山登り法
 * Hill Climbing
*/

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

const ll TIME_LIMIT = 1950; // ms

//状態
struct STATE {
};

// 状態の初期化
void init (STATE& state) {
}

// 状態遷移
void modify (STATE& state) {
}

// 状態のスコア計算
ll calc_score (STATE& state) {
    return 0;
}

// 山登り法
void hc() {
    STATE state;
    init(state);
    auto start_time = chrono::system_clock::now(); // 開始時刻
    while (true) { // 時間の許す限り回す
        auto now_time = chrono::system_clock::now(); // time; // 現在時刻
        double time = chrono::duration_cast<chrono::milliseconds>(now_time - start_time).count();
        if (time > TIME_LIMIT) break;

        STATE new_state = state;
        modify(new_state);
        ll new_score = calc_score(new_state);
        ll pre_score = calc_score(state);

        if (new_score > pre_score) { // スコア最大化の場合
            state = new_state;
        }
    }
}


int main() {
    hc();
}