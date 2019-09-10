//
// Created by yongpu on 2019/9/10.
//

#ifndef SWORDOFFER_P04_RECONSTRUCTBINARYTREE_H
#define SWORDOFFER_P04_RECONSTRUCTBINARYTREE_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL){};
};

class P04_ReConstructBinaryTree {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) ;
    int test();
};


#endif //SWORDOFFER_P04_RECONSTRUCTBINARYTREE_H
