//
// Created by yongpu on 2019/9/23.
//

#ifndef SWORDOFFER_P39_BALANCEDTREE_H
#define SWORDOFFER_P39_BALANCEDTREE_H

#include <iostream>
#include <vector>
#include "P00_CommonHead.h"

using namespace std;

class P39_BalancedTree {
public:
    int test();

    bool IsBalanced_Solution(TreeNode *pRoot);

    bool IsBalanced(TreeNode *pRoot, int &dep);

};


#endif //SWORDOFFER_P39_BALANCEDTREE_H
