//
// Created by yongpu on 2019/9/24.
//

#include "P45_IsContinuous.h"

/*
 * 题目：扑克牌顺子
 * 描述：给5张牌，判断是否能组成顺子
 * 输入：牌的编号
 * 输出：判断的结果
 * 思路：1.排序；2.统计0的数量；3.遍历非0数字，判断0的数目是否够补位，如果不够输出false
 * 备注：思路较简单，要仔细。
 */

bool P45_IsContinuous::IsContinuous(vector<int> numbers) {
    if (numbers.size() < 5)
        return false;

    //排序
    sort(numbers.begin(), numbers.end());

    //统计0的数目
    int NumOfZero = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0)
            NumOfZero++;
    }

    //开始遍历
    int preNum = numbers[NumOfZero];
    for (int i = NumOfZero + 1; i < numbers.size(); i++) {
        if (preNum==numbers[i]){                        //存在对子
            return false;                               //返回false
        }
        else{
            if(numbers[i] - preNum == 1){               //正常情况下差1，继续遍历
                preNum = numbers[i];
            }
            else{                                       //需要使用0
                if(numbers[i]-preNum - 1 > NumOfZero)   //需要0的张数>现有0的数目，无法补位
                    return false;
                else{
                    NumOfZero = NumOfZero - (numbers[i]-preNum) + 1;    //剩余0的数目
                    preNum = numbers[i];                                //将preNum赋值为numbers[i]，继续循环
                }
            }
        }
    }
    return true;
}

int P45_IsContinuous::test() {
    vector<int> numbers = {0,3,2,6,4};
    bool result = IsContinuous(numbers);
    cout << result << endl;
    return 0;
}
