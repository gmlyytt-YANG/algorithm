/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_53_1. Missing Number In [0, N-1].h
 * @author gmlyytt@outlook.com
 * @date 2018/08/24 9:34:00
 * @brief 剑指offer53_3题 排序数组中K的个数
 * */

#ifndef INC_1STPROGRAM_OFFER_53_GET_NUMBER_OF_K_H
#define INC_1STPROGRAM_OFFER_53_GET_NUMBER_OF_K_H

#include "../util/header_util.h"

class Solution {
public:
    int get_first_k(vector<int> &nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = ((low + high) >> 1);
        if (nums[mid] == target) {
            if (mid == 0 || nums[mid - 1] != target) {
                return mid;
            } else {
                high = mid - 1;
            }
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        return get_first_k(nums, target, low, high);
    }

    int get_last_k(vector<int> &nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = ((low + high) >> 1);
        int length = nums.size();
        if (nums[mid] == target) {
            if (mid == length - 1 || nums[mid + 1] != target) {
                return mid;
            } else {
                low = mid + 1;
            }
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        return get_last_k(nums, target, low, high);
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result = {-1, -1};
        if (!nums.empty()) {
            int length = nums.size();
            int first = get_first_k(nums, target, 0, length - 1);
            int last = get_last_k(nums, target, 0, length - 1);
            if (last != -1 && first != -1) {
                result = {first, last};
            }
        }
        return result;
    }
};


void test_searchRange() {
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int number = 8;
    vector<int> result = Solution().searchRange(arr, number);
}

#endif //INC_1STPROGRAM_OFFER_53_GET_NUMBER_OF_K_H
