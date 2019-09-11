//
// Created by yongpu on 2019/9/11.
//

#include "P05_Queue_with_two_stacks.h"

/*
 * 题目：用两个栈实现队列
 * 描述：用两个栈，实现队列的Push和Pop操作，此处队列默认指的是先进先出队列
 * 函数1：push
 * 输入参数：int node
 * 返回值：无
 *
 * 函数2：pop
 * 输入参数：无
 * 返回值：队首元素值
 *
 * 思路：
 * 每次push，把node存入stack1中
 * 每次pop，判断stack2是否为空，如果为空，则将stack1的元素放入stack2中，然后stack2弹出栈顶元素；不为空则直接弹出元素即可。
 */
void P05_Queue_with_two_stacks::push(int node) {
    stack1.push(node);
}

int P05_Queue_with_two_stacks::pop() {
    if(stack2.empty())
    {
        while(!stack1.empty())
        {
            int val = stack1.top();
            stack2.push(val);
            stack1.pop();
        }
    }
    int val = stack2.top();
    stack2.pop();
    return val;
}

int P05_Queue_with_two_stacks::test() {
    push(1);
    push(2);
    push(3);
    cout << pop() << endl;
    cout << pop() << endl;
    push(4);
    cout << pop() << endl;
    push(5);
    cout << pop() << endl;
    cout << pop() << endl;
    return 0;
}
