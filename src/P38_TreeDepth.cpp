//
// Created by yongpu on 2019/9/23.
//

#include "P38_TreeDepth.h"

/*
 * 题目：二叉树的深度
 * 描述：输入一棵二叉树，求该树的深度。
 * 输入：二叉树的根结点
 * 输出：二叉树的深度
 * 思路：使用层序遍历思想，1.队列实现；2.vector实现；3.递归实现
 * 备注：还可以改为输出最长的路径结果，结合P24做即可。
 */

int P38_TreeDepth::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(1);
    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(1);
    TreeNode *t7 = new TreeNode(1);
    TreeNode *t8 = new TreeNode(1);

    TreeNode *pRoot = t1;
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    t6->left = t8;
    int Deep = TreeDepth2(pRoot);
    cout << Deep << endl;
    return 0;
}

//非递归---使用vector实现
int P38_TreeDepth::TreeDepth1(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return 0;
    vector<TreeNode *> TVec;
    TVec.push_back(pRoot);
    int Deep = 0;
    while (TVec.size()) {
        vector<TreeNode *> TVec_temp;
        for (int i = 0; i < TVec.size(); i++) {
            if (TVec[i]->left) {
                TVec_temp.push_back(TVec[i]->left);
            }
            if (TVec[i]->right) {
                TVec_temp.push_back(TVec[i]->right);
            }
        }
        TVec.clear();
        TVec = TVec_temp;
        Deep++;
    }
    return Deep;
}

//非递归---使用queue实现
int P38_TreeDepth::TreeDepth2(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return 0;
    queue<TreeNode *> TQue;
    TQue.push(pRoot);
    int count_cur = 1;
    int Deep = 0;
    while (TQue.size()) {
        while (count_cur--) {       //当前层结点的数目
            TreeNode *Temp = TQue.front();
            if (Temp->left) {
                TQue.push(Temp->left);
            }
            if (Temp->right) {
                TQue.push(Temp->right);
            }
            TQue.pop();
        }
        count_cur = TQue.size();    //下一层结点数
        Deep++;                     //深度+1
    }

    return Deep;
}

//递归
int P38_TreeDepth::TreeDepth3(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return 0;
    int leftDeep = TreeDepth2(pRoot->left);
    int rightDeep = TreeDepth2(pRoot->right);
    int Deep = max(leftDeep, rightDeep) + 1;
    return Deep;
}
