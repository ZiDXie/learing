//
// Created by xie on 25-3-1.
//
#include <vector>
using namespace std;

/// @brief 螺旋矩阵
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int count = 1;
        int start_x = 0;
        int start_y = 0;
        int offset = 1;
        int loop = n / 2;
        while (loop) {
            for (int i = start_y, j = start_x; j < n - offset; j++) {
                matrix[i][j] = count;
                count++;
            }
            for (int j = n - offset, i = start_y; i < n - offset; i++) {
                matrix[i][j] = count;
                count++;
            }
            for (int j = n - offset, i = n - offset; j > start_x; j--) {
                matrix[i][j] = count;
                count++;
            }
            for (int i = n - offset, j = start_x; i > start_y; i--) {
                matrix[i][j] = count;
                count++;
            }
            start_x++;
            start_y++;
            offset++;
            loop--;
        }
        if (n % 2 == 1) {
            int mid = n / 2;
            matrix[mid][mid] = count;
        }
        return matrix;
    }
};
