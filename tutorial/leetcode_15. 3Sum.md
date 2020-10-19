## 题意

Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

**Example 1:**

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

**Example 2:**

```
Input: nums = []
Output: []
```

**Example 3:**

```
Input: nums = [0]
Output: []
```

**Constraints:**

- `0 <= nums.length <= 3000`
- `-105 <= nums[i] <= 105`

## 思路 & 实现

### 1. 排序 + 双指针法

#### **算法思路**

1. 为了满足"不重复"的要求，需要对数组进行升序排序
2. 定义k，用于遍历数组，在遍历数组过程中，如果遇到nums[k] == nums[k - 1]时，需要跳过，因为这会引入"重复"
3. 在遍历过程中，定义双指针i(k + 1)和j(nums_len - 1)，如果k、i、j这三个下标对应的数组元素之和为0，则将结果记录下来，如果中间出现重复，则跳过

算法的Python代码如下所示：

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums or len(nums) == 0:
            return []
        
        nums = sorted(nums)
        nums_len = len(nums)
        
        if nums[0] > 0 or nums[nums_len - 1] < 0:
            return []
        
        result = []
        
        for k in range(nums_len - 1):
          	# 0的限制
            if nums[k] > 0:
                break
            # 不重复
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            i = k + 1
            j = nums_len - 1
            target = -nums[k]
            while i < j:
                if nums[i] + nums[j] == target:
                    result.append([nums[k], nums[i], nums[j]])
                    # 不重复
                    while i < j and nums[i] == nums[i + 1]:
                        i += 1
                    while i < j and nums[j] == nums[j - 1]:
                        j -= 1
                    i += 1
                    j -= 1
                elif nums[i] + nums[j] < target:
                    i += 1
                else:
                    j -= 1
                    
        return result                    
```

#### **时空复杂度**

**时间复杂度**：`O(n^2)`。

**空间复杂度**：`O(1)`。