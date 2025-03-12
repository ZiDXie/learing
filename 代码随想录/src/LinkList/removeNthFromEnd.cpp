//
// Created by xie on 25-3-10.
//
/// @brief leetcode19 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *fast = dummy_head;
        ListNode *slow = dummy_head;
        while (n && fast->next) {
            fast = fast->next;
            n--;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummy_head->next;
    }
};
