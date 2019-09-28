//
// Created by yongpu on 2019/9/27.
//

#ifndef SWORDOFFER_P61_SERIALIZETREE_H
#define SWORDOFFER_P61_SERIALIZETREE_H

#include <iostream>
#include <cstring>
#include "P00_CommonHead.h"

using namespace std;

class P61_SerializeTree {
public:
    char *Serialize(TreeNode *root);

    string Serialize_Sub(TreeNode *root);

    TreeNode *Deserialize(char *str);

    void BuildTree(TreeNode **root, string str, int &index);

    int test();
};


#endif //SWORDOFFER_P61_SERIALIZETREE_H
