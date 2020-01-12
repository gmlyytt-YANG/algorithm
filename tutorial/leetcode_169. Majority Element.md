## 题意

Given an array of size *n*, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.

**Example 1:**

```
Input: [3,2,3]
Output: 3
```

**Example 2:**

```
Input: [2,2,1,1,1,2,2]
Output: 2
```

## 思路 & 实现

### 1. [Boyer-Moore思想](https://www.cnblogs.com/gaochundong/p/boyer_moore_string_matching_algorithm.html)

通过`major_elem`来记录当前出现次数最多的元素，`count`记录的是`major_elem`被抵消之后剩余的统计次数，这里的抵消是**指出现`major_elem`后当当前位置，有多少个元素与`major_elem`不同**，而这里的抵消是通过`atom_counter`来完成的，如果当前元素与`major_elem`不同，则`atom_counter`为-1，相反为1。

如下是C++的实现方式。

```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major_elem = 0;
        for (const auto& elem: nums) {
            if (count == 0) {
                major_elem = elem;
            }
            
            // 如果count == 0或者elem == major_elem
            // atom_counter都等于1
            int atom_counter = 1;
            
            // 否则atom_counter等于-1
            if (elem != major_elem) {
                atom_counter = -1;
            }
            
            count += atom_counter;
        }
        
        return major_elem;
    }
};
```

## 时空复杂度

时间复杂度：O(n)

空间复杂度：O(1)