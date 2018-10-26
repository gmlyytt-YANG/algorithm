/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_229. Majority Element II.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/25 15:33:00
 * @brief https://leetcode.com/problems/majority-element-ii/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_229_MAJORITY_ELEMENT_II_H
#define INC_1STPROGRAM_LEETCODE_229_MAJORITY_ELEMENT_II_H

#include "../util/header_util.h"

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int threshold = nums.size() / 3;
        unordered_map<int, int> m;
        vector<int> result;
        for (auto &elem : nums) {
            if (++m[elem] > threshold && find(result.begin(), result.end(), elem) == result.end()) {
                result.push_back(elem);
            }
        }
        return result;
    }
};

void test_m_element() {
    vector<int> nums{3};
    vector<int> result = Solution().majorityElement(nums);
}
#endif //INC_1STPROGRAM_LEETCODE_229_MAJORITY_ELEMENT_II_H
