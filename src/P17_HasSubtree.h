//
// Created by yongpu on 2019/9/13.
//

#ifndef SWORDOFFER_P17_HASSUBTREE_H
#define SWORDOFFER_P17_HASSUBTREE_H

#include <iostream>
#include "P00_CommonHead.h"

using namespace std;

class P17_HasSubtree {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2);
    int test();
};


#endif //SWORDOFFER_P17_HASSUBTREE_H
