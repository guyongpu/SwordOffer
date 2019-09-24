//
// Created by yongpu on 2019/9/24.
//

#include "P43_LeftRotateString.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 题目：左旋转字符串
 * 描述：将一个字符串循环左移n位
 * 输入：待处理字符串和左移位数n
 * 输出：处理结果
 * 思路：法1：采用旋转方式实现 YX = (X^T + Y^T)^T ，通过三次reverse实现；法2：采用普通的substr截取字符串处理。
 * 备注：reverse第二个参数是下一个元素的地址。
 */

//采用旋转方式实现 YX = (X^T + Y^T)^T
string P43_LeftRotateString::LeftRotateString1(string str, int n) {
    int len = str.length();
    if (n == 0 || len == 0)
        return str;
    int moveNum = n % len;  //分为两部分：[0,moveNum-1]和[moveNum, len-1]

    //对[0,moveNum-1]翻转
    reverse(str.begin(), str.begin() + moveNum);    //reverse第二个参数是下一个元素的地址

    //对[moveNum, len-1]翻转
    reverse(str.begin() + moveNum, str.begin() + len);

    //对[0,len-1]翻转
    reverse(str.begin(), str.end());

    return str;
}

//左移截取方式实现
string P43_LeftRotateString::LeftRotateString2(string str, int n) {
    int len = str.length();
    if (n == 0 || len == 0)
        return str;
    int moveNum = n % len;  //分为两部分：[0,moveNum-1]和[moveNum, len-1]
    str = str.substr(moveNum, len - moveNum) + str.substr(0, moveNum);
    return str;
}

int P43_LeftRotateString::test() {
    string str = "abcdefg";
    int n = 2;
    string str1 = LeftRotateString1(str, n);
    cout << str1 << endl;
    string str2 = LeftRotateString2(str, n);
    cout << str2 << endl;
    return 0;
}
