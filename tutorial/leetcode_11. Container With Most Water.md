## 题意

Given *n* non-negative integers *a1*, *a2*, ..., *an* , where each represents a point at coordinate (*i*, *ai*). *n* vertical lines are drawn such that the two endpoints of line *i* is at (*i*, *ai*) and (*i*, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**Note:** You may not slant the container and *n* is at least 2.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

**Example:**

```
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
```

## 思路 & 实现

### 1. 双指针法

#### **算法思路**

定义left指针指向数组的最左侧，right指针指向数组的最右侧，而后两指针以指定的条件向中间靠拢，靠拢停止的条件是两指针碰到一起，靠拢的条件如下所示：

1. 如果height[left] < height[right]，则++left，这是因为使更矮的那一段向中间靠拢才有可能有机会得到最大的围拢面积，这里会产生一个困扰，就是当遍历的过程中，如果height[left] < height[right]，为什么不--left，这是因为left左边和right右边能够围成的最大面积已经被计算过了，因而只能往中间靠拢才有可能找到更大的面积；
2. 如果height[left] >= height[right]，则--right，原理同上。

算法的C++代码如下所示：

```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = INT_MIN;
        
        while (left < right) {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        
        return max_area;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(1)`。