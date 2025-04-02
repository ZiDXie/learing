//
// Created by xie on 25-4-2.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> in;
    stack<int> out;

    MyQueue() {
    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int res = out.top();
        out.pop();
        return res;
    }

    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }

    bool empty() {
        if (in.empty() && out.empty()) {
            return true;
        }
        return false;
    }
};
