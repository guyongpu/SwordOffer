//
// Created by yongpu on 2019/9/11.
//

#include "P11_NumOf_1_InTheBinary.h"

/*
 * 题目：二进制中1的个数
 * 描述：给定一个整数，求其二进制中1的个数
 * 输入：n，给定的整数
 * 输出：n的二进制表示中1的个数
 * 思路：有3种方法，其中1和2是常规方法，3是高级方法
 * 方法1是对n进行判断，如果为负数则与0x7FFFFFFF预算，然后每次将n右移，逐个计算
 * 方法2是设置一个flag，然后每次将flag左移，逐个计算
 * 方法3是采用每次将n与减1得到的结果进行与运算，即n=n&(n-1)，当n为0时结束，计算次数与其1的个数相等，效果最好。
 */

/*
//常规方法1，将负数变为正数，然后右移
int P11_NumOf_1_InTheBinary::NumberOf1(int n) {
    int count = 0;
    if(n < 0)//处理负数
    {
        count++;
        n = n & 0x7FFFFFFF;
    }

    while(n)
    {
        if(n & 1)//最右位是否为1
        {
            count++;
        }
        n = n >> 1;//右移
    }
    return count;
}
*/

/*
//常规方法2，每次将flag左移1位
int P11_NumOf_1_InTheBinary::NumberOf1(int n) {
    int count = 0;
    int flag = 1;
    while(flag)
    {
        if(n & flag)//当前位为1
        {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}
*/

//高级方法3,每次与减1后的结果与运算，为0时结束计算
int P11_NumOf_1_InTheBinary::NumberOf1(int n) {
    int count = 0;
    while(n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

int P11_NumOf_1_InTheBinary::test(){
    int val = NumberOf1(0x7fffffff);
    cout << val << endl;

    return 0;
}

