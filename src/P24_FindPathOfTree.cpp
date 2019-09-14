//
// Created by yongpu on 2019/9/14.
//

#include "P24_FindPathOfTree.h"

/*
 * 题目：二叉树中和为某一值的路径
 * 描述：打印出二叉树中结点值的和为输入整数的所有路径，终点为叶子节点，按长度降序
 * 输入：root，二叉树根节点；expectNumber，整数和
 * 输出：result，所有的路径
 * 思路：按左右子树进行递归，当和相等且为叶子节点，则说明找到一条路径Path，然后将Path存入result中，
 * 如果不符合要求，则先将当前节点加入Path中，然后分别对左、右子树递归。
 * 题目不难，但要复习
 */

//比较器函数，按长度从大到小排序
bool cmp(vector<int> a, vector<int> b)
{
    return a.size() > b.size();
}

vector<vector<int> > P24_FindPathOfTree::FindPath(TreeNode *root, int expectNumber) {
    vector<vector <int>> result;
    //空树
    if(root == nullptr)
        return result;
    //只有一个节点的树
    if(root->val == expectNumber && root->left == nullptr && root->right == nullptr) // 叶子节点,找到一条路径
    {
        vector<int> Path;
        Path.push_back(root->val);
        result.push_back(Path); //存入result中
        return result;
    }

    //将当前节点加入到Path中
    int sum = root->val;
    vector<int> Path;
    Path.push_back(root->val);

    if(root->left) //左子树不为空，把左节点加入到Path中，然后递归
    {
        FindPath_Sub(root->left, sum, result, Path, expectNumber);
    }

    if(root->right) //右子树不为空，把右节点加入到Path中，然后递归
    {
        FindPath_Sub(root->right, sum, result, Path, expectNumber);
    }

    //排序
    sort(result.begin(),result.end(),cmp);

    return result;
}

void P24_FindPathOfTree::FindPath_Sub(TreeNode *node, int sum, vector<vector <int>> &result, vector<int> Path, int expectNumber) {
    if((node->val + sum == expectNumber) && (node->left == nullptr) && (node->right == nullptr)) // 当前节点满足和相等，且是叶子节点，则找到一条路径
    {
            Path.push_back(node->val);
            result.push_back(Path); //找到一条完整的路径，将Path存入result中
            return ;
    }

    sum = sum + node->val;          //加上node->val
    Path.push_back(node->val);      //node加入到Path中

    if(node->left) //左子树不为空，递归左子树
    {
        FindPath_Sub(node->left, sum, result, Path, expectNumber);
    }
    if(node->right) //右子树不为空，递归右子树
    {
        FindPath_Sub(node->right, sum, result, Path, expectNumber);
    }
}

int P24_FindPathOfTree::test() {
    TreeNode* p1 = new TreeNode(10);
    TreeNode* p2 = new TreeNode(5);
    TreeNode* p3 = new TreeNode(12);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p5 = new TreeNode(7);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    TreeNode* root = p1;
    vector<vector <int>> result = FindPath(root,22);
    cout << result[0].size() << endl;
    cout << result[1].size() << endl;
    return 0;
}
