//
// Created by xie on 25-3-18.
//
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int count = 0;
        unordered_map<int, int> tmp;
        for (int a: nums1) {
            for (int b: nums2) {
                tmp[a + b]++;
            }
        }
        for (int c: nums3) {
            for (int d: nums4) {
                auto iter = 0 - (c + d);
                if (tmp.find(iter) != tmp.end()) {
                    count += tmp[iter];
                }
            }
        }
        return count;
    }
};
