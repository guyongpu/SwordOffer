//
// Created by yongpu on 2019/9/10.
//
/*
 * 题目：替换空格
 *
 * 描述：给一个字符串str和可容纳的字符数length，将str中的空格替换为%20,
 *
 * 思路：在面试中，首先得确认需要在原字符串上操作还是构建新的字符串，假设是在原字符串上操作。
 * 如果采用传统从前往后遍历的方式，则时间复杂度O(n^2),时间复杂度太大，效率很低。
 * 这里采用从后往前的方式，首先确认空格的个数，通过oldLength+2*NumSpaces即可得到新字符串的长度。
 * 然后采用双指针的方式，从后往前遍历，p1指向原字符串尾，p2指向新字符串尾。
 * p1逐渐往前移，每移一位，如果不是空格，则p1位置的字符复制给p2，如果是，则p2赋值为%20，并前移3位，NumSpaces减一
 * 当NumSpaces等于0时，说明p1和p2相等，前面已经没有空格了，这时候可以结束遍历，得到的str即为所求结果。
 *
 * 思考：本题的本质是小字符串替换为大字符串，新指针永远在旧指针后面，当相等的时候说明替换结束，已得出结果。
 * 相反，考虑大字符串替换为小字符串的情况，则不能从后向前，因为新指针在旧指针前面，会导致原字符串还未赋值就已被覆盖，因此必须从前往后。
 * 总结下：
 * （1）小替换大，则从后向前，时间复杂度为O(n)；
 * （2）大替换小，则从前向后，时间复杂度为O(n)。
 */
#include "P02_Replace_spaces.h"

int P02_Replace_spaces::test() {
    char s[] = "We Are Happy.";
    replaceSpace(s , 100);
    cout << s<< endl;
    return 0;
}

void P02_Replace_spaces::replaceSpace(char *str, int length) {
    if(str == nullptr || length <= 0)
        return ;
    int oldLength = 0;
    int num_space = 0;
    for( int i = 0; str[i] != '\0' ; i++)
    {
        oldLength ++;
        if(str[i] == ' ')
            num_space ++;
    }
    int newLength = oldLength + num_space * 2;
    if(newLength > length)
        return ;
    int p1 , p2;
    p2 = newLength;
    for(p1 = oldLength; p1 >= 0 && num_space > 0; p1--)
    {
        if(str[p1] != ' ')
        {
            str[p2--] = str[p1];
        }
        else
        {
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
            num_space --;
        }
    }
}
