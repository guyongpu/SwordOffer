//
// Created by yongpu on 2019/9/23.
//

#include "P37_GetNumberOfK.h"

/*
 * 题目：数字在排序数组中出现的次数
 * 描述：统计一个数字在排序数组中出现的次数。
 * 输入：一个数组data和待查找的数字K
 * 输出：数字K出现的次数
 * 思路：用2次二分查找，第一次查找K的位置，第二次使用二分查找确定K的起点和终点。
 * 或者，在确定好K的位置后，用双指针前后移动，统计数目。
 * 备注：判断data是否为空要写在最前面，不然会出错。另外，要考虑降序时反转。
 */

int P37_GetNumberOfK::GetNumberOfK(vector<int> data, int k) {   //假设是升序
    int len = data.size();
//    if (k < data[0] || data[len - 1] < k || len <= 0) //这样写在data为空的时候会越界，需要将len <= 0写在前面或者单独写
    if (len <= 0 || k < data[0] || data[len - 1] < k)
        return 0;
    if (data[0] > data[len - 1])    //如果是降序，则反转
        reverse(data.begin(), data.end());

    int pos_begin = 0;              //K的起始坐标
    int pos_end = 0;                //K的结尾坐标
    int result = 0;                 //结果

    //开始进行二分查找
    int low = 0;
    int high = len - 1;
    int mid = (low + high) / 2;
    while (low <= high) {
        if (data[mid] < k) {
            low = mid + 1;
        } else if (data[mid] > k) {
            high = mid - 1;
        } else {                    //查找到K，则开始确定K的坐标，进行第二次二分查找
            //1.二分查找——头位置
            pos_begin = mid;        //K的起始坐标
            int high_begin = mid - 1;
            int low_begin = low;
            int mid_begin = (low_begin + high_begin) / 2;
            while ((data[high_begin] == k) && low_begin <= high_begin) {    //当data[high_begin]不等于k时，结束
                if (data[mid_begin] < k) {
                    low_begin = mid_begin + 1;                      //low_begin往后移,K的起点在[mid_begin+1, high_begin]之间
                } else {
                    high_begin = mid_begin - 1;
                    pos_begin = mid_begin;
                }
                mid_begin = (low_begin + high_begin) / 2;
            }

            //2.二分查找——尾位置
            pos_end = mid;          //K的结尾坐标
            int high_end = high;
            int low_end = mid + 1;
            int mid_end = (low_end + high_end) / 2;
            while ((data[low_end] == k) && low_end <= high_end) {   //当data[low_end]不等于k时，结束
                if (data[mid_end] > k) {
                    high_end = mid_end - 1;                         //high_end往前移，K的终点在[low_end, mid_end-1]之间
                } else {
                    low_end = mid_end + 1;
                    pos_end = mid_end;
                }
                mid_end = (low_end + high_end) / 2;
            }
            result = pos_end - pos_begin + 1;                       //计算结果
            break;                                                  //退出循环，计算完成
        }
        mid = (low + high) / 2;
    }
    return result;
}

int P37_GetNumberOfK::test() {
    vector<int> array = {1, 2, 3, 5, 5, 5, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9, 9, 10};
    int k = 11;
    int result;
    result = GetNumberOfK(array, 8);
    cout << result << endl;
    return 0;
}
