//
// Created by yongpu on 2019/9/14.
//

#include "P22_PrintFromTopToBottom.h"

/*
 * 题目：从上往下打印二叉树
 * 描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * 输入：root，二叉树的根节点
 * 输出：result，遍历的结果
 * 思路：本题书上的方法是采用先进先出队列，每遍历一个节点，则把该节点的左右节点放到队尾，知道队为空，则结束
 * 本人做法原理是一样的，只是用的vector实现，vectree存放本轮遍历的节点，一轮完成后，清空vectree，再把其子节点加入到vectree中，
 * 然后进行下一轮遍历，直到vectree的size为0，则说明所有节点已遍历。
 */

vector<int> P22_PrintFromTopToBottom::PrintFromTopToBottom(TreeNode *root) {
     vector <int> result;
     vector <TreeNode *> vectree;   //一层的所有节点
     if(root) //树不为空，则加入到vectree中
         vectree.push_back(root);
     while(1){
         // 遍历vectree中的所有元素
         for(int i =0; i < vectree.size(); i++)
         {
             result.push_back(vectree[i]->val);
         }

         vector <TreeNode *> vectreetmp;    //设置中间容器vectreetmp
         vectreetmp = vectree;              //将vectree赋值给vectreetmp
         vectree.clear();                   //清空vectree
         for(int i =0; i < vectreetmp.size(); i++)  //将vectreetmp中的节点的左右子节点加入到vectree中
         {
             if(vectreetmp[i]->left)
                 vectree.push_back(vectreetmp[i]->left);
             if(vectreetmp[i]->right)
                 vectree.push_back(vectreetmp[i]->right);
         }
         if(vectree.size()==0) //下一次遍历的节点为0，表示遍历完毕
             break;
     }
    return result;
}

int P22_PrintFromTopToBottom::test() {
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
    p3->left = p6;
    p3->right = p7;

    TreeNode *root = p1;
    vector <int> result = PrintFromTopToBottom(root);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
