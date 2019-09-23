//
// Created by yongpu on 2019/9/23.
//

#ifndef SWORDOFFER_P36_FINDFIRSTCOMMONNODE_H
#define SWORDOFFER_P36_FINDFIRSTCOMMONNODE_H

#include <iostream>
#include <stack>
#include "P00_CommonHead.h"

using namespace std;

class P36_FindFirstCommonNode {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2);
    int GetLengthOfList(ListNode *pHead);
    int test();
};


#endif //SWORDOFFER_P36_FINDFIRSTCOMMONNODE_H
