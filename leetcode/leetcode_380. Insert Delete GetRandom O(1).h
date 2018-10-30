/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_380. Insert Delete GetRandom O(1).h
 * @author gmlyytt@outlook.com
 * @date 2018/10/30 20:52:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_380_INSERT_DELETE_GETRANDOM_O_1_H
#define INC_1STPROGRAM_LEETCODE_380_INSERT_DELETE_GETRANDOM_O_1_H

#include "../util/header_util.h"

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        s.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (s.count(val)) {
            return false;
        }
        s.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (s.count(val)) {
            s.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto iter = s.begin();
        int k = rand() % s.size();
        while (k) {
            ++iter;
            --k;
        }
        return *iter;
    }

private:
    unordered_set<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

void test_random_set() {
    RandomizedSet obj = new RandomizedSet();
    bool param_1 = obj.insert(val);
    bool param_2 = obj.remove(val);
    int param_3 = obj.getRandom();
}

#endif //INC_1STPROGRAM_LEETCODE_380_INSERT_DELETE_GETRANDOM_O_1_H
