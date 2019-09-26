//
// Created by yongpu on 2019/9/26.
//

#include "P54_FirstAppearingOnce.h"

/*
 * 题目：字符流中第一个不重复的字符
 * 描述：请实现一个函数用来找出字符流中第一个只出现一次的字符。
 * 输入：单个字符
 * 输出：当前情况下第一个不重复的字符
 * 思路：使用 HashTable[256]大小的哈希表，初始值设置为-1，之后值为第一次出现的index，重复出现时设置为-2，然后输出当前HashTable[256]中最小的非负数对应的字符.
 * 备注：字符表考虑256大小的哈希表
 */

void P54_FirstAppearingOnce::Insert(char ch) {
    int num = (int) ch;
    if (HashTable[num] == -1) {         //第一次出现
        HashTable[num] = index;
    } else if (HashTable[num] >= 0) {   //已经出现过
        HashTable[num] = -2;            //表示重复出现
    }
    index++;
}

char P54_FirstAppearingOnce::FirstAppearingOnce() {
    int MinPos = INT_MAX;
    char ch;
    bool flag = false;
    for (int i = 0; i < 256; i++) {
        if (HashTable[i] >= 0) {
            if (HashTable[i] < MinPos) {
                MinPos = HashTable[i];
                ch = '\0' + i;
                flag = true;
            }
        }
    }
    if (flag == false)
        ch = '#';
    return ch;
}

P54_FirstAppearingOnce::P54_FirstAppearingOnce(int x, int in) {
    index = in;
    for (int i = 0; i < 256; i++)
        HashTable[i] = x;
}

int P54_FirstAppearingOnce::test() {
    Insert('g');
    cout << FirstAppearingOnce() << endl;
    Insert('o');
    cout << FirstAppearingOnce() << endl;
    Insert('o');
    cout << FirstAppearingOnce() << endl;
    Insert('g');
    cout << FirstAppearingOnce() << endl;
    Insert('l');
    cout << FirstAppearingOnce() << endl;
    Insert('e');
    cout << FirstAppearingOnce() << endl;
    return 0;
}

