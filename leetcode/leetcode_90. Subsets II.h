// Created by Administrator on 2018/9/20.
// Author: liyang
//

#ifndef INC_1STPROGRAM_LEETCODE_90_SUBSETS_II_H
#define INC_1STPROGRAM_LEETCODE_90_SUBSETS_II_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
    void dfs(vector<vector<int>>& ret, vector<int>& sol,
            unordered_map<int, int>::iterator it, unordered_map<int, int>& m) {
        if (it != m.end()) {
            cout << it->first << " " << it->second << endl;
        }
        if (it == m.end()) { //if we reach the last level, put the sol into ret and return
            ret.push_back(sol);
            return;
        }
        int size = sol.size();
        dfs(ret, sol, next(it) , m);          //put nothing in this level and go directly to the next level.
        for (int i = 0; i < it->second; i++) {
            sol.push_back(it->first);      // put i number in this level and go to next level
            dfs(ret, sol, next(it) , m);
        }
        sol.resize(size);                    //after dfs, resize the sol to original size;
    }
};

void test_subsets_II() {
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> result = Solution().subsetsWithDup(arr);
}
#endif //INC_1STPROGRAM_LEETCODE_90_SUBSETS_II_H
