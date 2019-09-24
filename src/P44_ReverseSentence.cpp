//
// Created by yongpu on 2019/9/24.
//

#include "P44_ReverseSentence.h"

/*
 * 题目：翻转单词顺序列
 * 描述：将一个句子的单词顺序进行翻转，单词内部顺序不变
 * 输入：待处理的字符串
 * 输出：处理后的结果
 * 思路：利用YX = (X^T + Y^T)^T的思想，先对每个单词翻转，然后再对整个单词翻转。
 * 备注：记住YX = (X^T + Y^T)^T方法
 */

string P44_ReverseSentence::ReverseSentence(string str) {
    int len = str.length();
    int start = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
        if(i==len-1){   //处理最后一个单词
            reverse(str.begin() + start, str.end());
        }
    }
    reverse(str.begin(), str.end());
    return str;
}

int P44_ReverseSentence::test() {
    string str1("student. a am I");
    string str2("I am a student.");
    string result = ReverseSentence(str2);
    cout << result << endl;
    return 0;
}
