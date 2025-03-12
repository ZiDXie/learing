//
// Created by xie on 25-3-9.
//
/// @brief leetcode24 两两交换链表中的节点
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *cur = dummy_head;
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode *node_1 = cur->next;
            ListNode *node_2 = node_1->next;
            ListNode *node_3 = node_2->next;
            cur->next = node_2;
            node_2->next = node_1;
            node_1->next = node_3;
            cur = node_1;
        }
        return dummy_head->next;
    }
};
