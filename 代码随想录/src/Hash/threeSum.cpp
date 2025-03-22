//
// Created by xie on 25-3-19.
//

///@brief leetcode 15. 三数之和
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    right--;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};
