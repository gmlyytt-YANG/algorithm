// Created by Administrator on 2018/9/24.
// Author: liyang
//
// 在数组中找到一个数插入的合适位置，比如[1,2,2,3,5,7], 2的插入位置为2(下标从0开始)

#ifndef INC_1STPROGRAM_COMMON_25_SEARCH_BIGGEST_INSERT_POSITION_H
#define INC_1STPROGRAM_COMMON_25_SEARCH_BIGGEST_INSERT_POSITION_H

#include <iostream>
#include <vector>

int binary_search_iterative(const std::vector<int>& arr, const int num) {
    if (arr.empty()) {
        return -1;
    }
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num) {
            return mid;
        } else if (arr[mid] > num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(const std::vector<int>& arr, const int num, int low, int high) {
    if (arr.empty()) {
        return -1;
    }
    int index = -1;
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > num) {
            index = binary_search_recursive(arr, num, low, mid-1);
        } else if (arr[mid] < num) {
            index = binary_search_recursive(arr, num, mid+1, high);
        } else {
            return mid;
        }
    }
    return index;
}

/*
 * @brief 有序数组中数不重复，查找某值，如果查到找，就返回其位置，如果查找不到就返回该插入的位置
 *
 * @param nums input vector
 * @param target
 * @return insert location
 */
int insert_location_no_repeat(std::vector<int>& nums, int target){
    if(nums.empty()){
        return -1;
    }
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

/*
 * @brief 有序数组中找到最后一个小于target的位置
 *
 * @param nums input vector
 * @param target
 * @return insert location
 */
int last_inser_location_small_than(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low  = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

/*
 * @brief 有序数组中找到最后一个小于等于target的位置
 *
 * @param nums input vector
 * @param target
 * @return insert location
 */
int last_insert_location_smaller_equal(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low  = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

/*
 * @brief 有序数组中数重复，查找出现的第一个数的位置
 *
 * @param nums input vector
 * @param target
 * @return element location
 */
int first_element_location_equal(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (nums[high] == target) {
        return high;
    }
    return -1;
}

/*
 * @brief 有序数组中数重复，查找出现的最后数的位置
 *
 * @param nums input vector
 * @param target
 * @return element location
 */
int last_element_location_equal(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2 + 1;
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    if (nums[low] == target) {
        return low;
    }
    return -1;
}

/*
 * @brief 有序数组，查找数组中第一个大于 key 的位置
 *
 * @param nums input vector
 * @param target
 * @return insert location
 */
int first_insert_location_larger(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

/*
 * @brief 有序数组，查找数组中第一个大于等于 key 的位置
 *
 * @param nums input vector
 * @param target
 * @return insert location
 */
int first_insert_location_larger_equal(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

/*
 * @brief 有序数组，查找数组中最后  大于等于 key 的位置
 *
 * @param nums input vector
 * @param target
 * @return insert location
 */
int last_insert_location_larger(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

void test_binary_search() {
    std::vector<int> nums_1 = {1, 3, 6, 6};
    std::vector<int> nums_2 = {6, 6, 7, 8};
    std::vector<int> nums_3 = {5, 6, 7, 8};
    std::vector<int> nums_4 = {1, 2, 3, 4};
    std::vector<int> nums_5 = {7, 8, 9, 10};
    int target = 6;
    std::cout << last_insert_location_larger(nums_1, target) << std::endl;
    std::cout << last_insert_location_larger(nums_2, target) << std::endl;
    std::cout << last_insert_location_larger(nums_3, target) << std::endl;
    std::cout << last_insert_location_larger(nums_4, target) << std::endl;
    std::cout << last_insert_location_larger(nums_5, target) << std::endl;

}
#endif //INC_1STPROGRAM_COMMON_25_SEARCH_BIGGEST_INSERT_POSITION_H
