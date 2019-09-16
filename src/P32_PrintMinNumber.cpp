//
// Created by yongpu on 2019/9/16.
//

/*
 * 题目：把数组排成最小的数
 * 描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个最小的数
 * 输入：numbers，一个正整数数组
 * 输出：result，排成一个最小的数
 * 思路：主要运用到一个字符串排序，当str_ab< str_ba时，a在前，否则b在前.
 */

#include "P32_PrintMinNumber.h"

int cmp_P32(string a, string b)
{
    string str_ab(a+b);
    string str_ba(b+a);
    int res = str_ab.compare(str_ba);
    if(res < 0)
        return true;
    else
        return false;
}

string P32_PrintMinNumber::PrintMinNumber(vector<int> numbers) {
    vector<string> num_str;
    for(int i = 0; i < numbers.size(); i++)
    {
        num_str.push_back(to_string(numbers[i]));
    }
    sort(num_str.begin(), num_str.end(), cmp_P32);
    string result;
    for(int i = 0; i < numbers.size(); i++)
        result.append(num_str[i]);
    return result;
}

int P32_PrintMinNumber::test() {
    vector<int> numbers1 = {321, 341, 21, 91};
    vector<int> numbers2 = {3,32,321};
    vector<int> numbers3 = {3334,3,3333332};
    string result = PrintMinNumber(numbers3);
    cout << result << endl;
    return 0;
}
