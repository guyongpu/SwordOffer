//
// Created by yongpu on 2019/9/28.
//

#include "P65_PathOfMatrix.h"

/**
 * 题目：矩阵中的路径
 * 描述：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 输入：字符串矩阵,行数，列数，待匹配字符串
 * 输出：是否能够匹配
 * 思路：测试所有可能的起点，然后使用递归回溯算法，visited用于标记是否访问，在匹配失败是进行回退。
 * 备注：在匹配失败要进行回退.
 */

bool P65_PathOfMatrix::hasPath(char *matrix, int rows, int cols, char *str) {
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int begin_row = i;
            int begin_col = j;
            int index = 0;
            vector<bool> visited(rows * cols, false);
            bool result = hasPath_Sub(matrix, rows, cols, begin_row, begin_col, str, index, visited);
            if (result == true) {
                return result;
            }
        }
    }
    return false;
}


bool P65_PathOfMatrix::hasPath_Sub(char *matrix, int rows, int cols, int row, int col, char *str, int &index,
                                   vector<bool> &visited) {
    if (str[index] == '\0')
        return true;
    bool result = false;
    bool flag1 = (0 <= row && row <= rows);
    bool flag2 = (0 <= col && col <= cols);
    if (flag1 && flag2) {
        bool flag3 = (matrix[row * cols + col] == str[index]);
        bool flag4 = (visited[row * cols + col] == false);
        if (flag3 && flag4) {
            visited[row * cols + col] = true;
            index++;
            result = hasPath_Sub(matrix, rows, cols, row - 1, col, str, index, visited)
                     || hasPath_Sub(matrix, rows, cols, row, col - 1, str, index, visited)
                     || hasPath_Sub(matrix, rows, cols, row + 1, col, str, index, visited)
                     || hasPath_Sub(matrix, rows, cols, row, col + 1, str, index, visited);

            //匹配失败，则需要回退
            if (result == false) {
                visited[row * cols + col] = false;
                index--;
            }
        }
    }
    return result;
}


int P65_PathOfMatrix::test() {
    char matrix[] = "abtgcfcsjdeh";
    char str[] = "bfce";
    int row = 3;
    int col = 4;
    bool result = hasPath(matrix, row, col, str);
    cout << result << endl;
    return 0;
}
