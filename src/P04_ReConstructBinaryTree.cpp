//
// Created by yongpu on 2019/9/10.
//

#include "P04_ReConstructBinaryTree.h"

/*
 * 题目：重建二叉树
 * 描述：给出前序和中序遍历结果，然后重建二叉树
 * 思路：使用递归进行求解，reConstructBinaryTree构造一个节点，pre[0]为节点的值，根据pre[0]的位置将pre和vin进行分割，
 * 分别划分左子树的pre和vin，右子树的pre和vin，然后递归求解。
 */

TreeNode *P04_ReConstructBinaryTree::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    if(pre.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(pre[0]);

    vector<int>::iterator it = find(vin.begin(), vin.end(), pre[0]);//寻找pre[0]在vin中的位置
    int index = it - vin.begin();
    vector <int> pre_left, vin_left;   //左子树的前序和中序
    vector <int> pre_right, vin_right; //右子树的前序和中序
    //cout << "index = " << index<< endl;

    //给左子树的前序和中序赋值
    pre_left.assign(pre.begin() + 1, pre.begin() + 1 + index);
    vin_left.assign(vin.begin(), vin.begin()+index);
    //给右子树的前序和中序赋值
    pre_right.assign(pre.begin()+index+1, pre.end());
    vin_right.assign(vin.begin()+index+1, vin.end());

    //递归求解左子树和右子树
    root->left = reConstructBinaryTree(pre_left,vin_left);      //建立左子树
    root->right = reConstructBinaryTree(pre_right,vin_right);   //建立右子树
    return root;
}

int P04_ReConstructBinaryTree::test() {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    reConstructBinaryTree(pre, vin);
    return 0;
}
