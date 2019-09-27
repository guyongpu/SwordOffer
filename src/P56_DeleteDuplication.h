//
// Created by yongpu on 2019/9/27.
//

#ifndef SWORDOFFER_P56_DELETEDUPLICATION_H
#define SWORDOFFER_P56_DELETEDUPLICATION_H

#include <iostream>
#include "P00_CommonHead.h"

using namespace std;

class P56_DeleteDuplication {
public:
    ListNode* deleteDuplication_reserve(ListNode* pHead);
    ListNode* deleteDuplication(ListNode* pHead);
    int test();
};


#endif //SWORDOFFER_P56_DELETEDUPLICATION_H
