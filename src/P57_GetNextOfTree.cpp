//
// Created by yongpu on 2019/9/27.
//

#include "P57_GetNextOfTree.h"

/*
 * 题目：二叉树的下一个结点
 * 描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回.
 * 输入：给定的结点
 * 输出：中序遍历的下一个结点
 * 思路：分3种情况。1.pNode是父结点的左结点，则直接返回父结点;2.pNode是父结点的右节点，则一直向上找，直到pFFNode->left = pFNode，返回pFFNode;3.如果有右子树，则一直找最左结点.
 * 备注：考虑父结点为空.
 */


TreeLinkNode *P57_GetNextOfTree::GetNext(TreeLinkNode *pNode) {
    //右子树为空，向上找。判断pNode是否是父结点的左结点
    if (pNode->right == nullptr) {
        TreeLinkNode *pFNode = pNode->next;

        //父结点为空，返回nullptr
        if (pFNode == nullptr)
            return nullptr;

        //情况1：pNode是父结点的左结点，则直接返回父结点
        if (pFNode->left == pNode)
            return pFNode;
        else {
            //情况2：pNode是父结点的右节点，则一直向上找，直到pFFNode->left = pFNode，返回pFFNode
            TreeLinkNode *pFFNode = pFNode->next;
            while (pFFNode) {
                if (pFFNode->left == pFNode)
                    break;
                else {
                    pFNode = pFNode->next;
                    pFFNode = pFNode->next;
                }
            }
            return pFFNode;
        }
    } else {  //右子树不为空，向下找。
        //情况3：如果有右子树，则一直找最左结点
        TreeLinkNode *child = pNode->right;
        while (1) {
            if (child->left) {
                child = child->left;
            } else
                break;
        }
        return child;
    }
}

int P57_GetNextOfTree::test() {
    TreeLinkNode *p1 = new TreeLinkNode(1);
    TreeLinkNode *p2 = new TreeLinkNode(2);
    TreeLinkNode *p3 = new TreeLinkNode(3);
    TreeLinkNode *p4 = new TreeLinkNode(4);
    TreeLinkNode *p5 = new TreeLinkNode(5);
    TreeLinkNode *p6 = new TreeLinkNode(6);
    TreeLinkNode *p7 = new TreeLinkNode(7);
    TreeLinkNode *p8 = new TreeLinkNode(8);
    TreeLinkNode *p9 = new TreeLinkNode(9);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;
    p2->next = p2;

    p3->left = p6;
    p3->right = p7;
    p3->next = p1;

    p4->next = p2;

    p5->left = p8;
    p5->right = p9;
    p5->next = p2;

    p6->next = p3;

    p7->next = p3;

    TreeLinkNode *res = GetNext(p6);
    cout << res->val << endl;

    return 0;
}
