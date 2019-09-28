//
// Created by yongpu on 2019/9/28.
//

#ifndef SWORDOFFER_P65_PATHOFMATRIX_H
#define SWORDOFFER_P65_PATHOFMATRIX_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class P65_PathOfMatrix {
public:
    bool hasPath(char *matrix, int rows, int cols, char *str);

    bool hasPath_Sub(char *matrix, int rows, int cols, int row, int col, char *str, int &index, vector<bool> &visited);

    int test();
};


#endif //SWORDOFFER_P65_PATHOFMATRIX_H
