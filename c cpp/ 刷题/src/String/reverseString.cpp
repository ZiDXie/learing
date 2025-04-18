//
// Created by xie on 25-3-22.
//
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};
