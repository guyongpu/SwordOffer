//
// Created by yongpu on 2019/9/14.
//

#ifndef SWORDOFFER_P24_FINDPATHOFTREE_H
#define SWORDOFFER_P24_FINDPATHOFTREE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "P00_CommonHead.h"

using namespace std;

class P24_FindPathOfTree {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber);
    void FindPath_Sub(TreeNode* node, int sum, vector<vector <int>> &result, vector<int> Path, int expectNumber);
    int test();
};


#endif //SWORDOFFER_P24_FINDPATHOFTREE_H
