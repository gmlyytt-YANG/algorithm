/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_886. Possible Bipartition.h
 * @author liyang921126@gmail.com
 * @date 2018/10/02 20:16:00
 * @brief https://leetcode.com/problems/possible-bipartition/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_886_POSSIBLE_BIPARTITION_H
#define INC_1STPROGRAM_LEETCODE_886_POSSIBLE_BIPARTITION_H

#include "../util/header_util.h"

class Solution {
public:
    void dfs(int cur_vertex, int color, vector<int>& visited,
             vector<vector<int>>& dislikes) {
        visited[cur_vertex] = color;
        for (int i = 0; i < dislikes.size(); ++i) {
            if (dislikes[i][0] == cur_vertex) {
                if (visited[dislikes[i][1]] == -1) {
                    dfs(dislikes[i][1], 1 - color, visited, dislikes);
                } else if (visited[dislikes[i][1]] == color) {
                    result = false;
                    return;
                }
            }
        }
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N < 0 || dislikes.empty()) {
            return true;
        }
        vector<int> visited(N + 1, -1);
        result = true;
        dfs(1, 0, visited, dislikes);
        return result;
    }
private:
    bool result;
};

void test_possible_bipartition() {
    int N = 4;
    vector<vector<int>> dislikes = {
            {1, 2},
            {1, 3},
            {2, 4}
    };
    bool result = Solution().possibleBipartition(N, dislikes);
    cout << result << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_886_POSSIBLE_BIPARTITION_H
