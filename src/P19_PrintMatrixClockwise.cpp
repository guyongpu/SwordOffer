//
// Created by yongpu on 2019/9/13.
//

#include "P19_PrintMatrixClockwise.h"

/*
 * 题目：顺时针打印矩阵
 * 描述：将一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 * 输入：matrix,二维矩阵
 * 输出：打印结果
 * 思路：第一步：先打印整圈的，圈数是行列的最小值minNum/2；
 * 第二步，如果minNum是奇数，说明有单独的行/列，当行>列，则有列，从上到下打印，当列>=行，则有行，从左到右打印。
 * 注意：列数 > 行数，单独的行要打印,从左到右
 *  列数 <= 行数单独的列要打印,从上到下
 *  测试时要测1*1,1*m,n*1,奇*奇，偶*偶，偶*奇，奇*偶等情况
 */

vector<int> P19_PrintMatrixClockwise::printMatrix(vector<vector<int> > matrix) {
    vector <int> result;
    if(matrix.size() == 0)
        return result;
    int row = matrix.size();
    int col = matrix[0].size();
    int pos_row1,pos_col1,pos_row2,pos_col2;
    int minNum = (row < col) ? row : col;
    int circle = minNum/2;

    //打印完整的圈
    for(int i = 0; i < circle; i++)
    {
        //打印规则
        //  - - - -
        //  *     *
        //  - - - -
        pos_row1 = i;
        pos_col1 = i;
        pos_row2 = row - 1 - i;
        pos_col2 = col - 1 - i;
        //从左到右打印,行坐标为pos_row1，列坐标改变
        for(int ci = pos_col1; ci <= pos_col2; ci++)
        {
            result.push_back(matrix[pos_row1][ci]);
        }
        //从上到下打印,行坐标改变，列坐标为pos_col2
        for(int  ri = pos_row1+1; ri < pos_row2; ri++)
        {
            result.push_back(matrix[ri][pos_col2]);
        }
        //从右到左打印,行坐标为pos_row2，列坐标改变
        for(int ci = pos_col2; ci >= pos_row1; ci--)
        {
            result.push_back(matrix[pos_row2][ci]);
        }
        //从下到上打印,行坐标改变，列坐标为pos_col1
        for(int ri = pos_row2-1; ri > pos_row1; ri--)
        {
            result.push_back(matrix[ri][pos_col1]);
        }
    }

    if(minNum%2) //当minNum是奇数，则存在单独的行或列
    {
        if(col > row) //列数 > 行数，单独的行要打印,从左到右
        {
            int pos_row = circle;
            int pos_col1 = circle;
            int pos_col2 = col - circle - 1;
            for(int ci = pos_col1; ci <= pos_col2; ci++)
                result.push_back(matrix[pos_row][ci]);
        }
        else//列数 <= 行数单独的列要打印,从上到下
        {
            int pos_col = circle;
            int pos_row1 = circle;
            int pos_row2 = row - circle - 1;
            for(int ri = pos_row1; ri <= pos_row2; ri++)
                result.push_back(matrix[ri][pos_col]);
        }
    }
    return result;
}

int P19_PrintMatrixClockwise::test() {
    vector <int> a1={ 1, 2, 3, 4, 5};
    vector <int> a2={ 5, 6, 7, 8, 6};
    vector <int> a3={ 9,10,11,12, 7};
    vector <int> a4={13,14,15,16, 8};
    vector <int> a5={17,18,19,20, 9};
    vector<vector <int>> array;
    vector <int> a6={11};
    vector <int> a7={22};
    vector <int> a8={33};
//    array.push_back(a6);
//    array.push_back(a7);
//    array.push_back(a8);
    array.push_back(a1);
    array.push_back(a2);
//    array.push_back(a3);
//    array.push_back(a4);
//    array.push_back(a5);

    vector<int>result = printMatrix(array);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

