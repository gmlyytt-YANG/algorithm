## 题意

Given a list of words and two words *word1* and *word2*, return the shortest distance between these two words in the list.

*word1* and *word2* may be the same and they represent two individual words in the list.

Example:
Assume that words = `["practice", "makes", "perfect", "coding", "makes"]`.

```
Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
```

Note:
You may assume *word1* and *word2* are both in the list.

## 思路 & 实现

### 1. 双指针升级版 -> 单指针

#### **算法思路**

和[**Shortest Word Distance**](https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode_243.%20Shortest%20Word%20Distance.md)唯一不同的地方是添加了一个`word1 == word2`的限制条件，如下是正确思路的C++实现方式。

```C++
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (words.empty()) {
            return -1;
        }

        int outer_index = -1;
        int result = INT_MAX;

        for (int inner_index = 0; inner_index < words.size(); ++inner_index) {
            if (outer_index != -1 && (word1 == word2 || words[inner_index] != words[outer_index])) {
                result = min(result, abs(outer_index - inner_index));
            }
        }
        outer_index = inner_index;
    }

    return result;
};
```

### 时空复杂度

时间复杂度：`O(n)`。

空间复杂度：`O(1)`。