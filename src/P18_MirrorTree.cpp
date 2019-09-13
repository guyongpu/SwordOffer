//
// Created by yongpu on 2019/9/13.
//

#include "P18_MirrorTree.h"

/*
 * 题目：镜像二叉树
 * 描述：给定一个的二叉树，将其变换为原二叉树的镜像
 * 输入：原二叉树的根节点
 * 输出：返回镜像后的二叉树根节点
 * 思路：将树的左右子树进行交换，然后再分别对左右子树进行镜像处理。
 */

void P18_MirrorTree::Mirror(TreeNode *pRoot) {
    if(pRoot == nullptr)
        return ;
    TreeNode* ptemp = nullptr;

    //交换左右子树
    ptemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = ptemp;

    //左子树不为空，则递归处理左子树
    if(pRoot->left)
        Mirror(pRoot->left);
    //右子树不为空，则递归处理右子树
    if(pRoot->right)
        Mirror(pRoot->right);
}

int P18_MirrorTree::test() {
    TreeNode* p1 = new TreeNode(8);
    TreeNode* p2 = new TreeNode(6);
    TreeNode* p3 = new TreeNode(10);
    TreeNode* p4 = new TreeNode(5);
    TreeNode* p5 = new TreeNode(7);
    TreeNode* p6 = new TreeNode(9);
    TreeNode* p7 = new TreeNode(11);

    p1->left = p2; p1->right = p3;
    p2->left = p4; p2->right = p5;
    p3->left = p6; p3->right = p7;

    TreeNode* root = p1;
    Mirror(root);
    return 0;
}
