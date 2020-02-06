## 题意

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**Example:**

```
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Note:**

You can assume that you can always reach the last index.思路 & 实现

### 1. 扩大边界法

#### **算法思路**

首先要说明的是，这个题的潜在含义是一定存在一种跳法，可以从位置0跳到位置-1，该题解析思路依然是贪心算法。这里说明一下，如下算法中当前停留位置`location`和遍历位置`i`要区分开来。

1. 用`i`遍历数组`nums`，**直到`nums[-2]`时停止**，
2. 定义`result`，用于记录`location`跳到位置-1所需要的最小步数，初始化为0；定义`cur_max_area`，用于记录**当遍历到`i`时`location`从位置0能够到达的最远位置**；定义`max_next`，用于记录**`location`跳到[位置0, 位置`cur_max_area`]之间而后再往后跳一步能跳到的最远位置**，
3. 在`i`遍历过程中，如果遍历到`cur_max_area`，证明`i`已经走到当前最远的边界了，那么就把`max_next`作为新的边界(将`max_next`赋值给`cur_max_area`)，这时**`location`跳到能够跳两步就跳到`max_next`时中间一步的位置**，`++result`，

上述算法中之所以让i遍历到`nums[-2]`时停止，是因为如果遍历到`nums[-1]`时停止的话，如果遇到最后的cur_max_area正好是`nums.size() - 1`，且i已经遍历到最后位置-1，则会导致多跳一步，正如题目中的构造case。

```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } 
        
        int result = 0;
      	int cur_max_area = 0; 
        int max_next = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_next = max(max_next, nums[i] + i);
            if (i == cur_max_area) {
                cur_max_area = max_next;
                ++result;
            }
        }
        
        return result;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(1)`。