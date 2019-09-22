//
// Created by yongpu on 2019/9/16.
//

#ifndef SWORDOFFER_P35_INVERSEPAIRS_H
#define SWORDOFFER_P35_INVERSEPAIRS_H

#include <vector>
#include <iostream>

using namespace std;

class P35_InversePairs {
public:
    int InversePairs_1(vector<int> data);
    long long int InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end);

    int InversePairs_2(vector<int> data);
    int test();
};


#endif //SWORDOFFER_P35_INVERSEPAIRS_H
