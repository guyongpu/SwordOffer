//
// Created by yongpu on 2019/9/13.
//

#include "P17_HasSubtree.h"

/*
 * 题目：树的子结构
 * 描述：判断树B是不是树A的子结构
 * 输入：pRoot1，树A的根节点；pRoot2，树B的根节点
 * 输出：返回判断结果
 * 思路：先找到一个节点值相等的节点，然后再递归进行计算，如果不包含，再在左右子树中找相等的节点。
 * HasSubtree，找到一个相等的节点
 * DoesTree1HaveTree2，开始计算两个树是否包含
 */

//找一个节点值相等的点
bool P17_HasSubtree::HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if(pRoot1 == nullptr || pRoot2 == nullptr)  //若其中一个为空树，则返回fasle
        return false;
    bool result = false;
    if(pRoot1->val == pRoot2->val){ //在pRoot1中找到一个节点值与pRoot2相等的节点
        result = DoesTree1HaveTree2(pRoot1,pRoot2); //开始递归计算是否是相等
    }
    if(result == false){    //如果不相等，则在左子树中查找相等的节点
        result = HasSubtree(pRoot1->left, pRoot2);
    }
    if(result == false){    //如果不相等，则在右子树中查找相等的节点
        result = HasSubtree(pRoot1->right, pRoot2);
    }
    return result;
}

//开始比较pRoot1为起点的子树是否包含pRoot2
bool P17_HasSubtree::DoesTree1HaveTree2(TreeNode *pRoot1, TreeNode *pRoot2) {
    if(pRoot2 == nullptr)
        return true;
    else if(pRoot1 == nullptr)
        return false;

    bool result = false;
    if(pRoot1->val == pRoot2->val)
    {
        result = DoesTree1HaveTree2(pRoot1->left, pRoot2->left);
        if(result == true)
            result = DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
        else
            result = false;
    }
    return result;
}

int P17_HasSubtree::test() {
    //pRoot1
    TreeNode* p11=new TreeNode(8);
    TreeNode* p12=new TreeNode(8);
    TreeNode* p13=new TreeNode(7);
    TreeNode* p14=new TreeNode(9);
    TreeNode* p15=new TreeNode(2);
    TreeNode* p16=new TreeNode(4);
    TreeNode* p17=new TreeNode(7);
    p11->left = p12;  p11->right = p13;
    p12->left = p14;  p12->right = p15;
    p15->left = p16;  p15->right = p17;
    TreeNode* pRoot1 = nullptr;
    pRoot1 = p11;

    //pRoot2
    TreeNode* p21=new TreeNode(8);
    TreeNode* p22=new TreeNode(8);
    TreeNode* p23=new TreeNode(8);
    p21->left = p22;  p21->right = p23;
    TreeNode* pRoot2 = nullptr;
    pRoot2 = p23;

    cout << HasSubtree(pRoot1, pRoot2) << endl;
    return 0;
}

