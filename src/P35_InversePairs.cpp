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
    if (length <= 0)
        return 0;
    vector<int> copy(data);
    long long int result = InversePairsCore(data, copy, 0, length - 1);
    result = result % 1000000007;
    return result;
}

long long int P35_InversePairs::InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end) {
    if (start == end)//如果指向相同位置，则说明没有逆序对
    {
        copy[start] == data[start];
        return 0;
    }

    int mid = start + (end - start) / 2;   // 求中点
    long long int left = InversePairsCore(copy, data, start, mid);          //[start, mid],使data左半段有序，并返回左半段逆序对的数目

    long long int right = InversePairsCore(copy, data, mid + 1, end); //[mid+1, end],使data右半段有序，并返回右半段逆序对的数目

    int i = mid;        //i初始化为前半段最后一个数字的下标
    int j = end;        //j初始化为后半段最后一个数字的下标
    int index = end;    //辅助数组复制的数组的最后一个数字的下标
    long long int result = 0;

    while (i >= start && j >= mid + 1)            //开始合并计数阶段
    {
        if (data[i] > data[j]) {                  //前半段的data[i]>data[j]
            result = result + j - (mid + 1) + 1;  //则从[mid+1 , j]都是逆序数
            copy[index] = data[i];
            index--;
            i--;
        } else {                        //后半段的data[j]>data[i]
            copy[index] = data[j];      //不需要计数，直接插入
            index--;
            j--;
        }
    }

    //只剩前半段
    while (i >= start) {
        copy[index] = data[i];
        index--;
        i--;
    }

    //只剩后半段
    while (j >= mid + 1) {
        copy[index] = data[j];
        index--;
        j--;
    }
    result = result + left + right;
    result = result % 1000000007;
    return result;
}


//常规解法，仅能通过50%，时间复杂度O(n^2)
int P35_InversePairs::InversePairs_2(vector<int> data) {
    int result = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] > data[j])
                result++;

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
