//
// Created by yongpu on 2019/9/27.
//

#include "P60_PrintTreeWithMultiLine.h"

/*
 * 题目：把二叉树打印成多行
 * 描述：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 * 输入：二叉树的根节点
 * 输出：打印结果
 * 思路：二叉树的层序遍历。
 * 备注：掌握二叉树遍历方法
 */

vector<vector<int> > P60_PrintTreeWithMultiLine::Print(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return vector<vector<int>>();
    vector<TreeNode *> vec;
    vec.push_back(pRoot);
    vector<vector<int>> result;
    while (vec.size()) {
        vector<int> out_vec;
        for (int i = 0; i < vec.size(); i++) {
            out_vec.push_back(vec[i]->val);
        }
        result.push_back(out_vec);

        vector<TreeNode *> vec_temp;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i]->left) {
                vec_temp.push_back(vec[i]->left);
            }
            if (vec[i]->right) {
                vec_temp.push_back(vec[i]->right);
            }
        }
        vec = vec_temp;
    }
    return result;
}

int P60_PrintTreeWithMultiLine::test() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    TreeNode *p7 = new TreeNode(7);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    TreeNode *pRoot = p1;
    vector<vector<int>> result;
    result = Print(pRoot);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

