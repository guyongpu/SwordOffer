//
// Created by yongpu on 2019/9/14.
//

#ifndef SWORDOFFER_P26_SEARCHTREE_TO_BIDIRELIST_H
#define SWORDOFFER_P26_SEARCHTREE_TO_BIDIRELIST_H

#include <iostream>
#include "P00_CommonHead.h"

using namespace std;

class P26_SearchTree_To_BidireList {
public:
    TreeNode* Convert(TreeNode* pRootOfTree);
    void Convert_Sub(TreeNode* pRootOfTree, TreeNode* &pre);
    int test();
};


#endif //SWORDOFFER_P26_SEARCHTREE_TO_BIDIRELIST_H
