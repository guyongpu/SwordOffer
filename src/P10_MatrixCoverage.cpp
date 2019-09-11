//
// Created by yongpu on 2019/9/11.
//

#include "P10_MatrixCoverage.h"

/*
 * 题目：矩形覆盖
 * 描述：用2*1的矩形去覆盖一个2*number的大矩形，计算方法数
 * 输入：number，大矩形的长度
 * 输出：覆盖的方法数
 * 思路：这个题与青蛙跳台阶的题目类似，F(1)=1,F(2)=2,F(n)=F(n-1)+F(n-2)
 * 递归会导致空间溢出，要采用非递归方法
 */

/*
//递归方法
int P10_MatrixCoverage::rectCover(int number){
    if(number == 1)
        return 1;
    if(number ==2)
        return 2;
    return rectCover(number -1) + rectCover(number-2);
}
*/

//非递归方法
int P10_MatrixCoverage::rectCover(int number){
    if(number == 0)
        return 0;
    if(number == 1)
        return 1;
    if(number ==2)
        return 2;

    int v1,v2,v3;
    v1 = 1;
    v2 = 2;
    for(int i = 3; i <= number; i++)
    {
        v3 = v1 + v2;
        v1 = v2;
        v2 = v3;
    }
    return v3;
}


int P10_MatrixCoverage::test(){
    int val = rectCover(10);
    cout << val << endl;
    return 0;
}