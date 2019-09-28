//
// Created by yongpu on 2019/9/28.
//

#ifndef SWORDOFFER_P63_MIDNUMOFDATA_H
#define SWORDOFFER_P63_MIDNUMOFDATA_H

#include <iostream>
#include <vector>
#include <algorithm> //建堆要用到的头文件

using namespace std;

class P63_MidNumOfData {
public:
    void Insert(int num);
    double GetMedian();
    int test();

    vector<int> LeftVec;     //左边
    vector<int> RightVec;     //右边
};


#endif //SWORDOFFER_P63_MIDNUMOFDATA_H
