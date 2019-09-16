//
// Created by yongpu on 2019/9/16.
//

#include "P33_GetUglyNumber.h"

/*
 * 题目：丑数
 * 描述：把只包含质因子2、3和5的数称作丑数，找第N个丑数
 * 输入：index，第index个丑数
 * 输出：丑数的值
 * 思路：维护三个指针，每次找三个指针对应的乘积的最小值加入队列，同时进行移动指针。
 * 常规解法和优化解法
 */

//优化解法
int P33_GetUglyNumber::GetUglyNumber_Solution_1(int index) {
    if(index <= 0)
        return 0;
    vector<int> array = {1}; //第一个数为1
    int pos_2 = 0, pos_3 = 0, pos_5 = 0;
    int newNum = 1;
    for(int i = 0; i < index; i++)
    {
        int len = array.size();
        int push_num = min(min(array[pos_2]*2, array[pos_3]*3), array[pos_5]*5);
        if(array[pos_2]*2 == push_num)
            pos_2++;
        if(array[pos_3]*3 == push_num)
            pos_3++;
        if(array[pos_5]*5 == push_num)
            pos_5++;
        array.push_back(push_num);
    }
    //返回下标为index-1的数
    int result = array[index-1];
    return result;
}

//常规解法
int P33_GetUglyNumber::GetUglyNumber_Solution_2(int index) {
    if(index <= 0)
        return 0;
    vector<int> array = {1}; //第一个数为1
    for(int i = 0; i < index; i++)
    {
        int len = array.size();
        int num1, num2, num3;

        for(int i = 0; i < len; i++)
        {
            if(array[i]*2 > array[len-1])
            {
                num1 = array[i]*2;
                break;
            }
        }

        for(int i = 0; i < len; i++)
        {
            if(array[i]*3 > array[len-1])
            {
                num2 = array[i]*3;
                break;
            }
        }

        for(int i = 0; i < len; i++)
        {
            if(array[i]*5 > array[len-1])
            {
                num3 = array[i]*5;
                break;
            }
        }

        //在num1,num2,num3中选一个最小的放入array中
        int push_num = min(min(num1, num2), num3);
        array.push_back(push_num);
    }
    //返回下标为index-1的数
    int result = array[index-1];
    return result;
}

int P33_GetUglyNumber::test() {
    int result = GetUglyNumber_Solution_1(3);
    cout << result << endl;
    return 0;
}
