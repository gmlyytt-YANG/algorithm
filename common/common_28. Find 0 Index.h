/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_28. Find 0 Index.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/26 11:21:00
 * @brief find the first 0 index
 * */

#ifndef INC_1STPROGRAM_COMMON_28_FIND_0_INDEX_H
#define INC_1STPROGRAM_COMMON_28_FIND_0_INDEX_H

#include "../util/header_util.h"

/*
 * @brief all 0s are at the front of array
 */
int find_0_index(vector<int> &array) {
    if (array.empty()) {
        return -1;
    }
    int low = 0;
    int high = array.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2 + 1;
        if (array[mid] == 0) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    if (array[low] == 0) {
        return low;
    }
    return -1;
}

void test_find_0_index() {
    vector<int> array = {0, 0, 0, 1, -3, 4};
    int index_0 = find_0_index(array);
    cout << index_0 << endl;
}

#endif //INC_1STPROGRAM_COMMON_28_FIND_0_INDEX_H
