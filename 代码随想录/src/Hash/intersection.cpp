//
// Created by xie on 25-3-16.
//
///@brief LEETCODE 349
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result;
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (auto num: nums2) {
            if (nums.find(num) != nums.end()) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
