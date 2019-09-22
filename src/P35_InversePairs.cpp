//
// Created by yongpu on 2019/9/16.
//

#include "P35_InversePairs.h"

/*
 * 题目：数组中的逆序对
 * 描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
 * 思路：归并排序的改进，把数据分成前后两个数组(递归分到每个数组仅有一个数据项)，合并数组，合并时，出现前面的数组值array[i]大于后面数组值array[j]时；
 * 则前面数组array[i]~array[mid]都是大于array[j]的，count += mid+1 - i。
 */

//标准解法，运用归并思想
int P35_InversePairs::InversePairs_1(vector<int> data) {
    int length = data.size();
    if(length <= 0)
        return 0;
    vector<int> copy(data);
    long long int result = InversePairsCore(data, copy, 0, length -1);
    result = result % 1000000007;
}

long long int P35_InversePairs::InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end){
    if(start == end)
    {
        copy[start] == data[start];
    }
    int length = (end - start)/2;
    long long int left = InversePairsCore(copy,data,start, start+length);
    long long int right = InversePairsCore(copy,data,start+length+1, end);

    int i = start + length;
    int j = end;
    long long int result =0;
    return result;

}


//常规解法，仅能通过50%，时间复杂度O(n^2)
int P35_InversePairs::InversePairs_2(vector<int> data) {
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
    int result = InversePairs_1(data);
    cout << result << endl;
    return 0;
}
