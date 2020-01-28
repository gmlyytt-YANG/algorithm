## 题意

Given an integer array of size *n*, find all elements that appear more than `⌊ n/3 ⌋` times.

**Note:** The algorithm should run in linear time and in O(1) space.

**Example 1:**

```
Input: [3,2,3]
Output: [3]
```

**Example 2:**

```
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
```

## 思路 & 实现

### 1. 双指针思想

算法思想如下：

1. 对数组`nums`进行升序排序，这样做的目的是让**所有相同元素位置相邻**。
2. 定义左指针`left`和右指针`right`，`left`指向的是相同元素区域的左边界，`right`指向的是相同元素区域的右边界的**下一个位置**，即通常意义上的**左闭右开**。`right`还有一个任务就是正常的遍历数组。
3. 当(1)`nums[right] != nums[left]`，且(2)`right - left > nums.size()/3 `，则说明left所在的相同元素区域符合要求，将`nums[left]`放到`result`中。之后不管(2)成立与否，`left`被赋值为`right`，意义在于让`left`踏入新的领域，之前的任务已经完成。最后`++right`，使得遍历任务正常进行。
4. 最终`right`遍历数组完成后，停留在`nums.size()`位置。一个特殊情况是如果最后一个相同元素区域的长度大于`nums.size()/3 `，则步骤3是没办法捕捉到的，因为这时right已经遍历到数组外边界，所以需要一个额外的判断，即`nums.size() - left >nums.size()/3 `，则`nums[left]`也是符合要求的，也需要放到`result`中去。

如下是C++的实现方式。

```C++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
      	if(nums.empty()) {
            return result;
        }
         
      	sort(nums.begin(), nums.end());
      
        int threshold = nums.size()/3;
        int left = 0;
        int right = 1;
      
        while(right < nums.size()){
            if(nums[right] != nums[left]){
                if(right - left > threshold) {
                    result.push_back(nums[left]);
                }
                left = right;
            }   
            ++right;
        }

        if(nums.size() - left > threshold) {
            result.push_back(nums[left]);
        }
        
        return result;
    }
};
```

## 时空复杂度

时间复杂度：O(nlogn)，因为有排序在其中。

空间复杂度：O(1)

### 2. hash map 思想

正常的hash_map储存中间结果思想。

如下是C++的实现方式。

```C++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) {
            return {};
        }
         
        int threshold = nums.size()/3;
        vector<int> result;

        unordered_map<int, int> m;
        
        for (const auto& elem: nums) {
            ++m[elem];
        }
        
        for (const auto& elem: m) {
            if (elem.second > threshold) {
                result.emplace_back(elem.first);
            }
        }
        
        return result;
    }
};
```

## 时空复杂度

时间复杂度：O(n)

空间复杂度：O(n)