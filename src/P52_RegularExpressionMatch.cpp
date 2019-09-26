//
// Created by yongpu on 2019/9/26.
//

#include "P52_RegularExpressionMatch.h"

/*
 * 题目：正则表达式匹配
 * 描述：实现一个函数用来匹配包括'.'和'*'的正则表达式.
 * 输入：普通字符串str，含*.字符串
 * 输出：匹配结果
 * 思路：第1步,先处理*，若能匹配，则三种情况：(1)跳过x*，即matchCore(str,pattern+2);(2)匹配x*,即matchCore(str+1,pattern+2);(3)匹配下一个str,即matchCore(str+1,pattern);若不能匹配，则忽略跳过x*。第2步,然后处理正常字符的情况。
 * 备注：常见题
 */

bool P52_RegularExpressionMatch::match(char *str, char *pattern) {
    if (str == nullptr || pattern == nullptr)
        return false;
    bool result = false;

    result = matchCore(str, pattern);

    return result;
}

bool P52_RegularExpressionMatch::matchCore(char *str, char *pattern) {
    if (str[0] == '\0' && pattern[0] == '\0')
        return true;
    if (str[0] != '\0' && pattern[0] == '\0')
        return false;

    //1.遇到*的情况
    if (pattern[1] == '*') {
        if (str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0')) {    //pattern[0]能与str[0]匹配
            bool flag1 = matchCore(str + 1, pattern + 2);   //匹配一个x*
            bool flag2 = matchCore(str + 1, pattern);               //匹配str的下一个字符
            bool flag3 = matchCore(str, pattern + 2);           //忽略x*
            return (flag1 || flag2 || flag3);
        } else {//pattern[0]能与str[0]匹配，则必须忽略
            bool flag4 = matchCore(str, pattern + 2);           //忽略x*
            return flag4;
        }
    }
    //2.遇到正常字符或.的情况
    if (pattern[0] == str[0] || (str[0] != '\0' && pattern[0] == '.')) {
        int flag5 = matchCore(str + 1, pattern + 1);
        return flag5;
    } else
        return false;
}

int P52_RegularExpressionMatch::test() {
    char str[] = "bcbbabab"; // "" != nullptr
    char pattern[] = ".*a*a";
    bool result = match(str, pattern);
    cout << result << endl;
    return 0;
}
