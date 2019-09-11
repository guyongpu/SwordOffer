//
// Created by yongpu on 2019/9/11.
//

#include "P06_Min_of_Rotate_arrays.h"

/*
 * 题目：旋转数组的最小数字
 * 描述：在一个经过一次旋转的数组中，找到数组的最小数字
 * 输入：经过一次旋转后的数组
 * 返回：返回数组中的最小数字
 * 思路：不能用直接遍历的方法，要抓住旋转一次这个条件
 * 采用双指针二分的方式，使用indexMid进行计算，保持index1指向前数组，index2指向后数组。
 */

int P06_Min_of_Rotate_arrays::minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty())
        return 0;
    if(rotateArray.size()==1)
        return rotateArray[0];
    int index1, index2, indexMid;
    index1 = 0;
    index2 = rotateArray.size()-1;
    indexMid = 0;
    while(rotateArray[index1] >= rotateArray[index2])
    {
        if(index1 == index2 - 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2)/2;

        //当index1，indexMid，index2均相等时，无法判断indexMid位于前数组还是后数组，只能通过遍历index1和index2的数据
        if(rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[indexMid])
        {
            //最小值元素下标
            indexMid = min_element(rotateArray.begin()+index1, rotateArray.begin()+index2) - rotateArray.begin();
            break;
        }
        //当indexMid > index2指向的数据，则说明indexMid在前数组中
        if(rotateArray[indexMid] > rotateArray[index2])
        {
            index1 = indexMid;
        }
        else if(rotateArray[indexMid] <= rotateArray[index2])//当indexMid <= index2指向的数据，则说明indexMid在后数组中
        {
            index2 = indexMid;
        }
    }

    return rotateArray[indexMid];
}

int P06_Min_of_Rotate_arrays::test() {
    vector <int> aa1 = {3,4,5,1,2};
    cout << minNumberInRotateArray(aa1) << endl;
    vector <int> aa2 = {1,1,1,1,0,1};
    cout << minNumberInRotateArray(aa2) << endl;
    return 0;
}
