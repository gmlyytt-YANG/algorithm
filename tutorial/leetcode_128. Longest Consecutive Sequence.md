## 题意

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(*n*) complexity.

**Example:**

```
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

## 思路 & 实现

### 1. 排序+stack

#### **算法思路**

对数组进行排序，通过栈的压入和弹出来记录最长的连续序列，思路较为简单。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int result = 0;
        sort(nums.begin(), nums.end());
        
        stack<int> stk;
        for (const auto& elem: nums) {
            while (!stk.empty() && elem != stk.top() + 1) {
                stk.pop();
            }
            stk.push(elem);
            result = max(result, (int)stk.size());
        }
        
        return result;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(nlgn)`。

**空间复杂度**：`O(n)`。

### 2. 排序+遍历记录

#### **算法思路**

对数组进行排序，在遍历过程中记录最长连续序列。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int current = 1;
        int longest = 1;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); ++i) {
          	// 一定要保证nums[i] != nums[i - 1]前提下统计最长连续序列
          	// 否则直接跳过
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    ++current;
                } else {
                    longest = max(current, longest);
                    current = 1;
                }
            }
        }
        
        return max(current, longest);
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(nlgn)`。

**空间复杂度**：`O(1)`。

### 3. Hash set

#### **算法思路**

1. 将数组的元素逐个push到s(hash set)中；
2. 遍历s，取出一个元素为num，当s中不包含num-1时进行第3步；
3. 令current_num=num，调用while循环，循环条件为s中包含current_num+1，如果满足该条件，则++current_num，直到不满足为止，在这个过程中记录最长连续序列的长度。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::set<int> s;
        
        for (const auto& elem: nums) {
            s.insert(elem);
        }
        
        int longest = 0;
        
        for (const auto& num: s) {
            if (s.count(num - 1) == 0) {
                int current_num = num;
                int current = 1;
                
                while (s.count(current_num + 1) > 0) {
                    ++current_num;
                    ++current;
                }
                
                longest = max(longest, current);
            }
        }
        
        return longest;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`，for循环中的while循环开始条件为连续序列的最左端，且最多循环n次，因而时间复杂度是线性的。

**空间复杂度**：`O(n)`。

