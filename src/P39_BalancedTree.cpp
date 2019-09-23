//
// Created by yongpu on 2019/9/23.
//

#include "P39_BalancedTree.h"

/*
 * 题目：平衡二叉树
 * 描述：输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 输入：二叉树的根结点
 * 输出：判断结果
 * 思路：法1：利用后序遍历思想，从下往上遍历，某一结点的深度等于其到叶子结点的路径的长度。
 * 法2：O(n^2)，对每个结点调用求深度的函数，然后判断。
 */

bool P39_BalancedTree::IsBalanced_Solution(TreeNode *pRoot) {
    int depth = 0;
    bool result = IsBalanced(pRoot, depth);
    return result;
}

bool P39_BalancedTree::IsBalanced(TreeNode *pRoot, int &dep) {
    if (pRoot == nullptr) {
        dep = 0;
        return true;
    }

    int dep_l = 0;
    int dep_r = 0;
    bool res_l = true;
    bool res_r = true;

    if (pRoot->left)
        res_l = IsBalanced(pRoot->left, dep_l);
    if (pRoot->right)
        res_r = IsBalanced(pRoot->right, dep_r);

    if (res_l && res_r) {
        if (abs(dep_l - dep_r) <= 1) {
            dep = 1 + max(dep_l, dep_r);
            return true;
        }
    }
    return false;
}


int P39_BalancedTree::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(1);
    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(1);
    TreeNode *t7 = new TreeNode(1);
    TreeNode *t8 = new TreeNode(1);
    TreeNode *t9 = new TreeNode(1);

    TreeNode *pRoot = t1;
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    t6->left = t8;
    t8->right = t9;
    bool result = IsBalanced_Solution(pRoot);
    cout << result << endl;
    return 0;
}
