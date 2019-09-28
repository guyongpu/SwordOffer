//
// Created by yongpu on 2019/9/28.
//

#include "P62_KthNodeOfTree.h"

/*
 * 题目：二叉搜索树的第k个结点
 * 描述：给定一棵二叉搜索树，请找出其中的第k小的结点.
 * 输入：二叉树的根结点和k
 * 输出：返回第K小结点的指针
 * 思路：采用中序遍历做，其次，k要使用引用，否则k不会发生变化，当k等于0返回；当k小于0时停止递归。
 * 备注：注意复习。
 */

//采用中序遍历
TreeNode *P62_KthNodeOfTree::KthNode(TreeNode *pRoot, int k) {
    TreeNode *resNode = KthNode_Sub(pRoot, k);
    return resNode;
}

TreeNode *P62_KthNodeOfTree::KthNode_Sub(TreeNode *pRoot, int &k) {
    TreeNode *resNode = nullptr;
    if (pRoot == nullptr)
        return nullptr;
    if (pRoot->left && k>0) {
        resNode = KthNode_Sub(pRoot->left, k);
    }

    k--;
//    cout << pRoot->val << endl;
    if (k == 0) {
        resNode =  pRoot;
    }

    if (pRoot->right && k>0) {
        resNode = KthNode_Sub(pRoot->right, k);
    }
    return resNode;
}


int P62_KthNodeOfTree::test() {
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(7);
    TreeNode *p4 = new TreeNode(2);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(6);
    TreeNode *p7 = new TreeNode(8);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    TreeNode *pRoot = p1;

    TreeNode *resNode = KthNode(pRoot, 3);
    cout << resNode->val << endl;

    return 0;
}
