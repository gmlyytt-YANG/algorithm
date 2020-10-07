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

### 1. 滑动窗口思想

定义指针i=0,j=0，并且定义set,用于存放nums[j]。而后进行如下操作：

循环遍历j，如果nums[j]在set中，则删除nums[i]，且i++，否则将nums[j]放入set中，且j++，且记录最大不重复子字符串的长度。

```Python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        j = 0
        n = len(s)
        result = 0
        
        ctnr = set()
        
        while i < n and j < n:
            if s[j] in ctnr:
                ctnr.remove(s[i])
                i += 1
                continue
            ctnr.add(s[j])
            j += 1
            result = max(result, j - i)
                
        return result
```

> 时间复杂度：O(2n)，因为i和j都有可能遍历一遍

> 空间复杂度：O(n), 最坏情况是nums中没有重复的元素

### 2. 滑动窗口跳跃思想

定义指针i=0,j=0，并且定义dict,用于存放j划过位置的不同元素。而后进行如下操作：

循环遍历j，将nums[j]以及j+1以key-value的形式存入dict中，如果nums[j]在dict中出现过，则i直接跳到dict[nums[j]]的位置上，之后记录最大不重复子字符串的长度，这样的好处是省略了思路1中的不必要的计算。


如下是Python的实现方式。

```Python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        ctnr = dict()
        
        i = 0
        result = 0
        for j in range(n):
            if s[j] in ctnr:
                i = max(i, ctnr[s[j]])
                
            result = max(result, j - i + 1)
            ctnr[s[j]] = j + 1
            
        return result
        
```

> 时间复杂度：O(n)

> 空间复杂度：O(n), 最坏情况是nums中没有重复的元素
