//
// Created by yongpu on 2019/9/24.
//

#include "P42_FindNumbersWithSum.h"

/*
 * 题目：和为S的两个数字
 * 描述：在数组中查找两个数，使得他们的和正好是S，要求乘积最小
 * 输入：待查找数组和一个数字S
 * 输出：和为S且乘积最小的两个数
 * 思路：从两端开始找，采用双指针做法，一旦找到，就是乘积最小的。
 * 备注：两个数和为S时，两个数越接近乘积越大。要考虑找不到的情况。
 */

vector<int> P42_FindNumbersWithSum::FindNumbersWithSum(vector<int> array, int sum) {
    if (array.size() == 0)
        return vector<int>();
    vector<int> result;
    int len = array.size();
    int minIndex = 0;
    int maxIndex = len - 1;
    while (minIndex < maxIndex) {
        if (array[minIndex] + array[maxIndex] == sum) {     //由于从两端开始找，首次找到的就是乘积最小的
            result.push_back(array[minIndex]);
            result.push_back(array[maxIndex]);
            break;
        } else if (array[minIndex] + array[maxIndex] < sum) {
            minIndex++;
        } else {
            maxIndex--;
        }
    }
    return result;
}

int P42_FindNumbersWithSum::test() {
    vector<int> array = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10};
    int sum = 11;
    vector<int> result = FindNumbersWithSum(array, sum);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
