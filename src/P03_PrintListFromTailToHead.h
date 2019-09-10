//
// Created by yongpu on 2019/9/10.
//

#ifndef SWORDOFFER_P03_PRINTLISTFROMTAILTOHEAD_H
#define SWORDOFFER_P03_PRINTLISTFROMTAILTOHEAD_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x),next(NULL){}
};

class P03_PrintListFromTailToHead {
public:
    int test();
    vector<int> printListFromTailToHead(ListNode* head);
};


#endif //SWORDOFFER_P03_PRINTLISTFROMTAILTOHEAD_H
