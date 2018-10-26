/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_27. Sort Plus Index.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/26 10:52:00
 * @brief sort plus index
 * */

#ifndef INC_1STPROGRAM_COMMON_27_SORT_PLUS_INDEX_H
#define INC_1STPROGRAM_COMMON_27_SORT_PLUS_INDEX_H

#include "../util/header_util.h"

struct NumIndex {
    int val;
    int index;

    NumIndex(int v = 0, int i = 0) {
        val = v;
        index = i;
    }
};

struct cmp {
    bool operator()(NumIndex &ni_1, NumIndex &ni_2) {
        return ni_1.val < ni_2.val;
    }
};

void sort_plus_index(vector<NumIndex> &ni_vec) {
    if (ni_vec.empty()) {
        return;
    }
    sort(ni_vec.begin(), ni_vec.end(), cmp());
}

void test_sort_plus_index() {
    vector<int> array = {3, 4, 5, 1, 7, 8};
    vector<NumIndex> ni_vec;
    for (int i = 0; i < array.size(); ++i) {
        ni_vec.push_back({array[i], i});
    }
    sort_plus_index(ni_vec);
    for (auto &elem : ni_vec) {
        cout << elem.val << " " << elem.index << endl;
    }

}

#endif //INC_1STPROGRAM_COMMON_27_SORT_PLUS_INDEX_H
