//
// Created by xie on 25-2-21.
//
#include <vector>
using namespace std;

/**
 * @brief 力扣977
 */
class Solution {
public:
    /**
     * @brief 
     * @param num 
     * @return 
     */
    int square(int num) {
        return num * num;
    }

    /**
     * @brief 
     * @param nums 
     * @return 
     */
    vector<int> sortedSquares(vector<int> &nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        int k = size - 1;
        for (int i = 0, j = size - 1; i <= j;) {
            if (square(nums[i]) > square(nums[j])) {
                result[k] = square(nums[i]);
                k--;
                i++;
            } else {
                result[k] = square(nums[j]);
                k--;
                j--;
            }
        }
        return result;
    }
};
