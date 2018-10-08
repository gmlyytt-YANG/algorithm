/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_16. 3Sum Closest.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/08 13:18:00
 * @brief https://leetcode.com/problems/3sum-closest/description/
 * @link http://note.youdao.com/noteshare?id=9b2de69628664f938d20dff397d98ae9&sub=C09CCE0E68724A69954D8E6423D36DA9
 * */

#ifndef INC_1STPROGRAM_LEETCODE_16_3SUM_CLOSEST_H
#define INC_1STPROGRAM_LEETCODE_16_3SUM_CLOSEST_H

#include "../util/header_util.h"

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int low = i + 1;
            int high = nums.size() - 1;
            int component = target - nums[i];
            while (low < high) {
                if (component == nums[low] + nums[high]) {
                    return target;
                }
                if (abs(nums[low] + nums[high] - component) < min_diff) {
                    result = nums[low] + nums[high] + nums[i];
                    min_diff = abs(nums[low] + nums[high] - component);
                }
                if (nums[low] + nums[high] < component) {
                    ++low;
                } else {
                    --high;
                }
            }
        }
        return result;
    }
};

void test_three_sum_closest() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = Solution().threeSumClosest(nums, target);
    cout << result << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_16_3SUM_CLOSEST_H
