//
// Created by yongpu on 2019/9/26.
//

#ifndef SWORDOFFER_P54_FIRSTAPPEARINGONCE_H
#define SWORDOFFER_P54_FIRSTAPPEARINGONCE_H

#include <iostream>

using namespace std;

class P54_FirstAppearingOnce {
public:
    int HashTable[256]; //字符哈希表
    int index;          //累计输入的字符数量

    void Insert(char ch);

    char FirstAppearingOnce();

    int test();

    P54_FirstAppearingOnce(int x = -1, int in = 0);
};


#endif //SWORDOFFER_P54_FIRSTAPPEARINGONCE_H
