//
// Created by xie on 25-2-20.
//
#include "vector"
using namespace std;

/**
 * @brief 移除元素
 */
class Solution {
public:
    /**
     * @brief 暴力解法(时间复杂度为O（n））
     * @param nums 数组
     * @param val 值
     * @return 新数组的大小
     */
    int removeElement(vector<int> &nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }

    /**
     * @brief 双指针复杂度o（1）
     * @param nums
     * @param val
     * @return
     */
    int removeElement_(vector<int> &nums, int val) {
        int SlowIndex = 0;
        for (int FastIndex = 0; FastIndex < nums.size(); FastIndex++) {
            if (nums[FastIndex] != val) {
                nums[SlowIndex] = nums[FastIndex];
                SlowIndex++;
            }
        }
        return SlowIndex;
    }
};
