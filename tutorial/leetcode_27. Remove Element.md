## 题意
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

```
Example 1:
    
    Given nums = [3,2,2,3], val = 3,
    
    Your function should return length = 2, with the first two elements of nums being 2.
    
    It doesn't matter what you leave beyond the returned length.
Example 2:
    
    Given nums = [0,1,2,2,3,0,4,2], val = 2,
    
    Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
```
## 思路 & 实现

### 1. 快慢指针思想
将符合要求的元素(与val不相同的元素)直接移动到前面。

如下是C++的实现方式。

```C++
class Solution {
public:
    int removeElement_slow_fast_pointer(vector<int> &nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        return slow;
    }
};
```
如下为Python的实现方式。
```python
class Solution:
    def removeElement_slow_fast_pointer(self, nums, val):
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow
```
这种算法的适用条件在于当数组中有很多元素都和val相同时，这个算法的效率较高。

> 时间复杂度：O(n), slow和fast至多遍历n步

> 空间复杂度：O(1), 没有利用额外的空间复杂度

### 2. 双指针思想
和第一种方法类似，基本思想也是将符合要求的元素(与val不相同的元素)移动到前面，但是j指针首先指向的是数组的尾部，而不是头部。

如下是C++ 的实现方式。
```C++
class Solution {
public:
    int removeElement_low_high_pointer(vector<int> &nums, int val) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] == val) {
                nums[low] = nums[high];
                --high;
            } else {
                ++low;
            }
        }
        return low;
    }
};
```
这种算法的适用条件在于当数组中有很少元素都和val相同时，这个算法的效率较高。

> 时间复杂度：O(n), low和high至多遍历n步

> 空间复杂度：O(1), 没有利用额外的空间复杂度
