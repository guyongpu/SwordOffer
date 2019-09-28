//
// Created by yongpu on 2019/9/28.
//

#include "P64_MaxInWindows.h"

/*
 * 题目：滑动窗口的最大值
 * 描述：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值.
 * 输入：待处理数组、滑动窗口大小
 * 输出：所有滑动窗口里数值的最大值
 * 思路：采用双端队列来做，队首始终是当前窗口的最大值.
 * 备注：学习该方法
 */

vector<int> P64_MaxInWindows::maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> MaxInWindows;
    if (size <= 0 || num.size() == 0)
        return MaxInWindows;
    int begin = 0;
    deque<int> index;
    for (int i = 0; i < num.size(); i++) {
        begin = i -size+1;
        if(index.empty()){
            index.push_back(i); //队列为空，直接放入元素
        }
        else if(begin > index.front()){     //最小下标 > 队首下标，则说明当前最大元素过期，弹出
            index.pop_front();  //弹出队首元素
        }

        while((index.empty() == false) && num[index.back()] <= num[i]){
            index.pop_back();   //弹出队尾元素
        }
        index.push_back(i);
        if(begin >= 0){
            int pos = index.front();
            MaxInWindows.push_back(num[pos]);
        }
    }
    return MaxInWindows;
}

int P64_MaxInWindows::test() {
    vector <int> num = {2,3,4,2,1,0,6,2,5,1};
    vector<int> result = maxInWindows(num,3);
    for(int i =0 ;i< result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
