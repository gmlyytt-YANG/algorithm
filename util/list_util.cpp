#include "list_util.h"

ListNode* create_list(std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    auto * pHead = new ListNode(values[0]);
    ListNode* pNode1 = pHead;
    for (int i=1; i<values.size(); ++i) {
        auto * pNode2 = new ListNode(values[i]);
        pNode1->next = pNode2;
        pNode1 = pNode2;
    }
    pNode1->next = nullptr;
    return pHead;
}

void print_list(ListNode* head) {
    while (head) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

//bool operator<(const ListNode& lhs, const ListNode& rhs) {
//    return lhs.value < rhs.value;
//}
