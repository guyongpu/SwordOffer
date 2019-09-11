//
// Created by yongpu on 2019/9/11.
//

#ifndef SWORDOFFER_P05_QUEUE_WITH_TWO_STACKS_H
#define SWORDOFFER_P05_QUEUE_WITH_TWO_STACKS_H

#include <stack>
#include <iostream>

using namespace std;

class P05_Queue_with_two_stacks {
public:
    void push(int node);
    int pop();
    int test();

private:
    stack <int> stack1;
    stack <int> stack2;
};


#endif //SWORDOFFER_P05_QUEUE_WITH_TWO_STACKS_H
