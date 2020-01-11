## 题意
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

```
Example:

Input: 3
Output: [1,3,3,1]
```

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

## 思路 & 实现

复杂一些的动态规划解决问题，[动态规划公式](https://github.com/gmlyytt-YANG/algorithm/issues/2)依旧为`result[j][index] = result[j - 1][index - 1] + result[j - 1][index]`。

如果采用空间复杂度为O(k)的算法的话，必须将上述的二维数组压缩为一维。但如果依旧采用从前到后的遍历方法的话，则会导致值覆盖的情况。根据上述描述，很容易想到从后向前遍历，这样就能保证前后两次的值不会因为遍历而被覆盖了。

如下是C++的实现方式。

```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int>();
        }
        
        vector<int> result(rowIndex + 1, 1);
        
        for (int i = 1; i < rowIndex + 1; ++i) {
            for (int j = i - 1; j > 0; --j) {
                // 核心思想，从后向前遍历，不会产生值覆盖的情况。
                result[j] = result[j] + result[j - 1];
            }
        }
        
        return result;
    }
};
```

## 时空复杂度

时间复杂度：O(n^2)。

空间复杂度：O(n)。