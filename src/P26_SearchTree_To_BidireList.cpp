//
// Created by yongpu on 2019/9/14.
//

#include "P26_SearchTree_To_BidireList.h"

/*
 * 题目：二叉搜索树与双向链表
 * 描述：将二叉搜索树转换成一个排序的双向链表
 * 输入：二叉搜索树的根节点
 * 输出：链表的头节点
 * 思路：二叉搜索树进行中序遍历恰好是排序的结果，借用一个指向当前链表最后一个节点的指针来构建链表
 * 备注：想了很久没做出来，这题之后要注意复习
 */

TreeNode *P26_SearchTree_To_BidireList::Convert(TreeNode *pRootOfTree) {
    if(pRootOfTree == nullptr)
        return nullptr;
    TreeNode* pLastNodeInList = nullptr;            //pLastNodeInList指向双向链表的最后一个节点
    Convert_Sub(pRootOfTree, pLastNodeInList);  //利用中序遍历思想，中序遍历的输出恰好是排序的结果
    TreeNode* head = pRootOfTree;
    while(head->left)                               //向左找到头节点
    {
        head = head->left;
    }
    return head;
}

void P26_SearchTree_To_BidireList::Convert_Sub(TreeNode* pNode, TreeNode* &pLastNodeInList) {
    if (pNode == nullptr)
        return;
    TreeNode *pCurrent = pNode;

    //中序遍历的方式
    //1.先左子树
    if (pCurrent->left)
    {
        Convert_Sub(pCurrent->left, pLastNodeInList);
    }

    //2.访问节点，核心代码
    pCurrent->left = pLastNodeInList;   //pCurrent左指针指向最后一个节点pLastNodeInList
    if (pLastNodeInList) //如果当前链表的最后一个节点不为空，则将最后一个节点的右指针指向当前节点
    {
        pLastNodeInList->right = pCurrent;  //pLastNodeInList右指针指向pCurrent
    }
    pLastNodeInList = pCurrent; //当前节点成为链表尾节点

    //3.最后右子树
    if (pCurrent->right)
    {
        Convert_Sub(pCurrent->right, pLastNodeInList);
    }
}

int P26_SearchTree_To_BidireList::test() {
    TreeNode* p1 = new TreeNode(10);
    TreeNode* p2 = new TreeNode(6);
    TreeNode* p3 = new TreeNode(14);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p5 = new TreeNode(8);
    TreeNode* p6 = new TreeNode(12);
    TreeNode* p7 = new TreeNode(16);

 /*
 *         10
 *       /   \
 *     6      14
 *    / \    /  \
 *   4   8  12  16
 */
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    TreeNode* root = p1;
    TreeNode* head = Convert(root);
    while (head)
    {
        cout << head->val << " ";
        head = head->right;
    }

    return 0;
}