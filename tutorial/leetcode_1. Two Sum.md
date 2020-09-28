## 题意

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly\* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

## 思路 & 实现

遍历数组，用map储存数组元素，遍历的过程中寻找符合要求的pair，如果发现则立即停止遍历

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) < 2:
            return []
        
        num_ctnr = dict()
        
        for idx, elem in enumerate(nums):
            if target - elem in num_ctnr:
                return [num_ctnr[target - elem], idx]
            num_ctnr[elem] = idx
                
        return []
```

## 时空复杂度

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(n)`。