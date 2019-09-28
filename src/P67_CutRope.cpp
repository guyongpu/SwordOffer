//
// Created by yongpu on 2019/9/28.
//

#include "P67_CutRope.h"

/**
 * 题目：剪绳子
 * 描述：一根长度为n的绳子，请把绳子剪成m段，记为k[0]、k[1]、...k[m]，请问k[0]xk[1]x...xk[m]可能的最大乘积
 * 输入：绳子的长度
 * 输出：得到的最大乘积
 * 思路：采用动态规划或者贪心算法均可求解
 * 备注：两种方法都需要掌握
 */


/**
 * 公式：f(n) = max(f(i) * f(n-i))
 * 从上到下分支过多，所以采用从下到上的方式计算，即先计算f(2),f(3),再得到f(4),f(5)
 */

// 动态规划
int P67_CutRope::cutRope_dp(int number) {
    if (number < 2)
        return 0;
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;

    int *products = new int[number + 1];

    //下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
    //这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for (int i = 4; i <= number; i++) {
        max = 0;
        for (int j = 1; j <= i / 2; j++) {
            int pro = products[j] * products[i - j];
            if (max < pro)
                max = pro;
        }
        products[i] = max;
    }
    int result = products[number];
    delete[] products;
    return result;
}

/**
 * 题目分析：
 * 先举几个例子，可以看出规律来。
 * 4 ： 2*2
 * 5 ： 2*3
 * 6 ： 3*3
 * 7 ： 2*2*3 或者4*3
 * 8 ： 2*3*3
 * 9 ： 3*3*3
 * 10：2*2*3*3 或者4*3*3
 * 11：2*3*3*3
 * 12：3*3*3*3
 * 13：2*2*3*3*3 或者4*3*3*3
 *
 * 下面是分析：
 * 首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。
 * 当然也可能有4，但是4=2*2，我们就简单些不考虑了。
 * 5<2*3,6<3*3,比6更大的数字我们就更不用考虑了，肯定要继续分。
 * 其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2*2*2<3*3，那么题目就简单了。
 * 直接用n除以3，根据得到的余数判断是一个2还是两个2还是没有2就行了。
 * 由于题目规定m>1，所以2只能是1*1，3只能是2*1，这两个特殊情况直接返回就行了。
 *
 * 乘方运算的复杂度为：O(log n)，用动态规划来做会耗时比较多。
 */

//贪心算法
int P67_CutRope::cutRope_greed(int number) {
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;
    int num3 = number / 3;

    if (number - num3 * 3 == 1)  //最后剩下1米，则对最后4米单独处理
    {
        num3--;
    }
    int remain = number - num3 * 3;
    int num2 = remain / 2;

    int result = pow(3, num3) * pow(2, num2);

    return result;
}

int P67_CutRope::test() {
    int number = 8;
    int res_dp = cutRope_dp(number);
    int res_gr = cutRope_greed(number);

    cout << res_dp << endl;
    cout << res_gr << endl;

    return 0;
}
