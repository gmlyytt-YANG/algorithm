## 题意

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

> Return true if there exists *i, j, k*
> such that *arr[i]* < *arr[j]* < *arr[k]* given 0 ≤ *i* < *j* < *k* ≤ *n*-1 else return false.

**Note:** Your algorithm should run in O(*n*) time complexity and O(*1*) space complexity.

**Example 1:**

```
Input: [1,2,3,4,5]
Output: true
```

**Example 2:**

```
Input: [5,4,3,2,1]
Output: false
```

## 思路 & 实现

### 1. min max指针

#### **算法思路**

定义min_index(初始化为-1)和max_index(初始化为-1)，分别指向**当前全局最小值和当前局部最大值**，算法比较直截了当，C++代码如下所示：

```C++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max_index = -1;
        int min_index = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
          	// 当max_index != -1时，说明之前已经存在局部最大值且存在全局最小值了，
          	// 如果这时nums[i] > nums[max_index]，
          	// 说明nums[i] > nums[max_index] > nums[min_index]，
          	// 符合条件，直接返回
            if (max_index != -1 && nums[i] > nums[max_index]) {
                return true;
            }
            
            if (min_index == -1) {
                min_index = i;
                continue;
            }
            
            if (nums[i] > nums[min_index]) {
              	// 只有当nums[i] > nums[min_index] 且 nums[i] < nums[max_index]，
              	// 才会更新max_index为i,这时能保证max_index指向的是局部最大值
                if (max_index == -1 || nums[i] < nums[max_index]) {
                    max_index = i;
                }
            } else if (nums[i] < nums[min_index]) {
                min_index = i;
            }
        }
        
        return false;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(1)`。

### 2. 直接遍历

#### **算法思路**

算法较为简单，C++代码如下所示：

```C++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_min = INT_MAX;
        int second_min = INT_MAX;
        
        for (const auto& elem: nums) {
          	// 注意这里是<=，而不是<，<则有可能存在"等于"的情况
            if (elem <= first_min) {
                first_min = elem;
            } else if (elem <= second_min) {
                second_min = elem;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(1)`。

