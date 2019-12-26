## 题意
Given a string, find the length of the longest substring without repeating characters.
```
Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```
## 思路 & 实现

### 1. 快慢指针思想(sliding window)
定义快慢指针fast=0,slow=0，并且定义set,用于存放fast划过位置的不同元素。而后进行如下操作：

循环遍历fast和slow，
1. 如果nums[fast]没有在set中出现，则将nums[fast]push到set中，且fast++；
2. 如果nums[fast]在set中出现，则将nums[slow]从set中删掉，且slow++。

上述算法的精髓在于如果nums[fast]不在set中出现，则会一直删除nums中的元素，直到slow与fast之间没有与fast相同的元素时，才将nums[fast]重新push到set中。

如下是C++的实现方式。

```C++
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int slow = 0;
        for (int fast = 1; fast < length; ++fast) {
            if (nums[slow] != nums[fast]) {
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
```

> 时间复杂度：O(2n), slow和fast至多遍历n步

> 空间复杂度：O(n), 最坏情况是nums中没有重复的元素

