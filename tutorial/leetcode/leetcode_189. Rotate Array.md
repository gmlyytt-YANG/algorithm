## 题意
Given an array, rotate the array to the right by k steps, where k is non-negative.

```
Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```
## 思路 & 实现

### 1. 循环拷贝
从第一个元素开始，以k为步长，循环向后移位。但这里有一种特殊情况，即如果循环移位时出现该移位的位置已经移动过了，这时需要向后错一位，之后继续循环移位，直到所有的元素都移动完成(这时已经移动了length次)。

如下是C++的实现方式。

```C++
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        // 如果这里不添加k % length == 0条件，
        // 则后续进入index == start条件时会出core
        // 而且从常理推理，如果k是length的倍数，
        // 则不需要再进行移位了，直接返回就行
        if (length <= 1 || k % length == 0) {
            return;
        }
        int start = 0;
        int pre = nums[0];
        int cur = nums[0];
        int index = 0;
        for (int i = 0; i < length; ++i) {
            pre = cur;
            index = (index + k) % length;
            cur = nums[index];
            nums[index] = pre;
            if (index == start) {
                ++start;
                index = start;
                cur = nums[index];
            }
        }
    }
};
```

> 时间复杂度：O(n)

> 空间复杂度：O(1)

### 2. 旋转三次数组
较为成熟的方法，不再多说，需要注意的是，在进行旋转之前，必须要对k进行length的取余操作，不然会出现旋转失败的问题。

```
class Solution {
public:
    void rotate2(vector<int> &nums, int k) {
        int length = nums.size();

        if (length == 0) {
            return;
        }
        k %= length; // 必要操作
        std::reverse(nums.begin(), nums.begin() + length - k);
        std::reverse(nums.begin() + length - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};
```
> 时间复杂度：O(n)

> 空间复杂度：O(1)

