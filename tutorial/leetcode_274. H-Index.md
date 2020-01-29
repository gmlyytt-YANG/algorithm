## 题意

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index *h* if *h* of his/her *N* papers have **at least** *h* citations each, and the other *N − h* papers have **no more than** *h* citations each."

**Example:**

```
Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
```

**Note:** If there are several possible values for *h*, the maximum one is taken as the h-index.

## 思路 & 实现

这道题首先需要明确题意，需要深刻理解"A scientist has index *h* if *h* of his/her *N* papers have **at least** *h* citations each, and the other *N − h* papers have **no more than** *h* citations each."这句话的含义，其具体含义可以借助下图来辅助理解。

![](/Users/liyang98/Work/个人资料/code/img-repo/github/leetcode_274.png)

题目中的例子不是特别形象，更为形象的例子为如果`citations = [6, 7, 8]`, 则`Output`应该为3，因为大于等于3的paper的数量是3篇，而大于等于4的paper的数量是3篇，因而4不符合要求，3才是`Output`。

### 1. 辅助内存

这里设`length = citations.size()`，算法思想如下：

1. 设置长度为`length + 1`的数组`table`，**`table[i]`的意义是`citations`中数值为`i`的元素的个数**，**`table.back()`储存的是`citations`中超过`length`的元素的个数**。
2. 从后向前遍历`table`，记录从table的最后一个元素到遍历的当前元素`table[i]`的累加和，如果累加和大于等于`i`的话，则代表`i`为`Output`。
3. 在第2步中如果没有找到合适的`i`，则返回0。

如下是C++的实现方式。

```C++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if (length == 0) {
            return 0;
        }
        
      	// 遍历citations，构建table
        vector<int> table(length + 1, 0);
        for (const auto& elem: citations) {
            if (elem >= length) {
                ++table[length];
            } else {
                ++table[elem];
            }
        }

      	// 从后向前遍历table，找到目标值
        int result = 0;
        for (int i = length; i >= 0; --i) {
            result += table[i];
            if (result >= i) {
                return i;
            }
        }
        
        return result;
    }
};
```

### 时空复杂度

时间复杂度：`O(n)`。

空间复杂度：`O(n)`，因为有辅助内存`table`。

### 2. 排序后统计

算法思想如下所示：

1. 对`citations`进行降序排序。
2. 找到排序后citations符合如下条件的**最右边元素**，即为Output，条件为 `citations[i] >= i + 1`。

上述算法思想比较直截了当，但之前我自己做了一次错误的探索，探索出的算法思想如下：

1. 对`citations`进行升序排序。
2. 找到排序后citations符合如下条件的**最右边元素的位置 + 1**，即为Output，条件为 `citations[i] <= length - i`。

但这样的思路是错误的，因为该思路**忽略了citations中有超过citations.size()的元素**(testcase为`citations = [6, 7, 8]`)。

如下是正确思路的C++实现方式。

```C++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if (length == 0) {
            return 0;
        }
        
        int result = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        
        int i = 0;
        for (int i = 0; i < length; ++i) {
            if (citations[i] >= i + 1) {
                result = i + 1;
            }
        }
        
        return result;
    }
};
```

### 时空复杂度

时间复杂度：`O(nlogn)`。

空间复杂度：`O(1)`。