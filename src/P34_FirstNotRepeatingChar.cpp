//
// Created by yongpu on 2019/9/16.
//

#include "P34_FirstNotRepeatingChar.h"

/*
 * 题目：第一个只出现一次的字符
 * 描述：在一个字符串中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回-1
 * 输入：str，字符串
 * 输出：result，第一个出现一次的字符的位置
 * 思路：可以采用构造hash表的思想，即构造pos[52]，int cnt[52]，遍历两次即可求解。
 * 也可以采用map思想，直接strmap<char,int>，做法也比较简单。
 */

//使用hash表思想
int P34_FirstNotRepeatingChar::FirstNotRepeatingChar_1(string str) {
    if(str.length() == 0)
        return -1;
    int len = str.length();
    int pos[52];
    int cnt[52];
    for(int i = 0; i < 52; i++)
    {
        pos[i] = -1;
        cnt[i] = 0;
    }
    for(int i = 0; i < len; i++)
    {
        char c = str[i];
        if('A' <= c && c <= 'Z')//0-25
        {
            int index = c - 'A';
            if(pos[index] == -1)
                pos[index] = i;
            cnt[index] ++;
        }
        if('a' <= c && c <= 'z')//26-51
        {
            int index = c - 'a' + 26;
            if(pos[index] == -1)
                pos[index] = i;
            cnt[index] ++;
        }
    }
    vector<int> vec_pos;
    for(int i = 0; i < 52; i++)
    {
        if(cnt[i] == 1)
        {
            vec_pos.push_back(pos[i]);
        }
    }
    sort(vec_pos.begin(),vec_pos.end());
    int result = vec_pos[0];
    return result;
}

//使用map做法
int P34_FirstNotRepeatingChar::FirstNotRepeatingChar_2(string str) {
    int len = str.length();
    map<char, int> strmp;
    int result = -1;
    for(int i = 0; i < len; i++)
    {
        strmp[str[i]]++;
    }
    for(int i = 0; i < len; i++)
    {
        if(strmp[str[i]]==1){
            result = i;
            break;
        }
    }
    return result;
}

int P34_FirstNotRepeatingChar::test() {
    string str("aabbcddf");
    int result = FirstNotRepeatingChar_1(str);
    cout << result << endl;
    return 0;
}
