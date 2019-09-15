//
// Created by yongpu on 2019/9/15.
//

#include "P29_MinimumKNmber.h"

# include <functional>
/*
 * 题目：最小的K个数
 * 描述：输入n个整数，找出其中最小的K个数
 * 输入：input，待处理的整数；k，最小的K个数
 * 输出：result，找出的最小K个数
 * 思路：利用大顶堆做即可，思路比较简单，先构造一个K大小的大顶堆，然后逐个对根比较，
 * 如果input[i]比根小，则替换根，重新构建，主要涉及堆的make、pop、push和sort等操作，O(n*logK)。
 */

vector<int> P29_MinimumKNmber::GetLeastNumbers_Solution(vector<int> input, int k) {
    if(input.size() ==0 || input.size() < k || k == 0)
        return vector<int>();
    vector<int> result;
    result.assign(input.begin(),input.begin()+k); //[0,k-1]的元素
    make_heap(result.begin(), result.end(), less<int>());    //建大顶堆用less<int>(),降序；建小顶堆用greater<int>()，升序
//    cout <<"result " << result[0] << endl;
    for(int i = k; i < input.size(); i++)
    {
        if(input[i] < result[0])
        {
            //先到堆中pop，然后在vector中pop
            pop_heap(result.begin(), result.end(), less<int>());
            result.pop_back();
            //先在vector中push，再到堆中push
            result.push_back(input[i]);
            push_heap(result.begin(), result.end(), less<int>());
        }
    }
    //排序，小到大
    sort_heap(result.begin(), result.end()); //默认升序
    return result;
}

int P29_MinimumKNmber::test() {
    vector<int> input = {10,2,9,10,1,4,5,6,7,8,1};
    vector<int> result = GetLeastNumbers_Solution(input,11);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
