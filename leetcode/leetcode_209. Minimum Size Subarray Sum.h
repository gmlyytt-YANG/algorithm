/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_209. Minimum Size Subarray Sum.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/10 15:33:00
 * @brief https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_209_MINIMUM_SIZE_SUBARRAY_SUM_H
#define INC_1STPROGRAM_LEETCODE_209_MINIMUM_SIZE_SUBARRAY_SUM_H

#include "../util/header_util.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        queue<int> q;
        int sum = nums[0];
        int min_num = INT_MAX;
        q.push(nums[0]);
        int index = 1;
        while (!q.empty()) {
            while (index < nums.size() && sum < s) {
                sum += nums[index];
                q.push(nums[index++]);
            }
            // consider reaching the end of the array
            if (sum >= s) {
                min_num = min(min_num, (int)q.size());
            }
            // when poping, sum should substract q.front()
            sum -= q.front();
            q.pop();
        }
        if (min_num == INT_MAX) {
            min_num = 0;
        }
        return min_num;
    }

    int minSubArrayLen2(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int min_num = nums.size() + 1;

        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int temp = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                ++temp;
                if (sum >= s) {
                    if (temp < min_num) {
                        min_num = temp;
                    }
                    break;
                }
            }
        }
        return min_num > nums.size() ? 0 : min_num;
    }
};

void test_min_subarray_len() {
    vector<int> nums = {1,2,3,4,5};
    int s = 7;
    int result = Solution().minSubArrayLen(s, nums);
    cout << result << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_209_MINIMUM_SIZE_SUBARRAY_SUM_H
