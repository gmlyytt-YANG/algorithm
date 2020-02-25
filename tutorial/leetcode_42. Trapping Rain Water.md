## 题意

Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![img](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!

**Example:**

```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

## 思路 & 实现

### 1. 暴力遍历

#### **算法思路**

遍历数组，从遍历当前位置向左寻找最大值max_left(包括自身)，向右寻找max_right(包括自身)，min(max_left, max_right) - height[i]即为当前位置可以存储的水量。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;

        for (int i = 0; i < height.size(); ++i) {
            int max_left = 0;
            int max_right = 0;
            for (int j = i; j >= 0; --j) {
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < height.size(); ++j) {
                max_right = max(max_right, height[j]);
            }
            
            result += min(max_left, max_right) - height[i];
        }
        
        return result;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n^2)`。

**空间复杂度**：`O(1)`。

### 2. 动态规划

#### **算法思路**

根据解法1中的思路，可以采用动态规划的形式保存遍历过程中每个位置对应的max_left和max_right，分别保存在两个数组max_left_arr和max_right_arr中，最后同时遍历height、max_left_arr和max_right_arr，得到最终结果。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int length = height.size();
        if (length == 0) {
            return 0;
        }
        
        vector<int> max_left_arr(length, 0);
        max_left_arr[0] = height[0];
        
        for (int i = 1; i < length; ++i) {
            max_left_arr[i] = max(max_left_arr[i - 1], height[i]);
        }
        
        vector<int> max_right_arr(length, 0);
        max_right_arr[length - 1] = height[length - 1];
        
        for (int i = length - 2; i >= 0; --i) {
            max_right_arr[i] = max(max_right_arr[i + 1], height[i]);
        }
        
      	// 1为左，length - 2为右是因为min(max_right_arr[i], max_left_arr[i])一定小于等于height[i]
        for (int i = 1; i < length - 1; ++i) {
            result += min(max_right_arr[i], max_left_arr[i]) - height[i];
        }
        
        return result;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(n)`。

### 3. 栈

#### **算法思路**

维护一个栈stk，这个栈中元素从底部到顶部是以此递减的，且栈中存储的是数组的下标。开始遍历数组，并将数组中的元素向栈中push，如果遇到当前元素比栈顶元素top小，则直接入栈，如果当前元素比top大，则弹出top，并记录distance和value，这样distance*value就是当前的局部result，之后不断地弹出栈顶元素，直到当前元素比栈顶元素小，才把当前元素放入到栈中，这样不断地累积局部result，则得到最终的result，distance和value的示意图如下所示：

![img](https://github.com/gmlyytt-YANG/img-repo/blob/master/github/leetcode_42.png)

算法的C++代码如下所示：

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int length = height.size();
        if (length == 0) {
            return 0;
        }
        
        std::stack<int> stk;
        
        int curr = 0;
        while (curr < length) {
            while (!stk.empty() && height[curr] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int distance = curr - stk.top() - 1;
                int value = min(height[curr], height[stk.top()]) - height[top];
                
                result += distance * value;
            }
            stk.push(curr++);
        }
        
        return result;
    }
};
```

### 4. 双指针

#### **算法思路**

和[leetcode_11. Container With Most Water](https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode_11.%20Container%20With%20Most%20Water.md)算法思路类似，定义左右指针left和right，**如果height[left]<height[right]，则需要让left++才有可能找到比height[right]更高的位置从而能够储存水，反之则需要让right--才有可能找到比height[left]更高的位置从而能够储存水**，在left++的过程中，如果发现有局部储存水的可能性，即height[left] < 已有的max_left，则记下当前的存水量，而在right--的过程中也可以局部存水。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        
        int max_left = 0;
        int max_right = 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= max_left ? (max_left = height[left]) : (result += max_left - height[left]);
                ++left;
            } else {
                height[right] >= max_right ? (max_right = height[right]) : (result += max_right - height[right]);
                --right;
            }
        }
        
        return result;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(1)`。

