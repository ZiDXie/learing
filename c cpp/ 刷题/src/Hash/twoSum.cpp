//
// Created by xie on 25-3-18.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> num;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = num.find(target - nums[i]);
            if (iter != num.end()) {
                return {iter->second, i};
            }
            num.insert({nums[i], i});
        }
        return {};
    }
};
