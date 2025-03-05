//
// Created by xie on 25-3-4.
//

/// @brief leetcode707
class MyLinkedList {
public:
    struct LinkNode {
        int val;
        LinkNode *next;

        LinkNode(int val): val(val), next(nullptr) {
        }
    };

    /// @param size大小
    MyLinkedList(
    ) {
        dummy_node = new LinkNode(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index > (size - 1)) {
            return -1;
        }
        LinkNode *cur = dummy_node->next;
        while (index) {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkNode *newnode = new LinkNode(val);
        newnode->next = dummy_node->next;
        dummy_node->next = newnode;
        size++;
    }

    void addAtTail(int val) {
        LinkNode *newnode = new LinkNode(val);
        LinkNode *cur = dummy_node;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newnode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        /// 不要忘记
        if (index < 0) {
            index = 0;
        }
        LinkNode *newnode = new LinkNode(val);
        LinkNode *cur = dummy_node;
        while (index) {
            cur = cur->next;
            index--;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > (size - 1)) {
            return;
        }
        LinkNode *cur = dummy_node;
        while (index) {
            cur = cur->next;
            index--;
        }
        LinkNode *tmp = cur->next;
        cur->next = tmp->next;
        delete(tmp);
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp = nullptr;
        size--;
    }

private:
    LinkNode *dummy_node;
    int size;
};
