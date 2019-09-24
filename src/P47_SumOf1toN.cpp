//
// Created by yongpu on 2019/9/24.
//

/*
 * 题目：求1+2+3+...+n
 * 描述：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 * 输入：累加的上界n
 * 输出：累加的结果
 * 思路：利用与运算的特点，(n>0) && (sum = n + Sum_Solution(n - 1))进行递归运算
 * 备注：构造函数法
 */

#include "P47_SumOf1toN.h"

int P47_SumOf1toN::Sum_Solution(int n) {
    int sum = 0;
    bool flag = (n>0) && (sum = n + Sum_Solution(n - 1));
    return sum;
}

int P47_SumOf1toN::test() {
    int result = Sum_Solution(3);
    cout << result;
    return 0;
}
