//
// Created by yongpu on 2019/9/28.
//

#include "P63_MidNumOfData.h"

/*
 * 题目：数据流中的中位数
 * 描述：输入一串数字流，得到其中的中位数.
 * 输入：insert的数字
 * 输出：中位数
 * 思路：采用最大最小堆做效率最高，插入复杂度O(logn),获取中位数O(1)
 * 备注：也可以采用插入排序思想，或者快排Partition，排序链表，ALV树
 */

void P63_MidNumOfData::Insert(int num) {
    int lenL = LeftVec.size();
    int lenR = RightVec.size();
    if ((lenL + lenR) % 2 == 0)    //奇数次插入到左边,LeftVec,大顶,less
    {
        if (lenR == 0) {
            LeftVec.push_back(num);
            make_heap(LeftVec.begin(), LeftVec.end(), less<int>());
        } else {
            int numR = RightVec[0];
            if (num <= numR) {
                LeftVec.push_back(num);
                make_heap(LeftVec.begin(), LeftVec.end(), less<int>());
            } else {
                LeftVec.push_back(numR);
                make_heap(LeftVec.begin(), LeftVec.end(), less<int>());

                pop_heap(RightVec.begin(), RightVec.end(), greater<int>());
                RightVec.pop_back();
                RightVec.push_back(num);
                make_heap(RightVec.begin(), RightVec.end(), greater<int>());
            }
        }

    } else {                          //偶数次插入到右边，RightVec,小顶,greater
        if (lenL == 0) {
            RightVec.push_back(num);
            make_heap(RightVec.begin(), RightVec.end(), greater<int>());
        } else {
            int numL = LeftVec[0];
            if (num >= numL) {
                RightVec.push_back(num);
                make_heap(RightVec.begin(), RightVec.end(), greater<int>());
            } else {
                RightVec.push_back(numL);
                make_heap(RightVec.begin(), RightVec.end(), greater<int>());

                pop_heap(LeftVec.begin(), LeftVec.end(), less<int>());
                LeftVec.pop_back();
                LeftVec.push_back(num);
                make_heap(LeftVec.begin(), LeftVec.end(), less<int>());
            }
        }
    }
}

double P63_MidNumOfData::GetMedian() {
    int lenL = LeftVec.size();
    int lenR = RightVec.size();
    double result = 0;
    if ((lenL + lenR) % 2 == 1) {//奇数个,则是 LeftVec[0]
        result = LeftVec[0];
    } else {//偶数个,则是 RightVec[0]
        result = (double)(RightVec[0] + LeftVec[0]) / 2;
    }
    return result;
}

int P63_MidNumOfData::test() {
    Insert(1);
    cout << GetMedian() << endl;
    Insert(2);
    cout << GetMedian() << endl;
    Insert(3);
    cout << GetMedian() << endl;
    Insert(4);
    cout << GetMedian() << endl;
    Insert(5);
    cout << GetMedian() << endl;
    return 0;
}
