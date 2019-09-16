//
// Created by yongpu on 2019/9/14.
//

#include "P27_StringPermutation.h"

/*
 * 题目：字符串排列
 * 描述：输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 输入：str，待排序的字符串
 * 输出：result，排列结果
 * 思路：将字符串分为两部分，第一个字符、其后面的所有字符。然后用第一个字符和后面的所有字符逐个交换。
 */

bool cmp_P27(string a, string b)
{
    return a < b;
}

vector<string> P27_StringPermutation::Permutation(string str) {
    vector<string> result;
    if(str.length() > 0)
    {
        int begin = 0;
        Permutation_Sub(str, result, begin);
    }
    //字典排序处理,升序
    sort(result.begin(), result.end(), cmp_P27);
    return result;
}

void P27_StringPermutation::Permutation_Sub(string str, vector<string> &result, int begin) {
    if(begin == str.length()-1) //已经处理最后一个，无需继续处理
    {
        vector<string>::iterator iter = find(result.begin(), result.end(), str);
        if(iter == result.end())//不重复
        {
            result.push_back(str);
        }
    }
    else{
        //str[begin]与后面的字符逐个交换
        for(int i = begin; i < str.length(); i++)
        {
            string temp_str = str;      //使用temp_str进行交换处理，避免改变str的值
            swap(temp_str[begin], temp_str[i]);
            int temp_begin = begin + 1;
            Permutation_Sub(temp_str, result, temp_begin);
        }
    }
}

int P27_StringPermutation::test() {
    string str = "alibaba";
    vector<string> result = Permutation(str);
    for(int i = 0; i < result.size(); i++)
        ;
    cout << result.size() << endl;
    return 0;
}
