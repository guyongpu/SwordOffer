//
// Created by yongpu on 2019/9/13.
//

#ifndef SWORDOFFER_P00_COMMONHEAD_H
#define SWORDOFFER_P00_COMMONHEAD_H

#include <iostream>

using namespace std;

//链表子结构
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

//树的子结构
struct  TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

//复杂链表子结构
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode (int x) :
        label(x), next(NULL), random(NULL) {};
};

//三指针二叉树子结构
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

#endif //SWORDOFFER_P00_COMMONHEAD_H
