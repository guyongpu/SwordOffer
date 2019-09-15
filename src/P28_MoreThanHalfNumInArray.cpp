//
// Created by yongpu on 2019/9/15.
//

#include "P28_MoreThanHalfNumInArray.h"

/*
 * 题目：数组中出现次数超过一半的数字
 * 描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字，不存在则输出0.
 * 输入：numbers,数组
 * 输出：result，超过一半的数，不存在则输出0
 * 思路：采用阵地攻守的思想。
 * 第一个数字作为第一个士兵，守阵地；count = 1；
 * 遇到相同元素，count++;
 * 遇到不相同元素，即为敌人，同归于尽,count--；当遇到count为0的情况，又以新的i值作为守阵地的士兵，继续下去，到最后还留在阵地上的士兵，有可能是主元素。
 * 再加一次循环，记录这个士兵的个数看是否大于数组一半即可。
 */

int P28_MoreThanHalfNumInArray::MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.size()==0)
        return 0;

    //1.设置首元素
    int result = numbers[0];
    int count = 1;
    //2.开始遍历，找可能的结果result
    for(int i = 1; i < numbers.size(); i++)
    {
        if(count == 0){
            result  = numbers[i];
            count = 1;
            continue ;
        }
        if(result == numbers[i])
            count ++;
        else
            count--;
    }
    //3.检查result是否大于一半
    if(count > 0)
    {
        //检查reslut是否符合要求
        int count = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(result == numbers[i])
                count ++;
        }
        if(count > numbers.size()/2)    //大于一半，返回result
            return result;
    }
    //返回0
    return 0;
}

int P28_MoreThanHalfNumInArray::test() {
    vector <int> numbers = {2,2,2,2,2,1,3,4,5};
    int num = MoreThanHalfNum_Solution(numbers);
    cout << num << endl;
    return 0;
}