//
// Created by yongpu on 2019/9/27.
//

#ifndef SWORDOFFER_P58_ISSYMMETRICALTREE_H
#define SWORDOFFER_P58_ISSYMMETRICALTREE_H

#include <iostream>
#include "P00_CommonHead.h"

using namespace std;

class P58_IsSymmetricalTree {
public:
    bool isSymmetrical(TreeNode *pRoot);

    bool isSymmetrical_sub(TreeNode *rRoot, TreeNode *lRoot);

    int test();
};


#endif //SWORDOFFER_P58_ISSYMMETRICALTREE_H
