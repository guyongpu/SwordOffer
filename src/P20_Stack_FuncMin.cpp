//
// Created by yongpu on 2019/9/13.
//

#include "P20_Stack_FuncMin.h"

/*
 * 题目：包含min函数的栈
 * 描述：实现一个能够得到栈中所含最小元素的min函数
 * 思路：本题目需要使用两个栈，数据栈和辅助栈。
 * 数据栈存放正常的数据，辅助栈存放当前情况下最小的元素，
 * 辅助栈两种方式，方式1是可以只在压栈元素比栈顶元素小或等于才入栈，出栈则与辅助栈顶元素相等才出栈
 * 方式2是可以采用当压栈元素比栈顶元素大，压入相同栈顶元素的方式，出栈则直接出栈；
 * 方式1方便，但是空间开销会大一些，而方式2则空间开销小一些。
 */

void P20_Stack_FuncMin::push(int value)
{
    stack_data.push(value);
    if(stack_min.size() == 0){
        stack_min.push(value);
    }
    else{
        int tmp = stack_min.top();
        if(value <= tmp){
            stack_min.push(value);
        }
    }
}
void P20_Stack_FuncMin::pop()
{
    int tmp = stack_data.top();
    stack_data.pop();
    if(tmp == stack_min.top()){
        stack_min.pop();
    }
}

int P20_Stack_FuncMin::top()
{
    return stack_data.top();
}

int P20_Stack_FuncMin::min()
{
    return stack_min.top();
}

int P20_Stack_FuncMin::test()
{
    push(5);
    push(3);
    push(5);
    push(4);
    cout << min() << endl;
    pop();
    cout << min() << endl;

}
