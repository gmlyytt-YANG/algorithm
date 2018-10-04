//
// Created by Li,Yang(Duer04) on 2018/7/16.
//

#ifndef INC_1STPROGRAM_SORTCOLORS_HPP
#define INC_1STPROGRAM_SORTCOLORS_HPP
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector<int>& nums) {
        for (auto elem: nums)
            cout << elem << " ";
        cout << endl;
    }

    void sortColors(vector<int>& nums) {
        auto length = static_cast<int>(nums.size());
        if (length <= 1)
            return;
        int head=0, tail=length-1;
        for (int i=0; i<=tail; ++i) {
            if (nums[i] == 2)
                swap(nums[i--], nums[tail--]);
            else if (nums[i] == 0)
                swap(nums[i], nums[head++]);
            print(nums);
        }
    }
};
#endif //INC_1STPROGRAM_SORTCOLORS_HPP
