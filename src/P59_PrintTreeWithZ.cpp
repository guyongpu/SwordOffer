//
// Created by yongpu on 2019/9/27.
//

#include "P59_PrintTreeWithZ.h"

/*
 * 题目：按之字形顺序打印二叉树
 * 描述：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，其他行以此类推。
 * 输入：二叉树的根节点
 * 输出：打印结果
 * 思路：这是二叉树层序遍历的变式题，只需在打印是设置order控制打印顺序即可，其他和层序遍历是一样的。
 * 备注：复习层序遍历。
 */


vector<vector<int> > P59_PrintTreeWithZ::Print(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return vector<vector<int>>();
    vector<vector<int>> result;
    vector<TreeNode *> vec;
    vec.push_back(pRoot);
    bool order = true;                  //默认设置：left -> right

    while (vec.size()){                 //打印每一层
        vector<int> out_vec;            //存放当前一层的打印结果
        if(order){                      //left -> right，从左到右打印
            for(int i =0 ;i < vec.size();i++){
                out_vec.push_back(vec[i]->val);
            }
            order = false;
        }
        else{                           //right -> left，从右到左打印
            for(int i =vec.size()-1 ;i >=0;i--){
                out_vec.push_back(vec[i]->val);
            }
            order = true;
        }
        result.push_back(out_vec);      //保存打印结果

        vector<TreeNode *> vec_temp;    //存放下一层结点
        for(int i = 0;i<vec.size();i++){
            if(vec[i]->left)
            {
                vec_temp.push_back(vec[i]->left);
            }
            if(vec[i]->right)
            {
                vec_temp.push_back(vec[i]->right);
            }
        }
        vec = vec_temp;
    }
    return result;
}

int P59_PrintTreeWithZ::test() {
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
