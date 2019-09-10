# 仓库说明
## 内容描述
本仓库为牛客网剑指offer题目的刷题记录，网址为：https://www.nowcoder.com/ta/coding-interviews ，[点击跳转到剑指offer](https://www.nowcoder.com/ta/coding-interviews)
每个题的代码放在src中，在main.cpp引入对应类的头文件，然后运行测试函数即可，例如需要运行题1时，对main.cpp写成如下形式即可:
~~~ c++
#include <iostream>
#include "src/P01_2d_array_find.h"

using namespace std;

int main() {
    P01_2d_array_find G;
    G.test();
    return 0;
}
~~~
然后点击运行即可。

## 刷题日志
|题号|题目名|完成日期|描述|备注|
:-:|:-:|:-:|:-|:-:
|P01|二维数组的查找|2019.9.10|问题：在一个递增的二维数组中查找一个数是否存在。<br>思路：从左上角或者右上角开始查找|思考递减数组|
|P02|替换空格|2019.9.10|问题：将空格替换为%20。<br>思路：从后往前替换，避免移动，时间复杂度O(n)|小换大，从后往前<br>大换小，从前往后|
|P03|从尾到头打印链表|2019.9.10|问题：将链表从尾到头存放到vector中<br>思路：顺序遍历，然后对vector进行反转|不建议反转链表，会改变链表结构|
