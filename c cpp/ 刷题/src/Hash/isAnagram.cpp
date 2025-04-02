//
// Created by xie on 25-3-14.
//

///@brief leetcode242
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int num[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            num[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            num[t[i] - 'a']--;
        }
        for (int i = 0; i <= 25; i++) {
            if (num[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
