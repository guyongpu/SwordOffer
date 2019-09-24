//
// Created by yongpu on 2019/9/24.
//

#include "P48_Add.h"

/*
 * 题目：不用加减乘除做加法
 * 描述：求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
 * 输入：待相加的两个数
 * 输出：两个数相加的和
 * 思路：对每一位进行讨论计算，使用flag诸位左移，设置sum的位.也可以采用标准解法.
 * 备注：利用了数据在计算机中以补码形式存储。
 */
int P48_Add::Add1(int num1, int num2) {
    int sum, carry;
    do {
        sum = num1 ^ num2;          //异或
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return num1;
}

int P48_Add::Add2(int num1, int num2) {
    int flag = 1;
    int sum = 0;
    int car = 0;                    //上一位的进位
    while (flag != 0) {
        int bit1 = num1 & flag;     //num1的二进制中第i位的值
        int bit2 = num2 & flag;     //num2的二进制中第i位的值
        //情况1: bit1=1, bit2=1
        if (bit1 && bit2) {         //如果都为1
            if (car == 1) {         //进位为1
                sum = sum | flag;   //sum第i为置为1
                car = 1;            //进位置为1
            } else {                //进位如果为0
                sum = sum | 0;      //sum第i为置为0
                car = 1;            //进位置为1
            }
        }
            //情况2: bit1=1, bit2=0 或 bit1=0, bit2=1
        else if (bit1 || bit2) {    //如果只有一个为1
            if (car == 1) {         //进位为1
                sum = sum | 0;      //sum第i为置为0
                car = 1;            //进位为1
            } else {                //进位如果为0
                sum = sum | flag;   //sum第i为置为1
                car = 0;            //进位置为1
            }
        }
            //情况3: bit1=0, bit2=0
        else {                      //如果都为0
            if (car == 1) {         //进位为1
                sum = sum | flag;   //sum第i为置为1
                car = 0;            //进位置为0
            } else {                //进位为0
                sum = sum | 0;      //sum第i为置为0
                car = 0;            //进位置为0
            }
        }
        flag = flag << 1;
    }

//    cout << sum << endl;
    return sum;
}

int P48_Add::test() {
    int num1 = 135;
    int num2 = -23;
    int result;
    result = Add1(num1, num2);
    cout << result << endl;
    result = Add2(num1, num2);
    cout << result << endl;
    return 0;
}
