//
// Created by yongpu on 2019/9/11.
//

#include "P08_JumpFloor.h"

/*
 * 题目：跳台阶
 * 描述：跳number级台阶，求出有多少种跳法
 * 输入：number,台阶的数量
 * 输出：跳法的数量
 * 思路：用递归时间、空间复杂度太大，因此用非递归方法做，实际上也是斐波拉契数列数列，F(n)=F(n-1)+F(n-2)
 */

/*
//递归方法
int P08_JumpFloor::jumpFloor(int number) {
    if(number == 0)
        return 0;
    if(number == 1)
        return 1;
    if(number == 2)
        return 2;
    return jumpFloor(number - 1) + jumpFloor(number - 2);
}
*/

//非递归方法
int P08_JumpFloor::jumpFloor(int number) {
    int v1,v2,v3;
    v1 = 0;
    v2 = 1;
    for(int i =2; i <= number; i++)
    {
        v3 = v1 + v2;
        v1 = v2;
        v2 = v3;
    }
    return v3;
}


int P08_JumpFloor::test(){
    int val = jumpFloor(100);
    cout << val;
    return 0;
}