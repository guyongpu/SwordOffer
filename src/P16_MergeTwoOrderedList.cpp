//
// Created by yongpu on 2019/9/13.
//

#include "P16_MergeTwoOrderedList.h"

/*
 * 题目：合并两个排序的链表
 * 描述：将两个有序链表合并成一个有序链表
 * 输入：pHead1，链表1的头指针；pHead2，链表2的头指针
 * 输出：返回合并好的链表的指针
 * 思路：使用一个指针，先构建头结点，然后再逐个构建起一条链表，类似于新建链表的过程
 * 注意：本题不能用新建链表的方式完成，那样会失去题目的本意
 */

ListNode *P16_MergeTwoOrderedList::Merge(ListNode *pHead1, ListNode *pHead2) {
    if(pHead1 == nullptr) //链表1为空，返回链表2
        return pHead2;
    if(pHead2 == nullptr) //链表2为空，返回链表1
        return pHead1;

    ListNode* newhead = nullptr;//头指针
    ListNode* pnode = nullptr;

    //建立初始节点
    if(pHead1->val < pHead2->val)
    {
        pnode = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        pnode = pHead2;
        pHead2 = pHead2->next;
    }
    //头指针
    newhead = pnode;

    //遍历链表1和链表2，逐个节点建立新链表
    while(pHead1 || pHead2){
        if(pHead1 && pHead2)    //均不为空,比较大小
        {
            if(pHead1->val < pHead2->val)
            {
                pnode->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                pnode->next = pHead2;
                pHead2 = pHead2->next;
            }
            pnode = pnode->next;
        }
        else if(pHead1 == nullptr){ //链表1为空，则直接指向链表2，结束
            pnode->next = pHead2;
            break;
        }
        else{   //链表2为空，则直接指向链表1，结束
            pnode->next = pHead1;
            break;
        }

    }
    return newhead;
}

int P16_MergeTwoOrderedList::test() {
    int a[5] = {1,3,5,7,9};
    int b[5] = {2,4,6,8,10};

    //构建链表1
    ListNode* phead_a = nullptr;
    ListNode* pnode1 = new ListNode(a[0]);
    phead_a = pnode1;
    for(int i = 1; i < 5; i++)
    {
        ListNode* tmp = new ListNode(a[i]);
        pnode1->next = tmp;
        pnode1 = tmp;
    }

    //构建链表2
    ListNode* phead_b = nullptr;
    ListNode* pnode2 = new ListNode(b[0]);
    phead_b = pnode2;
    for(int i = 1; i < 5; i++)
    {
        ListNode* tmp = new ListNode(b[i]);
        pnode2->next = tmp;
        pnode2 = tmp;
    }

    //合并链表
    ListNode* newhead = Merge(phead_a, phead_b);

    //输出结果
    while(newhead){
        cout << newhead->val << " ";
        newhead = newhead->next;
    }
    cout << endl;
    return 0;
}
