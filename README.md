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
|<center>题号</center>|<center>题目名</center>|<center>完成日期</center>|<center>描述</center>|<center>备注</center>|
:-:|:-:|:-:|:-|:-
|P01|二维数组的查找|2019.9.10|问题：在一个递增的二维数组中查找一个数是否存在。<br>思路：从左上角或者右上角开始查找|思考递减数组|
|P02|替换空格|2019.9.10|问题：将空格替换为%20。<br>思路：从后往前替换，避免移动，时间复杂度O(n)|小换大，从后往前<br>大换小，从前往后|
|P03|从尾到头打印链表|2019.9.10|问题：将链表从尾到头存放到vector中<br>思路：顺序遍历，然后对vector进行反转|不建议反转链表，会改变链表结构|
|P04|重建二叉树|2019.9.10|问题：根据前序和中序递归构建二叉树<br>思路：递归构建二叉树|复习时要回顾这个题
|P05|用两个栈实现队列|2019.9.11|问题：用两个栈实现队列的push和pop操作<br>思路：push时，直接存入stack1；pop时，若stack2不为空，则直接弹出栈顶元素，否则，将stack1放入stack2，再弹出栈顶元素。|无
|P06|旋转数组的最小数字|2019.9.11|问题：数组旋转一次后，找出数组的最小值<br>思路：用双指针的二分查找方法|不要顺序遍历|
|P07|斐波那契数列|2019.9.11|问题：输出斐波那契数列的第n项<br>思路：递归计算时间空间复杂度过大，用非递归做，F(n)=F(n-1)+F(n-2)|用非递归方法|
|P08|跳台阶|2019.9.11|问题：计算跳上number级台阶的跳法数量<br>思路：递归计算时间空间复杂度过大，用非递归做，F(n)=F(n-1)+F(n-2)|用非递归方法|
|P09|变态跳台阶|2019.9.11|问题：计算跳上number级台阶的跳法数量，每次可以选择跳1-n级<br>思路：利用数学归纳法推导，F(n)=2*F(n-1)|用非递归方法|
|P10|矩形覆盖|2019.9.11|问题：用2\*1的矩形去覆盖2\*number的大矩形，计算覆盖的方法数<br>思路：这个题也是斐波拉契数列，F(n)=F(n-1)+F(n-2)|用非递归方法|
|P11|二进制中1的个数|2019.9.11|问题：给定一个整数，计算其二进制中1的个数<br>思路：介绍了3种方法，关键是第2和第3种。方法1,采用每次右移n，提前处理负数；方法2采用每次将flag左移；方法3采用n=n&(n-1)的方式计算|掌握3种方法
|P12|数值的整数次方|2019.9.12|问题：不用库函数，计算base的exponent次方<br>思路：考虑两个点，一是int的绝对值算法，考虑边界值,使用unsigned int处理；二是0的处理，返回0|绝对值的处理|
|P13|调整数组顺序使奇数位于偶数前面|2019.9.12|问题：将一个数组的奇数放在前面，偶数放在后面，奇数之间、偶数之间的相对位置不变<br>思路：可以采用双指针平移的做法，排序的做法，用两个vector组合做法都可以|如果只要求奇数前，偶数后，则用双指针做法|
|P14|链表中倒数第k个结点|2019.9.13|问题：输出该链表中倒数第k个结点<br>思路：利用双指针思想，指针1先走k步，之后指针2与指针1同步移动，直到链表结尾|考虑0，空链表，倒数第x个，倒数第1个，倒数第length个等情况|
|P15|反转链表|2019.9.13|描述：将链表进行反转后，然后输出新链表的表头<br>思路：使用三个指针，分别指向前，中，后三个位置，中表示正在处理的节点|常见题，注意复习|
|P16|合并两个排序的链表|2019.9.13|描述：将两个有序链表合并成一个有序链表<br>思路：使用一个指针，先构建头结点，然后再逐个构建起一条链表，类似于新建链表的过程|常见题，注意多复习<br>用非递归实现的，而书上使用递归，但本质是一样的|
|P17|树的子结构|2019.9.13|描述：第一步，先在树A中找到一个和树B根节点的值相等的节点R；第二步，判断树A中以R为根节点的子树是不是包含树B一样的结构。 HasSubtree，找到一个相等的节点；DoesTree1HaveTree2，开始计算两个树是否包含。|常见题，注意复习|
|P18|镜像二叉树|2019.9.13|描述：给定一个的二叉树，将其变换为原二叉树的镜像<br>思路：将树的左右子树进行交换，然后再分别对左右子树进行镜像处理。|常见题，注意复习|
|P19|顺时针打印矩阵|2019.9.13|描述：将一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字<br>思路：第一步：先打印整圈的，圈数是行列的最小值minNum/2；第二步，如果minNum是奇数，说明有单独的行/列，当行>列，则有列，从上到下打印，当列>=行，则有行，从左到右打印。|1.圈数是行列的最小值minNum/2；<br>2.minNum是奇数则打印单独行/列。|
|P20|包含min函数的栈|2019.9.14|描述：实现一个能够得到栈中所含最小元素的min函数<br>思路：本题目需要使用两个栈，数据栈和辅助栈。辅助栈只在压栈元素比栈顶元素小或等于才入栈，出栈则与辅助栈顶元素相等才出栈|入栈时与辅助栈栈顶相等也要入栈|
|P21|栈的压入、弹出序列|2019.9.14|描述：判断一个序列是否可能为一个栈的弹出顺序<br>思路：遍历pushV[i]，如果遇到popV[cnt]相等，先压栈，然后popV[cnt]与栈中逐个比较，否则直接将pushV[i]压入栈中当cnt与popV的size相等时，则说明匹配成功，否则匹配失败。|比较阶段，结束判断条件|
|P22|从上往下打印二叉树|2019.9.14|描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。<br>思路：本题书上的方法是采用先进先出队列，每遍历一个节点，则把该节点的左右节点放到队尾，知道队为空，则结束。本人做法原理是一样的，只是用的vector实现，vectree存放本轮遍历的节点，一轮完成后，清空vectree，再把其子节点加入到vectree中，然后进行下一轮遍历，直到vectree的size为0，则说明所有节点已遍历。|二叉树的层序遍历，用队列更好|
|P23|二叉搜索树的后序遍历序列|2019.9.14|描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。<br>思路：后序遍历的最后一个元素是根，则序列必须可以分为左右两部分，左部分<root，右部分>root，不满足则返回false，满足则继续进行递归。递归结束条件：每一个sequence只有一个元素，则返回true.|常见题，注意多复习<br>输入空树返回false.|
|P24|二叉树中和为某一值的路径|2019.9.14|描述：打印出二叉树中结点值的和为输入整数的所有路径，终点为叶子节点，按长度降序<br>思路：按左右子树进行递归，当和相等且为叶子节点，则说明找到一条路径Path，然后将Path存入result中，如果不符合要求，则先将当前节点加入Path中，然后分别对左、右子树递归。|题目不难，但要复习|
|P25|复杂链表的复制|2019.9.14|描述：输入一个复杂链表，返回结果为复制后复杂链表的head<br>思路：本题分为3步。1.复制节点，并插入到原链表中，如A->A'->B->B'->C->C'；2.设置random指针的值；3.拆分原链表和新链表。|思路比较巧妙,注意不能破坏旧链表结构|
|P26|二叉搜索树与双向链表|2019.9.14|描述：将二叉搜索树转换成一个排序的双向链表<br>思路：二叉搜索树进行中序遍历恰好是排序的结果，借用一个指向当前链表最后一个节点的指针来构建链表|中序遍历思想，第一次不会做，要复习|
|P27|字符串排列|2019.9.15|描述：输入一个字符串,按字典序打印出该字符串中字符的所有排列。<br>思路：将字符串分为两部分，第一个字符、其后面的所有字符。然后用第一个字符和后面的所有字符逐个交换。|注意复习|
|P28|数组中出现次数超过一半的数字|2019.9.15|描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字，不存在则输出0.<br>思路：采用阵地攻守的思想。第一个数字作为第一个士兵，守阵地；count = 1；遇到相同元素，count++; 遇到不相同元素，即为敌人，同归于尽,count--；当遇到count为0的情况，又以新的i值作为守阵地的士兵，遍历到最后还留在阵地上的士兵，有可能是主元素。再加一次循环，记录这个士兵的个数看是否大于数组一半即可。|常见题，要复习|
|P29|最小的K个数|2019.9.15|描述：输入n个整数，找出其中最小的K个数<br>思路：利用大顶堆做即可，思路比较简单，先构造一个K大小的大顶堆，然后逐个对根比较，如果input[i]比根小，则替换根，重新构建，主要涉及堆的make、pop、push和sort等操作，O(n*logK)|常见题，要复习|
|P30|连续子数组的最大和|2019.9.16|描述：计算一个数组的最大连续子序列的和<br>思路：常规解法，逐个累加，当tmp_sum<0，则替换掉，每次与sum比较大小|常规解法<br>动态规划|
|P31|整数中1出现的次数|2019.9.16|描述：从1到整数N中1出现的次数<br>思路：逐位思考，可以计算1~9出现的次数，修改x即可，0除外|注意复习|
|P32|把数组排成最小的数|2019.9.16|描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个最小的数<br>思路：主要运用到一个字符串排序，当str_ab< str_ba时，a在前，否则b在前|注意复习|
|P33|丑数|2019.9.16|描述：把只包含质因子2、3和5的数称作丑数，找第N个丑数。<br>思路：维护三个指针，每次找三个指针对应的乘积的最小值加入队列，同时进行移动指针。|常规解法和优化解法|
|P34<br>书T50|第一个只出现一次的字符|2016.9.16|描述：在一个字符串中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回-1<br>思路：可以采用构造hash表的思想，即构造pos[52]，int cnt[52]，遍历两次即可求解。也可以采用map思想，直接strmap<char,int>，做法也比较简单|hash表<br>map方法|
