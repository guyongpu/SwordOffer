//
// Created by yongpu on 2019/9/11.
//

#include "P07_Fibonacci.h"

/*
 * 题目：斐波拉契数列
 * 描述：求出斐波拉契数列的第n项
 * 输入：n：数列的第n项
 * 输出：斐波拉契数列第n项的值
 * 思路：用递归时间、空间复杂度太大，因此用非递归方法做
 */

/*
//递归方法
int P07_Fibonacci::Fibonacci(int n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
*/

//非递归方法
int P07_Fibonacci::Fibonacci(int n) {
    int v1,v2,v3;
    v1 = 0;
    v2 = 1;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    for(int i = 2; i <= n; i++)
    {
        v3 = v1 + v2;
        v1 = v2;
        v2 = v3;
    }
    return v3;
}

int P07_Fibonacci::test() {
    int val = Fibonacci(8);
    cout << val << endl;
    return 0;
}
