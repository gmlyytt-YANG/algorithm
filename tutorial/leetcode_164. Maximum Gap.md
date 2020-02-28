## 题意

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

**Example 1:**

```
Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
```

**Example 2:**

```
Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

**Note:**

- You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
- Try to solve it in linear time/space.

## 思路 & 实现

### 1. 排序+遍历

#### **算法思路**

思路很简单，先排序，之后计算相邻两个数的最大差异，而且个人觉得并没有很大的必要研究Solution中提供的[高深的桶排序的算法](https://leetcode.wang/leetcode-164-Maximum-Gap.html)，因为面试中基本不可能考出这么有难度的题，算法的C++代码如下所示：

```C++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int result = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); ++i) {
            result = max(result, nums[i] - nums[i - 1]);
        }
        
        return result;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(nlogn)`。

**空间复杂度**：`O(1)`。

