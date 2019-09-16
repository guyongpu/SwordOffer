//
// Created by yongpu on 2019/9/16.
//

#include "P30_FindGreatestSumOfSubArray.h"

/*
 * 题目：连续子数组的最大和
 * 描述：计算一个数组的最大连续子序列的和
 * 输入：array，数组
 * 输出：result，数组最大连续子序列的和
 * 思路：常规解法，逐个累加，当tmp_sum<0，则替换掉，每次与sum比较大小
 * 动态规划，F(i)=Max(F(i-1)+array[i],array[i])
 */

// 常规解法
int P30_FindGreatestSumOfSubArray::FindGreatestSumOfSubArray_1(vector<int> array) {
    if(array.size() == 0)
        return 0;
    int tmp_sum = 0;
    int sum = INT_MIN;
    int pos_begin = 0, pos_end =0;
    for(int i = 0; i < array.size(); i++)
    {
        if(tmp_sum < 0)   //上一步累加和tmp_sum为负数,则替换
        {
            tmp_sum = array[i];
            if(tmp_sum > sum)
                pos_begin = i;
        }
        else{
            tmp_sum = tmp_sum + array[i];
        }
        if(tmp_sum > sum)
        {
            pos_end = i;
            sum = tmp_sum;
        }
    }
    //序列的坐标
    cout << pos_begin << " " << pos_end << endl;
    return sum;
}

//动态规划解法
/*
 * F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
 * F（i）=max（F（i-1）+array[i] ， array[i]）
 * res：所有子数组的和的最大值
 * res=max（res，F（i））
 * 如数组[6, -3, -2, 7, -15, 1, 2, 2]
 * 初始状态：
 *    F（0）=6
 *    res=6
 * i=1：
 *    F（1）=max（F（0）-3，-3）=max（6-3，3）=3
 *    res=max（F（1），res）=max（3，6）=6
 * i=2：
 *    F（2）=max（F（1）-2，-2）=max（3-2，-2）=1
 *     res=max（F（2），res）=max（1，6）=6
 * i=3：
 *    F（3）=max（F（2）+7，7）=max（1+7，7）=8
 *    res=max（F（2），res）=max（8，6）=8
 * i=4：
 *    F（4）=max（F（3）-15，-15）=max（8-15，-15）=-7
 *    res=max（F（4），res）=max（-7，8）=8
 *  以此类推
 *  最终res的值为8
 */
int P30_FindGreatestSumOfSubArray::FindGreatestSumOfSubArray_2(vector<int> array) {
    if(array.size() == 0)
        return 0;
    int tmp_sum = array[0];
    int sum = array[0];
    for(int i = 1; i < array.size(); i++)
    {
        tmp_sum = max(tmp_sum + array[i] , array[i]);
        sum = max(tmp_sum, sum);
    }
    return sum;
}

int P30_FindGreatestSumOfSubArray::test() {
    vector<int> array1 = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> array2 = {-2, -8, -1, -5, -9 };
    vector<int> array3 = {6, -3, -2, 7, -15, 1, 2, 2};
    int result = FindGreatestSumOfSubArray_2(array2);
    cout << result << endl;

    return 0;
}
