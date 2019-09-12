//
// Created by yongpu on 2019/9/12.
//

#include "P13_ReOrderArray_Odd_front_Even.h"

/*
 * 题目：调整数组顺序使奇数位于偶数前面
 * 描述：将一个数组的奇数放在前面，偶数放在后面，奇数之间、偶数之间的相对位置不变
 * 输入：array，待处理vector
 * 输出：排序之后的array
 * 思路：可以采用双指针平移的做法，排序的做法，用两个vector组合做法都可以|如果只要求奇数前，偶数后，则用双指针做法
 */


bool cmp(int a, int b)
{
    if((a%2==1)&&(b%2==0))//前奇数，后偶数
        return true;
    return false;//其他情况，如同偶，同奇，偶奇，必须全部返回false

}


void P13_ReOrderArray_Odd_front_Even::reOrderArray(vector<int> &array) {
    sort(array.begin(),array.end(),cmp);
}

int P13_ReOrderArray_Odd_front_Even::test()
{
    vector <int> aa = {1,2,12,56,47,23,88,45,3,4,5,6,7};
    vector<int>::iterator it;
    reOrderArray(aa);
    for(it = aa.begin(); it != aa.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}