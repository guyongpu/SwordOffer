//
// Created by yongpu on 2019/9/14.
//

#include "P21_IsPopOrderOfStack.h"

/*
 * 题目：栈的压入、弹出序列
 * 描述：判断一个序列是否可能为一个栈的弹出顺序
 * 输入：pushV，压栈序列；popV，出栈序列
 * 输出：是否是出栈序列
 * 思路：遍历pushV[i]，如果遇到popV[cnt]相等，先压栈，然后popV[cnt]与栈中逐个比较，否则直接将pushV[i]压入栈中
 * 当cnt与popV的size相等时，则说明匹配成功，否则匹配失败。
 */

bool P21_IsPopOrderOfStack::IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int> stack_data;
    int cnt = 0;                                //popV的计数器
    for(int i = 0; i < pushV.size(); i++)
    {
        if(pushV[i] == popV[cnt])               //遇到相等的元素
        {
            stack_data.push(pushV[i]);          //先压栈
            while(1){                           //开始匹配
                if(stack_data.empty())          //栈为空，则退出匹配
                    break;
                int tmp_stk = stack_data.top(); //栈顶元素
                int tmp_pop = popV[cnt];        //popV的元素
                if(tmp_stk == tmp_pop){         //相等
                    stack_data.pop();           //stack出栈
                    cnt++;                      //popV计数器加1
                }
                else{                           //不相等，则退出
                    break;
                }
            }
        }
        else    //不相等，则压栈
        {
            stack_data.push(pushV[i]);
        }
    }
    if(cnt == popV.size())                      //当cnt相等时，则说明匹配成功
        return true;
    return false;
}

int P21_IsPopOrderOfStack::test()
{
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    bool result = IsPopOrder(pushV, popV);
    cout << result << endl;
    vector<int> popV2 = {4,3,5,1,2};
    result = IsPopOrder(pushV, popV2);
    cout << result << endl;
    return 0;
}
