/**
 * 焼きなまし法
 * Simulated Annealing
*/

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define P pair<ll,ll>
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)

const ll TIME_LIMIT = 1950; // ms
const ll INF = 1<<31-1;
mt19937 engine;

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
void sa() {
    STATE state;
    init(state);
    double start_temp = 1e1; //1回の遷移で動きうるスコア幅の最大値
    double end_temp = 1e-1; //１回の遷移で動きうるスコアの最小値
    auto start_time = chrono::system_clock::now(); // 開始時刻
    while (true) { // 時間の許す限り回す
        auto now_time = chrono::system_clock::now(); // time; // 現在時刻
        double time = chrono::duration_cast<chrono::milliseconds>(now_time - start_time).count();
        if (time > TIME_LIMIT) break;

        STATE new_state = state;
        modify(new_state);
        ll new_score = calc_score(new_state);
        ll pre_score = calc_score(state);

        double tmp = start_temp + (end_temp - start_temp) * time / TIME_LIMIT;
        double prob = exp((new_score - pre_score) / tmp);

        if (prob > (engine()%INF/(double)INF)) { // スコア最大化の場合
            state = new_state;
        }
    }
}


int main() {
    sa();
}

/*
コンテストフォルダ作成 : acc new [コンテスト名] --template cpp
回答 : 問題を開いてmain.cppを編集
テスト : oj test -c ./a.out -d ./tests
提出 : acc submit
*/