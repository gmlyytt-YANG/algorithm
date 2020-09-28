## 题意

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example:**

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

## 思路 & 实现

### 1. 遍历链表

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        
        carry = 0
        
        l_result = ListNode(0)
        l_traverse = l_result
        
        while l1 != None or l2 != None:
            l1_value = l1.val if l1 != None else 0
            l2_value = l2.val if l2 != None else 0
            
            l_process_value = l1_value + l2_value + carry
            l_process = ListNode(l_process_value % 10)
            
            l_traverse.next = l_process
            l_traverse = l_traverse.next
            
            carry = l_process_value / 10
            
            l1 = l1.next if l1 != None else None
            l2 = l2.next if l2 != None else None
            
        if carry > 0:
            l_traverse.next = ListNode(carry)
            
        return l_result.next
```

#### **时空复杂度**

**时间复杂度**：`O(max(m, n))`。

**空间复杂度**：`O(max(m, n))`。