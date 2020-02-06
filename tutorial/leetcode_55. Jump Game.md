## 题意

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

## 思路 & 实现

### 1. 回溯法

#### **算法思路**

拿到题目，第一个想法是如果站在位置0时，尽可能往远的地方跳，最远处即为`0+nums[0]`处，但是这并不能解决问题，因为如果`nums[0+nums[0]]`为0的话，就没办法进行了，因而只能从0开始，先跳1步到达位置1，看下基于位置1能否根据一定的跳转策略达到`nums[-1]`，如果基于位置1不能跳到`nums[-1]`，则从0开始跳2步到达位置2，看下基于位置2能否根据一定的跳转策略达到`nums[-1]`...，这样的回溯法确实可以解决问题，但是在leetcode submit时超时，算法的C++代码如下所示：

```C++
class SolutionRecursion {
public:
    bool canJumpFromPosition(vector<int>& nums, int position) {
        if (position > nums.size() - 1) {
            return false;
        }
        
        if (position == nums.size() - 1) {
            return true;
        }
        
        int right_most_position = 
            std::min(position + nums[position], int(nums.size() - 1));
        for (int iter_position = position + 1; 
                iter_position <= right_most_position; ++iter_position) {
            if (canJumpFromPosition(nums, iter_position)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(nums, 0);
    }
};
```

#### **时空复杂度**

**时间复杂度**：`O(2^n)`，证明省略，重点关注的是回溯法的时间复杂度是指数级。

**空间复杂度**：`O(n)`，递归调用栈。

### 2. 回溯动态规划

#### **算法思路**

算法1中的回溯法中有很多重复的步骤，比如从位置0跳到位置1，以位置1为基础，再跳到位置2，再以位置2为基础往下跳时，和从位置0跳到位置2再以位置2为基础往下跳的过程是重复的。基于此，可以运用动态规划的思想，保存从位置0跳到位置1然后跳到位置2之后以位置2为基础往下跳之后的状态，之后每次跳到位置2然后再往下跳时则不用继续往下跳了，直接返回位置2的状态即可。但是这种算法在leetcode上依然超时，算法的C++代码如下所示：

```C++
class SolutionRecursionDP {
public:
    bool canJumpFromPosition(vector<int>& nums, int position) {
      	// 如果position的状态被记录过，则直接返回
        if (mem[position] != "unk") {
        		return mem[position] == "good" ? true : false;
        }
        
        int right_most_position = 
            std::min(position + nums[position], int(nums.size() - 1));
        for (int iter_position = position + 1; 
                iter_position <= right_most_position; ++iter_position) {
            if (canJumpFromPosition(nums, iter_position)) {
                mem[position] = "good";
              	return true;
            }
        }
        
        mem[position] = "bad";
      	return false;
    }
    
    bool canJump(vector<int>& nums) {
        mem = vector<string>(nums.size(), "unk");
        mem.back() = "good";
        return canJumpFromPosition(nums, 0);
    }
private:
  	// mem中记录每个位置的状态，状态分为good,bad,unk
  	// good是指从该位置开始能跳到nums[-1]，
  	// bad是指从该位置开始不能跳到nums[-1]，
  	// unk是指该位置的状态未知
    vector<string> mem;
};
```

#### **时空复杂度**

**时间复杂度**：`O(n^2)`，在每个位置向后遍历的过程中都会都会去寻找它右边的"good"，那么最坏的情况就是"good"所在的位置为nums.size() - 1，这里提供一个自己构造的case：[5, 3, 2, 1, 0, 1]。

**空间复杂度**：`O(n+n)`，第一个n代表的是递归调用栈，第二个n代表的是辅助内存mem。

### 3. 动态规划

#### **算法思路**

回溯动态规划法中要递归的原因是从前向后遍历的过程中，前面的元素是并不知道后面元素状态的，因而需要递归。如果采用从后向前遍历，则可以解决这个问题，因为从后向前遍历的过程中，元素i后面的状态已经获得了，因而无需递归，思路比较直接，但是依然超时，直接给出C++代码：

```C++
class SolutionDP {
public:
   bool canJump(vector<int>& nums) {
       if (nums.empty()) {
           return true;
       }
       vector<string> mem(nums.size(), "unk");
       mem.back() = "good";

       for (int i = nums.size() - 2; i >= 0; --i) {
           int position = min(i + nums[i], int(nums.size() - 1));
           for (int j = i + 1; j <= position; ++j) {
               if (mem[j] == "good") {
                   mem[i] = "good";
               }
           }
           mem[i] = mem[i] == "good" ? "good" : "bad";
       }

       return mem[0] == "good" ? true : false;
   } 
};
```

#### **时空复杂度**

**时间复杂度**：`O(n^2)`，双层遍历。

**空间复杂度**：`O(n)`，递归调用栈。

### 4. 贪心算法

#### **算法思路**

在某个位置既然已经知道其最大能跳到哪里去，而且从后向前遍历也能够解决从当前位置一下就能看到是否到达`nums[-1]`，因而就用最贪心的算法，从后向前遍历，每次都走最大步，这样就能见问题完美地解决。该算法的时间复杂度较小，因而能通过leetcode，C++代码如下：

```C++
class SolutionGreedy {
public:
   bool canJump(vector<int>& nums) {
       int last_position = nums.size() - 1;
       for (int i = nums.size() - 2; i >= 0; --i) {
           if (nums[i] + i >= last_position) {
           		 // 如果nums[i] + i >= last_position，
             	 // 则代表从位置i跳最大步nums[i]可以达到最后
               last_position = i;
           }
       }

       return last_position == 0 ? true : false;
   }
};
```

