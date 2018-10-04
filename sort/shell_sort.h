#ifndef _SHELL_SORT_H
#define _SHELL_SORT_H

#include <iostream>
#include <vector>

void shell_sort(std::vector<int>& arr) {
    int gap = arr.size() / 2;
    while (gap > 0) {
        for (int group_index = 0; group_index < gap; ++group_index) {
            for (int j = group_index + gap; j < arr.size(); j += gap) {
                int key = arr[j];
                int i = j - gap;
                while (i >= 0 && arr[i] > arr[i + gap]) {
                    arr[i + gap] = arr[i];
                    i -= gap;
                }
                arr[i + gap] = key;
            }
        }
        gap /= 2;
    }
}

void test_shell_sort() {
    std::vector<int> arr = {3, 4, 5, 1, 7, 8, 9};
    shell_sort(arr);
    for (auto& elem : arr) {
        std::cout << elem << std::endl;
    }
}

#endif