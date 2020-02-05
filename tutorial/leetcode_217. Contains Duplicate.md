## 题意

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**Example 1:**

```
Input: [1,2,3,1]
Output: true
```

**Example 2:**

```
Input: [1,2,3,4]
Output: false
```

**Example 3:**

```
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
```

## 思路 & 实现

### 1. has map思想

#### **算法思路**

算法的思路直截了当，直接给出C++代码。

```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (const auto& elem: nums) {
            if (m.count(elem) > 0) {
                return true;
            }
            m.insert(elem);
        }
        
        return false;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(n)`，用到额外的辅助空间`m`来存储`nums`中不同元素。