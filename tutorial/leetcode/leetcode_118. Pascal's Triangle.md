## 题意

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

```
Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

## 思路 & 实现

简单的动态规划解决问题，动态规划的公式为`result[j][index] = result[j - 1][index - 1] + result[j - 1][index]`。另外，需要特别注意的是边界问题，即开始遍历和停止遍历的边界判断。

如下是C++的实现方式。

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        if (numRows <= 0) {
            return results;
        }
        
        for (int index = 0; index < numRows; ++index) {
            vector<int> row(index + 1, 1);
            for (int inner_index = 1; inner_index < index; ++inner_index) {
                row[inner_index] = results[index - 1][inner_index - 1] 
                        + results[index - 1][inner_index];
            }
            results.emplace_back(row);
        }
        
        return results;
    }
};
```

## 时空复杂度

时间复杂度：`O(n^2) `, 遍历的次数为1+2+...+numRows-1=numRows(numRows - 1) / 2，因而时间复杂度为O(n^2)。

空间复杂度：`O(n^2) `, 结果是二维数组。

