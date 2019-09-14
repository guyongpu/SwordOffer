//
// Created by yongpu on 2019/9/14.
//

#include "P23_VerifySquenceOfBST.h"

/*
 * 题目：二叉搜索树的后序遍历序列
 * 描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 输入：sequence，一个待判断的整数数列
 * 输出：判断结果
 * 思路：后序遍历的最后一个元素是根，则序列必须可以分为左右两部分，左部分<root，右部分>root，不满足则返回false，满足则继续进行递归。
 * 递归结束条件：每一个sequence只有一个元素，则返回true.
 */

bool P23_VerifySquenceOfBST::VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size() == 0)    //如果输入序列为空，则输出false
        return false;
    if(sequence.size() == 1)    //如果只有一个元素，则输出true，递归结束条件
        return true;
    int root = sequence[sequence.size()-1]; //最后一个元素，即根节点

    //找一个位置pos，可以把sequence分为大于root和小于root的两类
    int pos = sequence.size()-1-1; //不能初始化为0，因为有可能前面所有元素都小于root
    for(int i = 0; i < sequence.size()-1; i++)
    {
        if(sequence[i] < root)
            ;
        else
        {
            pos = i-1;  //注意有可能所有元素都小于root，则不会进入这一步，所以前面要将pos = sequence.size()-1-1
            break;
        }
    }

    //pos将sequence分为[0, pos]和[pos+1, sequence.size()-1-1]两段，分别验证是否满足条件
    //1.检查左边，[0, pos]，元素应该 < root
    bool res_letf = true;
    for(int i = 0; i <= pos; i++)
    {
        if(sequence[i] >= root)
        {
            res_letf = false;
            break;
        }
    }
    if(res_letf == false)
        return false;

    //2.检查右边，[pos+1, sequence.size()-1-1]，元素应该 > root
    int res_right = true;
    for(int i = pos+1; i <= sequence.size()-1-1; i++)
    {
        if(sequence[i] <= root)
        {
            res_right = false;
            break;
        }
    }
    if(res_right == false)
        return false;

    //通过验证，继续递归,sequence_left元素为[0, pos]、sequence_right元素为[pos+1, sequence.size()-1-1]
    vector<int> sequence_left, sequence_right;
    sequence_left.assign(sequence.begin(), sequence.begin()+pos+1);     //assign(a,b)是复制[a,b-1]区间的数值，所以还要加1
    sequence_right.assign(sequence.begin()+pos+1, sequence.begin()+sequence.size()-1-1+1);

    //递归判断
    bool res_1 = true, res_2 = true;
    if(sequence_left.size() > 0)
        res_1 = VerifySquenceOfBST(sequence_left);
    if(sequence_right.size() > 0)
        res_2 = VerifySquenceOfBST(sequence_right);
    if(res_1 && res_2)
        return true;
    return false;
}

int P23_VerifySquenceOfBST::test() {
    vector <int> sequence1 = {5, 7, 6, 9, 11, 10, 8};
    vector <int> sequence2 = {1, 2, 3, 4, 5};
    sequence2.clear();
    bool res = VerifySquenceOfBST(sequence2);
    cout << res << endl;
    return 0;
}