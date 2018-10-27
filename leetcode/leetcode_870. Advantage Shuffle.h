/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_870. Advantage Shuffle.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/26 11:43:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_870_ADVANTAGE_SHUFFLE_H
#define INC_1STPROGRAM_LEETCODE_870_ADVANTAGE_SHUFFLE_H

#include "../util/header_util.h"

class Solution {
    struct Pair {
        int first, second;

        Pair(int f = 0, int s = 0) : first(f), second(s) {}

        bool operator<(const Pair &p) const {
            if (first != p.first)
                return first < p.first;
            return second < p.second;
        }
    };

public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B) {
        int n = A.size();
        vector<int> res(n, 0);
        int lo = 0, hi = n - 1;
        sort(A.begin(), A.end());
        priority_queue<Pair> q;
        for (int i = 0; i < n; ++i) {
            q.push(Pair(B[i], i));
        }
        while (!q.empty()) {
            auto pa = q.top();
            q.pop();
            if (A[hi] > pa.first) {
                res[pa.second] = A[hi--];
            } else {
                res[pa.second] = A[lo++];
            }
        }
        return res;
    }
};

void test_advantage_shuffle() {
    vector<int> A = {2, 7, 11, 15};
    vector<int> B = {1, 10, 4, 11};
    vector<int> result = Solution().advantageCount(A, B);
}

#endif //INC_1STPROGRAM_LEETCODE_870_ADVANTAGE_SHUFFLE_H
