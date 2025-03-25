//
// Created by xie on 25-3-24.
//

#include <string>
using namespace std;

class Solution {
public:
    void removeExtraSpaces(string &s) {
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                while (i < s.size() && s[i] != ' ') {
                    s[slow] = s[i];
                    i++;
                    slow++;
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
