//
// Created by xie on 25-2-28.
//
#include <climits>
#include <vector>
using namespace std;

///最小长度
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = INT_MAX;
        int sum = 0;
        int i = 0;
        int length = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum = sum + nums[j];
            while (sum >= target) {
                length = j - i + 1;
                sum = sum - nums[i];
                i++;
                result = min(result, length);
            }
        }
        if (result == INT_MAX) {
            return 0;
        }
        return result;
    }
};
