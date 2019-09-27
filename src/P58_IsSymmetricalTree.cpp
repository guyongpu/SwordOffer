//
// Created by yongpu on 2019/9/27.
//

#include "P58_IsSymmetricalTree.h"

/*
 * 题目：对称的二叉树
 * 描述：请实现一个函数，用来判断一颗二叉树是不是对称的
 * 输入：树的根节点
 * 输出：是否是对称
 * 思路：二叉树左右节点递归比较，左节点与右节点比较，同为空或者val值相等。
 * 备注：注意复习
 */

bool P58_IsSymmetricalTree::isSymmetrical(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return false;
    bool result = isSymmetrical_sub(pRoot->left, pRoot->right);
    return result;
}

bool P58_IsSymmetricalTree::isSymmetrical_sub(TreeNode *rRoot, TreeNode *lRoot) {
    if (rRoot == nullptr && lRoot == nullptr)
        return true;
    if ((rRoot != nullptr && lRoot != nullptr) && (rRoot->val == lRoot->val)) { //左右节点不为空且值相等，然后继续递归
        bool flag1 = isSymmetrical_sub(rRoot->left, lRoot->right);
        bool flag2 = isSymmetrical_sub(rRoot->right, lRoot->left);
        return (flag1 && flag2);
    } else
        return false;
}

int P58_IsSymmetricalTree::test() {
    TreeNode *t1 = new TreeNode(8);
    TreeNode *t2 = new TreeNode(6);
    TreeNode *t3 = new TreeNode(6);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(7);
    TreeNode *t6 = new TreeNode(7);
    TreeNode *t7 = new TreeNode(5);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    TreeNode *pRoot = t1;

    bool res = isSymmetrical(pRoot);
    cout << res << endl;

    return 0;
}

