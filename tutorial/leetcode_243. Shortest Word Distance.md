## 题意

Given a list of words and two words *word1* and *word2*, return the shortest distance between these two words in the list.

For example,
Assume that words = `["practice", "makes", "perfect", "coding", "makes"]`.

Given *word1* = `“coding”`, *word2* = `“practice”`, return 3.
Given *word1* = `"makes"`, *word2* = `"coding"`, return 1.

Note:
You may assume that *word1* does not equal to *word2*, and *word1* and *word2* are both in the list.

## 思路 & 实现

### 1. 双指针

算法思路比较直接，如下：

1. 用`p1`记录`word1`所在的位置，p2记录`word2`所在的位置，这两个变量被初始化为-1。
2. 遍历数组，当遍历到`word1`时，`p1`指向当前位置；当遍历到`word2`时，`p2`指向当前位置。当`p1`和`p2`都不为-1的时候，记录下`p1`和`p2`之间的最短距离，即为最终答案。

如下是C++的实现方式。

```C++
int shortestDistance(vector<string>& words, string word1, string word2) {
    if (words.empty() || word1 == word2) {
        return -1;
    }

    int p1 = -1;
    int p2 = -1;
    int result = INT_MAX;

    for (int index = 0; index < words.size(); ++index) {
        if (words[index] == word1) {
            p1 = index;
        } else if (words[index] == word2) {
            p2 = index;
        } else {
        		// do nothing
        }
        if (p1 != -1 && p2 != -1) {
            result = min(result, abs(p1 - p2));
        }
    }

    return result;
}
```

### 时空复杂度

时间复杂度：`O(n)`。

空间复杂度：`O(1)`，没有用到额外的辅助空间。

### 2. 双指针升级版 -> 单指针

只用一个辅助变量解决问题，如下是正确思路的C++实现方式。

```C++
int shortestDistance_advanced(vector<string>& words, string word1, string word2) {
    if (words.empty() || word1 == word2) {
        return -1;
    }
    int result = INT_MAX;

    int outer_index = -1;

    for (int inner_index = 0; inner_index < words.size(); ++inner_index) {
        if (words[inner_index] == word1 || words[inner_index] == word2) {
          	// 当outer_index != -1时，证明outer_index已经指向word1或者word2，
          	// 而inner_index现在等于word1或者word2，且words[inner_index] != words[outer_index]，
          	// 证明inner_index和outer_index分别指向word1和word2，这时就需要记录result。
            if (outer_index != -1 && words[inner_index] != words[outer_index]) {
                result = min(result, abs(outer_index - inner_index));
            }
            outer_index = inner_index;
        }
    }

    return result;
}
```

### 时空复杂度

时间复杂度：`O(n)`。

空间复杂度：`O(1)`。