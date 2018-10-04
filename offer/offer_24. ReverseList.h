//
// Created by Li,Yang(Duer04) on 2018/7/24.
//

#ifndef INC_1STPROGRAM_OFFER_24_REVERSELIST_H
#define INC_1STPROGRAM_OFFER_24_REVERSELIST_H

#include "../util/list_util.h"

ListNode* ReverseList(ListNode* pNode) {
    if (!pNode)
        return nullptr;
    ListNode* pHead = pNode;
    while (pNode->next) {
        ListNode* pNext = pNode->next;
        pNode->next = pNext->next;
        pNext->next = pHead;
        pHead = pNext;
    }
    return pHead;
}

ListNode* ReverseList2(ListNode* pNode) {
    if (!pNode || !pNode->next)
        return pNode;
    ListNode* pNewHead = ReverseList2(pNode->next);
    ListNode* pNewTail = pNode->next;
    pNewTail->next = pNode;
    pNode->next = nullptr;
    return pNewHead;
}

void test() {
    std::vector<int> arr = {1,2,3,4,5};
    ListNode* pHead1 = createList(arr);
    ListNode* pResult1 = ReverseList(pHead1);

    ListNode* pHead2 = createList(arr);
    ListNode* pResult2 = ReverseList(pHead2);
}

#endif //INC_1STPROGRAM_OFFER_24_REVERSELIST_H
