//
// Created by yongpu on 2019/9/13.
//

#ifndef SWORDOFFER_P20_STACK_FUNCMIN_H
#define SWORDOFFER_P20_STACK_FUNCMIN_H

#include <stack>
#include <iostream>

using namespace std;

class P20_Stack_FuncMin {
public:
    stack <int> stack_data,stack_min;
    void push(int value);
    void pop();
    int top();
    int min();
    int test();
};


#endif //SWORDOFFER_P20_STACK_FUNCMIN_H
