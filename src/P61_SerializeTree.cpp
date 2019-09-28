//
// Created by yongpu on 2019/9/27.
//

#include "P61_SerializeTree.h"

/*
 * 题目：序列号二叉树
 * 描述：实现二叉树的序列化，并实现二叉树的反序列化
 * 输入：序列化：树的根节点；反序列化：字符串
 * 输出：序列化：序列化结果；反序列化：树的根节点
 * 思路：序列化采用先序遍历完成，反序列化遍历字符串，逐步重建树
 * 备注：此题比较麻烦，记得复习
 */


char *P61_SerializeTree::Serialize(TreeNode *root) {
    if (root == nullptr) {
        char *str = new char[2];
        strcpy(str, "#");
        return str;
    }
    string strRes = Serialize_Sub(root);

    int len = strRes.length();
    char *str = new char[len + 1];
    strcpy(str, strRes.c_str());
//    cout << str << endl;
    return str;
}

string P61_SerializeTree::Serialize_Sub(TreeNode *root) {
    if (root == nullptr) {
        string str = "#";
        return str;
    }
    int val = root->val;

    string str;
    str = to_string(val) + ",";

    string str_L = Serialize_Sub(root->left);
    string str_R = Serialize_Sub(root->right);

    str = str + str_L + str_R;

    return str;
}

TreeNode *P61_SerializeTree::Deserialize(char *str) {
    TreeNode *root = nullptr;
    string strRes(str);
    int index = 0;
    BuildTree(&root, strRes, index);
    return root;
}


void P61_SerializeTree::BuildTree(TreeNode **root, string str, int &index) {
    if (str[index] != '#') {
        int pos = 0;
        for (int i = index; i < str.length(); i++) {
            if (str[i] == ',') {
                pos = i;    //pos指向,
                break;
            }
        }
        int val = atoi(str.substr(index, pos - index).c_str());
        index = pos;
        *root = new TreeNode(val);

        index = index + 1;
        BuildTree((&(*root)->left), str, index);
        index = index + 1;
        BuildTree((&(*root)->right), str, index);
    }
}


int P61_SerializeTree::test() {
    TreeNode *p1 = new TreeNode(8);
    TreeNode *p2 = new TreeNode(6);
    TreeNode *p3 = new TreeNode(10);
    TreeNode *p4 = new TreeNode(5);
    TreeNode *p5 = new TreeNode(7);
    TreeNode *p6 = new TreeNode(9);
    TreeNode *p7 = new TreeNode(11);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p5;
    p3->right = p6;

    TreeNode *pRoot = p1;
    char *strRes1 = Serialize(pRoot);//8,6,5,##7,##10,7,##9,##      格式要求比较奇怪
    cout << strRes1 << endl;

    TreeNode *pRoot1 = Deserialize("1,2,##3,##");
    system("pause");
    return 0;
}

