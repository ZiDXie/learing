//
// Created by xie on 25-3-5.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    /// @brief 暴力解法
    void baoli() {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
        int a, b;
        while (cin >> a >> b) {
            int result = 0;
            for (int i = a; i <= b; i++) {
                result += array[i];
            }
            cout << result << endl;
        }
    }

    /// @brief 前缀和
    /// C++ 代码 面对大量数据 读取 输出操作，最好用scanf 和 printf，耗时会小很多
    void qianzhuihe() {
        int n;
        cin >> n;
        vector<int> array(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int num = 0;
            scanf("%d", &num);
            sum += num;
            array[i] = sum;
        }
        int a, b;
        while (cin >> a >> b) {
            if (a == 0) {
                printf("%d\n", array[b]);
            } else {
                printf("%d\n", array[b] - array[a - 1]);
            }
        }
    }
};
