//
// Created by yongpu on 2019/9/28.
//

#ifndef SWORDOFFER_P67_CUTROPE_H
#define SWORDOFFER_P67_CUTROPE_H

#include <iostream>
#include <cmath>

using namespace std;

class P67_CutRope {
public:
    int cutRope_dp(int number);     //动态规划
    int cutRope_greed(int number);  //贪心算法
    int test();
};


#endif //SWORDOFFER_P67_CUTROPE_H
