## 题意
Given an unsorted integer array, find the smallest missing positive integer.

```
Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
```

## 思路 & 实现

### 1. 对应位置排序后找异常点 

算法的思路大致如下：
1. 遍历数组`nums[i]`，将元素放到其本应该放到的位置
    1. 如果`0 < nums[i] <= length` 且 `nums[i] != nums[nums[i] - 1]`(`nums[i]`和对应位置的元素不相同)， 则交换`nums[i]`和`nums[nums[i] - 1]`
    2. 如果`nums[i]`不在(0, length]范围内，或者`nums[i]`本身已经放置了正确的元素，或者`nums[i] == nums[nums[i] - 1]`, 则直接`++i`

2. 找到异常点

    经过第1步，已经将符合要求的元素放置到了正确的位置，之后再次遍历数组，找到不符合要求的异常点(元素不在(0, length]范围内)即能得到最终答案。
如下是C++的实现方式。

3. 特殊情况

    如果数组中没有异常点，则直接返回length+1。

```C++
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int length = nums.size();
        int index = 0;
        
        // put the element in the right place
        while (index < length) {
            if (nums[index] > 0 && nums[index] <= length
                    && nums[index] != nums[nums[index] - 1]) {
                int x = nums[index];
                nums[index] = nums[x - 1];
                nums[x - 1] = x;
            } else if (nums[index] <= 0 || nums[index] > length
                    || nums[index] == index + 1 
                    || nums[index] == nums[nums[index] - 1]) {
                ++index;
            }
        }
        
        // find the Outlier
        for (int index = 0; index < length; ++index) {
            if (nums[index] != index + 1) {
                return index + 1;
            }
        }
        
        // there is no Outlier in nums
        return length + 1;
    }
};
```

> 时间复杂度：O((x+1)*n), 线性时间内遍历数组, x代表的是将符合要求的元素放置到正确的位置所需时间，1代表的是最终遍历数组找到异常点的时间复杂度

> 空间复杂度：O(1),没有引入额外的空间复杂度


## 参考
[leetcode参考](https://leetcode.com/problems/first-missing-positive/discuss/464487/Simple-Python-O(n)-time-O(1)-space-(convert-input-array-to-hashtable)
