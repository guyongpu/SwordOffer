//
// Created by yongpu on 2019/9/16.
//

#include "P31_NumberOf1Between1AndN.h"

/*
 * 题目：整数中1出现的次数
 * 描述：从1到整数N中1出现的次数
 * 输入：n，整数
 * 输出：reulst，1出现的次数
 * 思路：逐位思考，可以计算1~9出现的次数，修改x即可，0除外。
 * 参考：https://www.cnblogs.com/nailperry/p/4752987.html
 */

/*
 *
 * 总结一下以上的算法，可以看到，当计算右数第 i 位包含的 X 的个数时：
 * 1.取第 i 位左边（高位）的数字，乘以 10^(i−1)，得到基础值 a
 * 2.取第 i 位数字，计算修正值：
 *      如果大于 X，则结果为 a+10^(i−1) ,则十位上可能出现的X的次数仅由更高位决定
 *      如果小于 X，则结果为 a ,则个位上可能出现的X的次数仅由更高位决定
 *      如果等于 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1 ,百位上可能出现X的次数不仅受更高位影响，还受低位影响
 * 相应的代码非常简单，效率也非常高，时间复杂度只有 O(log10n)
 */
int P31_NumberOf1Between1AndN::NumberOf1Between1AndN_Solution(int n) {
    int  x= 1;
    if(n < 0)
        return 0;
    int high, low, cur, tmp, i = 1;
    high = n;
    int reulst = 0;
    while(high != 0){
        high = n / (int)pow(10, i);         //当前位左边部分
        tmp  = n % (int)pow(10, i);
        cur  = tmp / (int)pow(10, i-1); //当前位
        low  = tmp % (int)pow(10, i-1); //当前位右边部分
        //例如2593,计算5的个数
        //当i=1, 指向个位, high=259, tmp=3, cur=3, low=0       ,cur=3 < 5, 故+ 259*10^(1-1) = 259
        //当i=2, 指向十位, high=25,  tmp=93, cur=9, low=3      ,cur=9 > 5, 故+ (25+1)*10^(2-1) = 260
        //当i=3, 指向百位, high=2,   tmp=593, cur=5, low=93    ,cur=5 = 5, 故+ 2*10^(3-1)+93+1 = 294
        //当i=4, 指向千位, high=0,   tmp=2593, cur=2, low=593  ,cur=2 < 5, 故+ 0*10^(4-1) = 0
        //计算完毕，结果total = 259 + 260 + 294 + 0 = 813
        if( cur == x){
            reulst = reulst + high * (int)pow(10, i-1) + low + 1;
        }
        else if(cur < x){
            reulst = reulst + high * (int)pow(10, i-1);
        }
        else{
            reulst = reulst + (high + 1) * (int)pow(10, i-1);
        }
        i++;
    }

    return reulst;
}

int P31_NumberOf1Between1AndN::test(){
    int result = NumberOf1Between1AndN_Solution(2593);
    cout << result << endl;
    return 0;
}
