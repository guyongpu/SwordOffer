//
// Created by yongpu on 2019/9/16.
//

#include "P35_InversePairs.h"

/*
 * 题目：数组中的逆序对
 * 描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
 */

int P35_InversePairs::InversePairs(vector<int> data) {
    int result = 0;
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = i+1; j < data.size(); j++)
        {
            if(data[i] > data[j])
                result ++;

        }
        result = result % 1000000007;
    }
    result = result % 1000000007;

    return result;
}

int P35_InversePairs::test() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    int result = InversePairs(data);
    cout << result << endl;
    return 0;
}
