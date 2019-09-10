//
// Created by yongpu on 2019/9/10.
//
//

/*
 * 题目：二维数组的查找
 *
 * 描述：在一个递增的二维数组里，查找target是否存在。
 *
 * 思路：由于矩阵是从左到右和从上到下都是递增的，所以考虑从右上角或者左下角开始计算
 * 本程序是从右上角考虑计算的，
 * 初始时，i = 0，j = colCount -1 ，
 * 当target = array[i][j] 时，查找成功，直接结束；
 * 当target > array[i][j] 时，往下走，即i++ ；
 * 当target < array[i][j] 时，往左走，即j-- ；
 * 边界条件，i < rowCount, j>=0
 * 边界条件结束还未找到，则说明不存在target
 *
 * 扩展思考：本题的数组是从左上到右下递增数组，
 * 相反，如果是从左上到右下是递减的，则也要从左下和右上的两个位置作为初始位置计算，
 * 计算方法是一样的，因为也是需要找一个位置，使得比target大一个方向，比target小是另一个方向。
 */

#include "P01_2d_array_find.h"

int P01_2d_array_find::test() {
    vector <vector<int>> arr;
    vector <int> vec;
    vec.clear();
    vec.push_back(1);vec.push_back(2);vec.push_back(8);vec.push_back(9);
    arr.push_back(vec);

    vec.clear();
    vec.push_back(2);vec.push_back(4);vec.push_back(9);vec.push_back(12);
    arr.push_back(vec);

    vec.clear();
    vec.push_back(4);vec.push_back(7);vec.push_back(10);vec.push_back(13);
    arr.push_back(vec);

    vec.clear();
    vec.push_back(6);vec.push_back(8);vec.push_back(11);vec.push_back(15);
    arr.push_back(vec);

    bool res = Find(3, arr);
    if(res)
        cout << "Find!" << endl;
    else
        cout << "Not find!" << endl;
    return 0;
}

bool P01_2d_array_find::Find(int target, vector<vector<int> > array) {
    int rowCount = array.size();
    int colCount = array[0].size();
    int i = 0, j = colCount - 1;
    bool flag = false;
    while( i < rowCount && j >= 0)
    {
        if(target == array[i][j])
        {
            flag = true;
            break;
        }
        if(target > array[i][j])
        {
            i++;
            continue;
        }
        if(target < array[i][j])
        {
            j--;
            continue;
        }
    }
    return flag;
}