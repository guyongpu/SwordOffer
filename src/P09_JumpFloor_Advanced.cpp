//
// Created by yongpu on 2019/9/11.
//

#include "P09_JumpFloor_Advanced.h"

/*
 * 题目：变态跳台阶
 * 描述：跳一次，可以跳上1,2,3,4...n级台阶，计算跳n级台阶的方法数量。
 * 输入：number，需要跳的台阶数
 * 输出：求得的方法种数
 * 思路：这里需要用数学归纳法
 * F(1) = 1
 * F(2) = F(2-1) + F(2-2)
 * F(3) = F(3-1) + F(3-2) + F(3-3)
 * F(4) = F(4-1) + F(4-2) + F(4-3) + F(4-4)
 * .....
 * F(n-1) = F(n-1-1) + F(n-1-2) + F(n-1-3) + ...... + F(n-1-n-1)
 *        = F(n-2) + F(n-3) + F(n-4) + ...... + F(0)
 * F(n) = F(n-1) + F(n-2) + F(n-3) + ...... + F(n-n)
 *      = F(n-1) + F(n-2) + F(n-3) + F(n-4) + ...... + F(0)
 *      = F(n-1) + F(n-1)
 * 所以，F(n) = 2*F(n-1) = 2^(n-1)
 */

int P09_JumpFloor_Advanced::jumpFloorII(int number) {
    int val = pow(2, number-1);
    return val;
}

int P09_JumpFloor_Advanced::test(){
    int val = jumpFloorII(8);
    cout << val << endl;
}
