/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_90. Subsets II.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/20 10:01:00
 * @brief https://leetcode.com/problems/subsets-ii/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_90_SUBSETS_II_H
#define INC_1STPROGRAM_LEETCODE_90_SUBSETS_II_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> ret;
        vector<int> sol;
        unordered_map<int, int> m;
        for (int i : nums) {   //computing the count for every number
            m[i]++;
        }
        dfs(ret, sol, m.begin(), m);
        return ret;
    }

    //the back tracking part.
    void dfs(vector<vector<int>> &ret, vector<int> &sol,
             unordered_map<int, int>::iterator it, unordered_map<int, int> &m) {
        if (it != m.end()) {
            cout << it->first << " " << it->second << endl;
        }
        if (it == m.end()) {
            ret.push_back(sol);
            return;
        }
        int size = sol.size();
        dfs(ret, sol, next(it), m);
        for (int i = 0; i < it->second; i++) {
            sol.push_back(it->first);
            dfs(ret, sol, next(it), m);
        }
        sol.resize(size);
    }

    vector<vector<int>> subsets_basic(vector<int> &nums) {
        vector<vector<int>> result(1, vector<int>());
        for (auto &elem : nums) {
            int length = result.size();
            for (int i = 0; i < length; ++i) {
                result.push_back(result[i]);
                result.back().push_back(elem);
            }
        }

        return result;
    }
};


void test_subsets_II() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = Solution().subsetsWithDup(arr);
    result = Solution().subsets_basic(arr);
    cout << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_90_SUBSETS_II_H
