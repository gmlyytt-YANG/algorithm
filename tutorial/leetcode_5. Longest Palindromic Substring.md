## 题意

Given a string `s`, return *the longest palindromic substring* in `s`.

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"
```

**Example 3:**

```
Input: s = "a"
Output: "a"
```

**Example 4:**

```
Input: s = "ac"
Output: "a"
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consist of only digits and English letters (lower-case and/or upper-case),

## 思路 & 实现

### 动态规划

状态转移方程为：
$$
\left\{\begin{array}{l}
dp[i][i] = True\\ 
dp[i][i + 1] = (s[i] == s[i + 1])\\ 
dp[i][j] = (s[i] == s[j]) and dp[i + 1][j -1]
\end{array}\right.
$$

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans = ""
        
        for l in range(n):
            for i in range(n - l):
                j = i + l
                if l == 0:
                    dp[i][j] = True
                elif l == 1:
                    dp[i][j] = (s[i] == s[j])
                else:
                    dp[i][j] = (s[i] == s[j] and dp[i + 1][j - 1])
                if dp[i][j] and l + 1 > len(ans):
                    ans = s[i:i + l + 1]
                    
        return ans
```

#### 时空复杂度

*时间复杂度**：`O(n^2)`。

**空间复杂度**：`O(n^2)`。

### 回文状态遍历

通过找到所有的回文状态，从而得到最长的回文串

```Python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        start = 0
        end = 0
        
        for i in range(n - 1):
            left1, right1 = self.expand(s, i, i)
            left2, right2 = self.expand(s, i, i + 1)
            if right1 - left1 > end - start:
                end = right1
                start = left1
            if right2 - left2 > end - start:
                end = right2
                start = left2
            
        return s[start: end + 1]
    
    def expand(self, s, left, right):
        while (left >= 0 and right < len(s) \
               and left <= right and s[left] == s[right]):
            left -= 1
            right += 1
        
        return left + 1, right - 1
        
```

#### 时空复杂度

*时间复杂度**：`O(n^2)`。

**空间复杂度**：`O(1)`。

