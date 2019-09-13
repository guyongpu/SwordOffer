//
// Created by yongpu on 2019/9/10.
//

#ifndef SWORDOFFER_P04_RECONSTRUCTBINARYTREE_H
#define SWORDOFFER_P04_RECONSTRUCTBINARYTREE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "P00_CommonHead.h"

using namespace std;


class P04_ReConstructBinaryTree {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) ;
    int test();
};


#endif //SWORDOFFER_P04_RECONSTRUCTBINARYTREE_H
