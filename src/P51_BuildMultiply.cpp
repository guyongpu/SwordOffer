//
// Created by yongpu on 2019/9/26.
//

#include "P51_BuildMultiply.h"

/* 题目：构建乘积数组
 * 描述：给定数组A[0,1,...,n-1]，构建数组B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]，不使用除法
 * 输入：数组A
 * 输出：构建的数组B
 * 思路：直接计算时间复杂度为O(n^2)，考虑将B[i]=array1[i]*array2[i],其中array1[i]=A[0]*...*A[i-1];而array2[i] = A[i+1]*...*A[len-1]
 * 备注：如果可以使用除法，则B[i]=II(j=0->n-1)A[i] / A[i]，时间复杂度为O(n)
*/
vector<int> P51_BuildMultiply::multiply(const vector<int> &A) {
    int len = A.size();
    vector<int> array1(len, 1), array2(len, 1);
    for (int i = 0; i < len; i++) {
        //计算array1[i],即A[0]*...*A[i-1]
        for (int j = 0; j < i; j++) {
            array1[i] = array1[i] * A[j];
        }
        //计算array2[i],即A[i+1]*...*A[len-1]
        for (int k = i + 1; k < len; k++) {
            array2[i] = array2[i] * A[k];
        }
    }
    vector<int> arrayB;
    for (int i = 0; i < len; i++) {
        arrayB.push_back(array1[i] * array2[i]);
    }
    return arrayB;
}

int P51_BuildMultiply::test() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arrayB = multiply(A);
    for (int i = 0; i < arrayB.size(); i++) {
        cout << arrayB[i] << " " << endl;
    }
    return 0;
}
