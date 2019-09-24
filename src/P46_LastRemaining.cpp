//
// Created by yongpu on 2019/9/24.
//

#include "P46_LastRemaining.h"

/*
 * 题目：孩子们的游戏(圆中最后剩下的数)
 * 描述：一个n大小的约瑟夫环，每次去掉一个数，知道只剩最后一个数即为结果
 * 输入：环大小n和取数间隔m
 * 输出：最后的结果
 * 思路：标准结果和常规解法
 */

//标准解法
/* 令k=m%n-1，重新映射:
 * k+1 -> 0
 * k+2 -> 1
 * k+3 -> 2
 * 0,1,2...组成新的子问题，设为F(n-1,m)
 * 设F(n-1,m)=x，x为最后的胜利者在F(n-1)中的编号，将x反映射到F(n,m)中，
 * 则x在F(n,m)中编号num = x+(k+1)，又k = m%n-1 所以：num = x + (m%n-1 +1) = x+m%n = (x+m)%n = (F(n-1,m)+m)%n
 * F(n,m) = (F(n-1,m) + m)%n
 */
int P46_LastRemaining::LastRemaining_Solution1(int n, int m) {
    if (n < 1 || m < 1)
        return -1;
    //当F(1,m) = 0
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = (result + m) % i;
    }
    return result;
}

//常规解法
/*
 * 声明一个n大小的数组，然后每次删除一个元素，知道vector大小为1，剩下的首元素的值即为结果。
 */
int P46_LastRemaining::LastRemaining_Solution2(int n, int m) {
    if (n < 1 || m < 1)
        return -1;
    vector<int> num(n);
    for (int i = 0; i < num.size(); i++) {
        num[i] = i;
    }
    int start = 0;
    while (num.size() != 1) {
        int len = num.size();
        int index = (start + m - 1) % len;
        start = index;
        num.erase(num.begin() + index);
    }
    int result = num[0];

    return result;
}

int P46_LastRemaining::test() {
    int result;
    int n = 5;
    int m = 3;
    result = LastRemaining_Solution1(n, m);
    cout << result << endl;
    result = LastRemaining_Solution2(n, m);
    cout << result << endl;
    return 0;
}
