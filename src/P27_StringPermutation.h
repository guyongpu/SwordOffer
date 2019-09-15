//
// Created by yongpu on 2019/9/14.
//

#ifndef SWORDOFFER_P27_STRINGPERMUTATION_H
#define SWORDOFFER_P27_STRINGPERMUTATION_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P27_StringPermutation {
public:
    vector<string> Permutation(string str);
    void Permutation_Sub(string str, vector <string> &result, int begin);
    int test();

};


#endif //SWORDOFFER_P27_STRINGPERMUTATION_H
