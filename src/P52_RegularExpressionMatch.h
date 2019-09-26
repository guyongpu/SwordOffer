//
// Created by yongpu on 2019/9/26.
//

#ifndef SWORDOFFER_P52_REGULAREXPRESSIONMATCH_H
#define SWORDOFFER_P52_REGULAREXPRESSIONMATCH_H

#include <iostream>
#include <cstring>

using namespace std;

class P52_RegularExpressionMatch {
public:
    bool match(char* str, char* pattern);
    bool matchCore(char* str, char* pattern);
    int test();
};


#endif //SWORDOFFER_P52_REGULAREXPRESSIONMATCH_H
