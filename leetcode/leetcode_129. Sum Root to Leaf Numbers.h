/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_129. Sum Root to Leaf Numbers.h
 * @author liyang921126@gmail.com
 * @date 2018/10/02 15:36:00
 * @brief https://leetcode.com/problems/number-of-islands/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_129_SUM_ROOT_TO_LEAF_NUMBERS_H
#define INC_1STPROGRAM_LEETCODE_129_SUM_ROOT_TO_LEAF_NUMBERS_H

#include <iostream>
#include <vector>
#include <cmath>

#include "../util/tree_util.h"

using namespace std;

class Solution {
public:
    int dfs(TreeNode* root, int& sum) {
        if (!root) {
            return 0;
        }
        int new_sum = root->val + sum * 10;
        if (!(root->left) && !(root->right)) {
            return new_sum;
        }
        return dfs(root->left, new_sum) + dfs(root->right, new_sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return dfs(root, sum);
    }
};

void test_sumNumbers() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    connect_tree_node(node1, node2, node3);
    int result = Solution().sumNumbers(node1);
    cout << result << endl;
}
#endif //INC_1STPROGRAM_LEETCODE_129_SUM_ROOT_TO_LEAF_NUMBERS_H
