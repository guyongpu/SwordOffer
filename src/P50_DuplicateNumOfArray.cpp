//
// Created by yongpu on 2019/9/25.
//

#include "P50_DuplicateNumOfArray.h"

/*
 * 题目：数组重复的数字
 * 描述：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，找出一个重复的数字。
 * 输入：数组指针，数组长度，重复元素指针
 * 输出：是否重复，重复数字
 * 思路：逐个遍历，如果numbers[i]!=i,判断numbers[i]与numbers[numbers[i]]是否相等，相等则说明是重复元素，否则numbers[i]与numbers[numbers[i]]交换位置.
 * 备注：n个数字，每个数组0~n-1之间，无此条件会越界，另外检查合法性.
 */

//时间复杂度O(n)，空间复杂度O(1)
bool P50_DuplicateNumOfArray::duplicate(int *numbers, int length, int *duplication) {
    //检查数据合法性
    if(numbers == nullptr || length <= 0){
        *duplication = -1;
        return false;
    }
    for (int i = 0; i < length; i++) {
        if(numbers[i]<0 || numbers[i]>length-1)
        {
            *duplication = -1;
            return false;
        }
    }
    //遍历交换数字
    for (int i = 0; i < length; i++) {
        while (numbers[i] != i) {
            int num = numbers[i];
            if (numbers[num] == numbers[i]) {
                *duplication = numbers[i];
                return true;
            }
            //swap(numbers[num], numbers[i])
            int temp = numbers[num];
            numbers[num] = numbers[i];
            numbers[i] = temp;
        }
    }
    *duplication = -1;
    return false;
}


int P50_DuplicateNumOfArray::test() {
//    int numbers[10] = {9, 4, 6, 7, 8, 3, 2, 1, 2, 6};
    int numbers[] = {9};
    //step1:{9,4,6,7,8,3,2,1,2,6};
    //step2:{6,4,6,7,8,3,2,1,2,9};
    //step3:{2,4,6,7,8,3,6,1,2,9};
    //step4:{6,4,2,7,8,3,6,1,2,9};
    //step5:{6,4,2,7,8,3,6,1,2,9};
    int duplication = 0;
    int length = sizeof(numbers) / sizeof(int);
    bool result;
    result= duplicate(numbers, length, &duplication);
    cout << result << " " << duplication << endl;
    return 0;
}
