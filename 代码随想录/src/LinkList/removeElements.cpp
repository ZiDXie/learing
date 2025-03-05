//
// Created by xie on 25-3-2.
//

#include <iostream>
using namespace std;

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

/// @brief leetcode203移除元素
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummy_node = new ListNode(0, head);
        ListNode *cur = dummy_node;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummy_node->next;
    }
};
