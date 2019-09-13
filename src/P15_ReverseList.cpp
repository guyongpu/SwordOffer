//
// Created by yongpu on 2019/9/13.
//

#include "P15_ReverseList.h"

/*
 * 题目：反转链表
 * 描述：将链表进行反转后，然后输出新链表的表头
 * 输入：pHead，原链表头
 * 输出：返回新链表头
 * 思路：使用三个指针，分别指向前，中，后三个位置，中表示正在处理的节点
 */

ListNode *P15_ReverseList::ReverseList(ListNode *pHead) {
    if(pHead == nullptr || pHead->next == nullptr) //空指针或者只有一个元素，则直接返回原头指针
        return pHead;
    ListNode* newhead = nullptr;

    ListNode* node_front = nullptr;         //前指针
    ListNode* node_midle = pHead;           //中指针，正在处理的节点
    ListNode* node_behind = pHead->next;    //后指针

    while(node_midle){
        node_midle->next = node_front;
        node_front = node_midle;
        node_midle = node_behind;
        if(node_behind)//node_behind如果是空指针，则结束
            node_behind = node_behind->next;
        else
            break;
    }
    newhead = node_front;
    return newhead;
}

int P15_ReverseList::test(){
    int a[5] = {1,2,3,4,5};
    ListNode* phead = nullptr;
    ListNode* pnode = new ListNode(a[0]);
    phead = pnode;
    for(int i = 1; i < 5; i++)
    {
        ListNode* tmp = new ListNode(a[i]);
        pnode->next = tmp;
        pnode = tmp;
    }
    pnode = phead;
    while(pnode)
    {
        cout << pnode->val << " ";
        pnode = pnode->next;
    }
    cout << endl;

    phead->next->next->next = nullptr;//测试3个元素
    pnode = ReverseList(phead);
    while(pnode)
    {
        cout << pnode->val << " ";
        pnode = pnode->next;
    }
    cout << endl;
    return 0;
}