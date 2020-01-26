## 题意

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

```
Example 1:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

## 思路 & 实现

### 1. 二分查找+深度优先遍历

利用二分查找和深度优先遍历的组合解决问题，具体算法描述如下：

1. 设**有序数组**左边边界为`left`，右边边界为`right`, 取中间值`middle((left+right)/2)`，
2. 将数组以`middle`为界分为两段，两段的边界分别为`[left, middle - 1]`和`[middle + 1, right]`，`middle`对应位置的取值`nums[middle]`作为`root`，
3. 上述两段的中间位置对应的取值作为`root`的左右子树的根节点，递归进行，直到`left < 0 || right >= nums.size() || left > right`，停止递归。

这里需要解释的是为什么该算法构建的树一定是平衡树，这是因为数组的切分本身就是均匀的，并不存在左子树切分少或者右子树切分少的问题。

如下是C++的实现方式。

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return nullptr;
        }
        
        return dfs(nums, 0, length - 1);
    }
    
    TreeNode* dfs(const vector<int>& nums, int left, int right) {
      	// dfs的核心为边界条件的判断
        if (left < 0 || right >= nums.size() || left > right) {
            return nullptr;
        }
        
        int middle = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = dfs(nums, left, middle - 1);
        root->right = dfs(nums, middle + 1, right);
        
        return root;
    }
};
```


## 时空复杂度

时间复杂度：`O(n)`, 因为每个元素只被访问了一次。

空间复杂度：`O(log(n))`，递归栈的大小。

