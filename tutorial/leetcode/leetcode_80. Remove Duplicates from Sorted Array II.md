## 题意
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
```
Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
```
## 思路 & 实现

### 1. 快慢指针思想
定义快慢指针fast=1,slow=0，定义count用于相同元素的计数器，初始化为1。

for循环遍历fast指针，

1. 如果fast指向的元素nums[fast]等于nums[slow]且count=1，则将nums[fast]赋值给nums[slow+1], 且slow向后移动一步。
2. 如果fast指向的元素nums[fast]大于nums[slow]，则将nums[fast]赋值给nums[slow+1], 且slow向后移动一步。 

上述方法的精髓在于**如果nums[fast]等于nums[slow]且count>1，这时slow不动，fast继续向后移动**，直到fast移动到一个位置，使得nums[fast]>nums[slow]。

如下是C++的实现方式。

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int slow = 0;
        int count = 1;
        for (int fast = 1; fast < length; ++fast) {
            if (nums[fast] == nums[slow]) {
                if (count == 1) {
                    ++slow;
                    nums[slow] = nums[fast];
                    ++count;
                }
            } else {
                ++slow;
                nums[slow] = nums[fast];
                count = 1;
            }
        }
        return slow + 1;
    }
};
```

> 时间复杂度：O(2n), slow和fast至多遍历n步

> 空间复杂度：O(1), 没有利用额外的空间复杂度

