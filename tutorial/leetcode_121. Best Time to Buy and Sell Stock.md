## 题意

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

**Example 1:**

```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

**Example 2:**

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

## 思路 & 实现

### 1. 极值法

#### **算法思路**

遍历数组的过程中，首先判断当前位置是否是数组的极小值，如果是的话，刷新极小值，如果不是的话，看下当前值减去极小值是否大于当前的最大利益，如果是的话，更新最大利益，图示如下所示，

![](https://leetcode.com/media/original_images/121_profit_graph.png)

算法的C++代码如下所示：

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int max_profit = 0;
        int min_price = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            } 
        }
        
        return max_profit;
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(n)`。

**空间复杂度**：`O(1)`。