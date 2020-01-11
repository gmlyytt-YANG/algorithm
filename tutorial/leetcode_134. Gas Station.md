## 题意
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
```
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```

## 思路 & 实现

从第一站开始计算剩余油量`left`，如果发现剩余油量小于0，则可以证明从第一站开始到当前站(i)的下一站(i+1)中间的任何一站都没有可以设置的起点(`start`)，因为如果从第一站起都没有办法走到i+1, 那么第一站与i+1中间的任何一站作为起点都没办法走到i+1，因而起点只可能从i+1开始寻找。

在从第一站开始遍历的过程中，还需要记录每次尝试寻找起点过程中欠下油量的累加和`lack`，遍历到最后需要看下剩余油量`left`和`lack`的加和是否大于0来判断是否存在起点`start`.

如下是C++的实现方式。

```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        if (length != cost.size() || length == 0) {
            return -1;
        }
        
        int left = 0;
        int lack = 0;
        int start = 0;
        
        for (int i = 0; i < length; ++i) {
            left += gas[i] - cost[i];
            if (left < 0) {
                start = (i + 1) % length;
                lack += left;
                left = 0;
            }
        }
        
        return (lack + left >= 0) ? start : -1;
    }
};
```

## 时空复杂度

时间复杂度：`O(n)`, 遍历一次数组即可

空间复杂度：`O(1)`, 没有利用额外的空间复杂度