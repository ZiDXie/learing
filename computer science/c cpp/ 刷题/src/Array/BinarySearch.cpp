//
// Created by xie on 25-2-19.
//
#include <vector>
using namespace std;

/**
 * @brief 二分查找
 * 练习为力扣704
 */
class Solution {
public:
    /**
     * @brief 左闭右闭
     * @param nums 数组
     * @param target 目标值
     * @return 返回目标位置
     * 当查找不到时返回-1
     */
    int Search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        // failed find
        return -1;
    }

    /**
     * @brief 左闭右开
     * @param nums 数组
     * @param target 目标值
     * @return 返回目标位置
     * 当查找不到时返回-1
     */
    int Search_2(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};
