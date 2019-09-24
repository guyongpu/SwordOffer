//
// Created by yongpu on 2019/9/24.
//

#include "P41_FindContinuousSequence.h"

/*
 * 题目：和为S的连续正数序列
 * 描述：输出和为S的连续正数序列，要求序列内部升序，序列间按起始数字升序
 * 输入：序列和S
 * 输出：连续正数序列
 * 思路：采用双指针，small=1,big=2,然后逐步将指针往右移，约束条件：small <= sum/2.
 * 备注：起始不能为0.
 */

vector<vector<int> > P41_FindContinuousSequence::FindContinuousSequence(int sum) {
    if (sum < 3)  //s最小为3
        return vector<vector<int>>();
    vector<vector<int>> result;
    int small = 1;  //要求是正数序列，因此不能初始化为0
    int big = 2;
    long long int sum_temp;
    int limit = sum / 2;
    while (small <= limit) {
        sum_temp = (small + big) * (big - small + 1) / 2;
        if (sum_temp < sum) {
            big++;
        } else if (sum_temp > sum) {
            small++;
        } else {
            vector<int> Sequence;
            for (int i = small; i <= big; i++) {
                Sequence.push_back(i);
            }
            result.push_back(Sequence);

            small++;
            big++;
        }
    }
    //无需再进行排序，因为已经符合序列内部升序，序列间按起始数字升序的要求
    return result;
}

int P41_FindContinuousSequence::test() {
    int sum = 100;
    vector<vector<int>> result = FindContinuousSequence(sum);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
