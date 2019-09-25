//
// Created by yongpu on 2019/9/24.
//

#include "P49_StrToInt.h"
/*
 * 题目：把字符串转换成整数
 * 描述：将一个字符串转换成一个整数的功能，当string不符合数字要求时返回0)
 * 输入：待转化的字符串
 * 输出：转化出的结果
 * 思路：正常思路，注意正负号，非法字符，标记位，空字符串，整数上下溢出
 * 备注：注意细节。
 */

int P49_StrToInt::StrToInt(string str) {
    bool flag = true;
    if (str.size() == 0) {
        flag = false;
        return 0;
    }
    //检查符号位
    bool sign = true;
    int index = 0;
    if (str[0] == '+') {
        sign = true;
        index = 1;
    } else if (str[0] == '-') {
        sign = false;
        index = 1;
    }
    //检查数据是否合法
    for (int i = index; i < str.size(); i++) {
        if ('0' <= str[i] && str[i] <= '9')
            continue;
        else {
            flag = false;
            return 0;
        }
    }
    //开始转化
    int len = str.length();
    long long int result = 0;
    for (int i = index; i <len; i++) {
        result = result * 10 + (str[i] - '0');
        if (sign == true) //正数
        {
            if (result > INT_MAX) {
                flag = false;
                return 0;
            }
        } else {
            if (result - 1 > INT_MAX ) {
                flag = false;
                return 0;
            }
        }

    }
    //加上符号位
    if (sign == false) {
        result = -result;
    }
    return result;
}

int P49_StrToInt::test() {
    string str= "-1223";
    int result = StrToInt(str);
    cout << result << endl;
    return 0;
}
