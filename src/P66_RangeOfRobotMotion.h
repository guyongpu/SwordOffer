//
// Created by yongpu on 2019/9/28.
//

#ifndef SWORDOFFER_P66_RANGEOFROBOTMOTION_H
#define SWORDOFFER_P66_RANGEOFROBOTMOTION_H

#include <iostream>
#include <vector>

using namespace std;

class P66_RangeOfRobotMotion {
public:
    int movingCount(int threshold, int rows, int cols);
    int movingCount_Sub(int threshold, int rows,int cols,int row,int col,vector<bool> &visited);
    bool check(int threshold, int rows,int cols,int row,int col,vector<bool> &visited);
    int getDigitSum(int number);
    int test();

};


#endif //SWORDOFFER_P66_RANGEOFROBOTMOTION_H
