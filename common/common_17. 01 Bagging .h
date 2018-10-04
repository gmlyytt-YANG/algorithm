// Created by Administrator on 2018/9/8.
// Author: liyang
//
// 0 1 背包问题

#ifndef INC_1STPROGRAM_COMMON_17_BAG_0_1_H
#define INC_1STPROGRAM_COMMON_17_BAG_0_1_H

#include <iostream>
#include <vector>

using namespace std;

void trace_back(vector<vector<int> >& result, vector<int>& w) {
    int N = result.size() - 1;
    int C = result[0].size() - 1;
    vector<int> x(N + 1, 0);
    for (int i = N; i > 0; i--) {
        if (result[i][C] == result[i - 1][C]) x[i] = 0;
        else {
            x[i] = 1;
            C -= w[i];
        }
    }
    /*x[1] = result[1][C] > 0 ? 1 : 0;*/
    for (int i = 1; i < N + 1; i++) {
        cout << x[i] << " ";
    }
}

int bagging(vector<int>& v, vector<int>& w, int value, bool print_debug=true) {
    if (v.empty() || w.empty() || v.size() != w.size() || w[0] != 0 || v[0] != 0 || value <= 0) {
        return -1;
    }
    int n = v.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(value + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= value; ++j) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
//            if (print_debug) {
//                cout << dp[i][j] << " ";
//            }
        }
//        if (print_debug) {
//            cout << endl;
//        }
    }
    trace_back(dp, w);
    return dp[n][value];
}



void test_bagging() {
    vector<int> v = { 0,9, 8, 2, 5, 10 };
    vector<int> w = { 0,3,4,1,2,8 };
    int value = 10;
    int result = bagging(v, w, value);
}
#endif //INC_1STPROGRAM_COMMON_17_BAG_0_1_H
