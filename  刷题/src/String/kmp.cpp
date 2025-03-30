//
// Created by xie on 25-3-28.
//
#include <iostream>
using namespace std;

class Solution {
public:
    void getnext(int *next, string &s) {
        int j = 0;
        next[0] = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[j] != s[i]) {
                j = next[]fvgr
            }
            if (s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
    }
};
