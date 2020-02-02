## 题意

This is a follow up of [Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance). The only difference is now you are given the list of words and your method will be called *repeatedly* many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words *word1* and *word2* and return the shortest distance between these two words in the list.

For example,
Assume that words = `["practice", "makes", "perfect", "coding", "makes"]`.

Given *word1* = `“coding”`, *word2* = `“practice”`, return 3.
Given *word1* = `"makes"`, *word2* = `"coding"`, return 1.

Note:
You may assume that *word1* does not equal to *word2*, and *word1* and *word2* are both in the list.

## 思路 & 实现

### 1. has map思想

#### **算法思路**

沿用原先[**Shortest Word Distance**](https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode_243.%20Shortest%20Word%20Distance.md)的做法是没有问题的，这里提供一个用空间来换时间的算法，可以将算法的**平均时间复杂度**降到更低，算法思路比较直接，如下：

1. 类`WordDistance`构造函数的输入为words，且类定义`unordered_map`类型的私有变量`m`, 储存的是`words`中不同元素出现的位置，因为`words`中可能存在重复元素，因而`unordered_map`的`second`的变量类型定义为`vector<int>`。
2. 在提取最短距离的函数`shortestDistanceII`中，定义`i`和`j`两个指针，指向的是遍历`m`过程中`word1`和`word2`出现的位置。
3. 第2步的遍历过程中完成两件事：记录最短距离`result`，更新`i`和`j`，更新`i`和`j`的方法是看`m[word1][i]`和`m[word][j]`哪个小，小的一方先前近一步，这样做的原因是试图记录更小的最短距离，因为只有将小的位置向大的位置靠拢，才能使得有机会记录更小的result。

如下是C++的实现方式。

```C++
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int length = words.size();
        for (int i = 0; i < length; ++i) {
            m[words[i]].emplace_back(i);
        }
    }

    int shortestDistanceII(string word1, string word2) {
        int i = 0;
        int j = 0;
        int result = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            result = min(result, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
        }

        return result;
    }
    
private:
    unordered_map<string, vector<int>> m;
};
```

#### **时空复杂度**

**时间复杂度**：可以看出上述算法的最坏时间复杂度依然是`O(n-1)`，`n`为`words`的长度，能想到的testcase为`words{"practice", "practice", "practice", "coding"}`，`word1`为`"practice"`，`word2`为`"coding"`，可以发现上述算法在这个case上是需要将words所有的元素都遍历完成后才能得到`result`的。而最好的时间复杂度为`O(1)`，testcase很好找，`word1`和`word2`在`words`中都出现过一次就可以了，因而算法的时间`min(M, N)`，`M`代表的是`word1`在`words`中出现的次数，`N`代表的是`word2`在`words`中出现的次数。

综上所述，本文中的算法时间复杂度无论在何种情况下都要比[**Shortest Word Distance**](https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode_243.%20Shortest%20Word%20Distance.md)提供算法的时间复杂度要小，因为[**Shortest Word Distance**](https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode_243.%20Shortest%20Word%20Distance.md)提供算法无论如何都是要把数组遍历完成才行。

**空间复杂度**：`O(n)`，用到额外的辅助空间`m`来存储`words`中不同元素出现的位置。