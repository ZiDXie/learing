//
// Created by xie on 25-3-12.
//

///@brief leetcode141 环形链表
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        //注意为空链表的情况
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *tmp1 = head;
                ListNode *tmp2 = slow;
                while (tmp1 != tmp2) {
                    tmp1 = tmp1->next;
                    tmp2 = tmp2->next;
                }
                return tmp2;
            }
        }
        return NULL;
    }
};
