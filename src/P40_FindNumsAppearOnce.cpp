//
// Created by yongpu on 2019/9/23.
//

#include "P40_FindNumsAppearOnce.h"

/*
 * 题目：数组中只出现一次的数字
 * 描述：一个整型数组里除了两个数字之外，其他的数字都出现了两次
 * 输入：待查找的数组
 * 输出：只出现一次的两个数字
 * 思路：采用异或的思想，将所有数异或，得到不等于0的数，然后根据1的位置分为两组异或，然后在两组中获得num1和num2.
 * 备注：如果只有一个数出现一次，则直接异或即可得到结果。
 */

void P40_FindNumsAppearOnce::FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
    int len = data.size();
    if (len < 2)
        return;

    int resultOR = 0;
    for (int i = 0; i < len; i++) {         //对所有数进行异或运算
        resultOR = resultOR xor data[i];
    }

    //获得1的index
    int index = 0;
    while (1) {
        index++;
        if (resultOR & 0x1) {
            break;
        }
        resultOR = resultOR >> 1;
    }

    *num1 = 0;
    *num2 = 0;
    for (int j = 0; j < len; j++) {
        if ((data[j] >> (index - 1)) & 1) {   //对第index位为1的数进行异或运算
            *num1 = *num1 xor data[j];
        } else {                            //对第index位不为1的数进行异或运算
            *num2 = *num2 xor data[j];
        }
    }
//    cout << *num1 << endl;
//    cout << *num2 << endl;
}

int P40_FindNumsAppearOnce::test() {
//    vector<int> data = {1, 1, 2, 2, 3, 4, 5, 5, 6, 6};
    vector<int> data = {1, 1, 3, 6};
//    vector<int> data = {2,4,3,6,3,2,5,5};
    int num1, num2;
    FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}
