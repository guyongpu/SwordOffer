//
// Created by yongpu on 2019/9/28.
//

#include "P66_RangeOfRobotMotion.h"

/**
 * 题目：机器人的运动范围
 * 输入：方格的行、列，以及数位之和
 * 输出：
 */

int P66_RangeOfRobotMotion::movingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;
    vector<bool> visited(rows * cols, false);
    int count = movingCount_Sub(threshold, rows, cols, 0, 0, visited);
    return count;
}

int
P66_RangeOfRobotMotion::movingCount_Sub(int threshold, int rows, int cols, int row, int col, vector<bool> &visited) {
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited) == true) {
        visited[row * cols + col] = true;
        count = 1 + movingCount_Sub(threshold, rows, cols, row - 1, col, visited)
                + movingCount_Sub(threshold, rows, cols, row, col - 1, visited)
                + movingCount_Sub(threshold, rows, cols, row + 1, col, visited)
                + movingCount_Sub(threshold, rows, cols, row, col + 1, visited);
    }
    return count;
}

bool P66_RangeOfRobotMotion::check(int threshold, int rows, int cols, int row, int col, vector<bool> &visited) {
    bool flag1 = (row >= 0 && row < rows);
    bool flag2 = (col >= 0 && col < cols);
    if (flag1 && flag2) {
        bool flag3 = ((getDigitSum(row) + getDigitSum(col)) <= threshold);
        bool flag4 = (visited[row * cols + col] == false);
        if (flag3 && flag4) {
            return true;
        }
    }
    return false;
}

int P66_RangeOfRobotMotion::getDigitSum(int number) {
    int sum = 0;
    while (number) {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

int P66_RangeOfRobotMotion::test() {
    int result = movingCount(15, 20, 20);
    cout << result << endl;
    return 0;
}


