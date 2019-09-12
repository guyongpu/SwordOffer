//
// Created by yongpu on 2019/9/11.
//

#include "P12_Numerical_Integer_Power.h"
/*
 * 题目：数值的整数次方
 * 描述：不用库函数，计算base的exponent次方
 * 输入：base，double类型的浮点数；exponent，次方数
 * 输出：返回base的exponet次方的计算结果
 * 思路：考虑两个点，一是int的绝对值算法，考虑边界值；二是0的处理，返回0
 */


double P12_Numerical_Integer_Power::Power(double base, int exponent) {
    if(base == 0)
        return 0;
    unsigned int abs_exponent;

    //计算绝对值
    if(exponent < 0)
        abs_exponent = (unsigned)(-exponent);
    else
        abs_exponent = (unsigned)exponent;

    //计算结果
    double result = 1.0;
    for(int i = 0; i < abs_exponent; i++)
    {
        result = result * base;
    }

    //负次方数要取导数
    if(exponent < 0)
        return 1/result;
    else
        return result;
}

int P12_Numerical_Integer_Power::test() {
    double val;
    val = Power(1.2,2);
    cout << val <<endl;
    val = Power(2,-2);
    cout << val <<endl;
    return 0;
}