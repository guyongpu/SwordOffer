//
// Created by yongpu on 2019/9/28.
//

#ifndef SWORDOFFER_P62_KTHNODEOFTREE_H
#define SWORDOFFER_P62_KTHNODEOFTREE_H

#include <iostream>
#include "P00_CommonHead.h"

using namespace std;

class P62_KthNodeOfTree {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k);
    TreeNode* KthNode_Sub(TreeNode* pRoot, int &k);
    int test();

};


#endif //SWORDOFFER_P62_KTHNODEOFTREE_H
