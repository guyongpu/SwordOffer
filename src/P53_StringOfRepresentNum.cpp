//
// Created by yongpu on 2019/9/26.
//

#include "P53_StringOfRepresentNum.h"

/*
 * 题目：表示数值的字符串
 * 描述：请实现一个函数用来判断字符串是否表示数值(包括整数和小数).
 * 输入：待判断的字符串
 * 输出：判断结果
 * 思路：直接判断，以E为界限，分为E的左边和E的右边，E的左边为正常数值，E的右边为整数。
 * 备注：仔细判断，也可考虑用正则表达式匹配.
 */

bool P53_StringOfRepresentNum::isNumeric(char *string) {
    if (strlen(string) == 0)
        return false;
    int index = 0;
    if (string[0] == '-' || string[0] == '+') {
        index++;
    }
    int len = strlen(string);

    //e和E计数
    int NumOfE = 0;
    int pos = 0;
    for (int i = index; i < len; i++) {
        if (string[i] == 'e' || string[i] == 'E') {
            pos = i;
            NumOfE++;
        }
    }
    if (NumOfE > 1)
        return false;

    //将数据分为E的左边和右边
    bool result = true;
    if (NumOfE == 1) {    //含有E
        //1.左边 [index, pos-1] , 整数部分只有一位
        //小数点位置和个数
        int NumOfPoint = 0;
        int PosOfPoint = 0;
        for (int i = index; i <= pos-1; i++) {
            if (string[i] == '.') {
                PosOfPoint = i;
                NumOfPoint++;
            }
        }
        if (NumOfPoint > 1) {
            result = false;
            return result;
        }
        if (NumOfPoint == 1) {  //有小数点
            //整数部分
            if (PosOfPoint - index < 1) {
                result = false;
                return result;
            }
            for(int i = index;i<PosOfPoint; i++){
                if( string[index] < '0' || string[index] > '9'){
                    result = false;
                    return result;
                }
            }
            //小数部分
            for (int i = PosOfPoint + 1; i < pos; i++)
            {
                if (string[i] < '0' || string[i] > '9') {
                    result = false;
                    return result;
                }
            }
        } else {                //无小数点
            //整数部分
            if ((pos - index != 1) || !('0' < string[index] && string[index] <= '9')) {
                result = false;
                return result;
            }
        }

        //2.右边 [pos+1, len-1] ,全部为整数
        int index_r = pos + 1;
        if (string[index_r] == '+' || string[index_r] == '-')
            index_r++;
        if (len - index_r < 1) {
            result = false;
            return result;
        }

        for (int i = index_r; i <= len - 1; i++) {
            if ((string[index_r] == '0' && index_r == pos + 1) || (string[index_r] < '0' || string[index_r] > '9')) {
                result = false;
                return result;
            }
        }

    } else { //不含有E
        //小数点个数
        int NumOfPoint = 0;
        for (int i = index; i < len; i++) {
            if (string[i] == '.') {
                NumOfPoint++;
            }
        }
        if (NumOfPoint > 1) {
            result = false;
            return result;
        }
        for (int i = index; i < len; i++) {
            if (('0' <= string[i] && string[i] <= '9') || (string[i] == '.'))
                continue;
            else {
                result = false;
                return result;
            }
        }
    }
    return result;
}

int P53_StringOfRepresentNum::test() {
    bool result;
    result = isNumeric("1.2.3");
    cout << result << endl;
    return 0;
}
