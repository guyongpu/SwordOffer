//
// Created by yongpu on 2019/9/13.
//

#ifndef SWORDOFFER_P00_COMMONHEAD_H
#define SWORDOFFER_P00_COMMONHEAD_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

#endif //SWORDOFFER_P00_COMMONHEAD_H
