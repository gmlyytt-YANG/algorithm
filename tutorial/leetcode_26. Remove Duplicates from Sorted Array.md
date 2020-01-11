## 题意
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
```
Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
```
## 思路 & 实现

### 1. 快慢指针思想
定义快慢指针fast=1,slow=0。**将符合要求的元素(与slow不相同的fast指针指向的元素)直接拉到slow的后面**，且slow向后移动一步，这样就能保证slow所扫过的地方都是不重复的元素。

如下是C++的实现方式。

```C++
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int slow = 0;
        for (int fast = 1; fast < length; ++fast) {
            if (nums[slow] != nums[fast]) {
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
```

> 时间复杂度：O(2n), slow和fast至多遍历n步

> 空间复杂度：O(1), 没有利用额外的空间复杂度

