//
// Created by yongpu on 2019/9/27.
//

#include "P56_DeleteDuplication.h"

/*
 * 题目：删除链表中重复的结点
 * 描述：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针
 * 输入：链表头指针
 * 输出：处理后的链表头指针
 * 思路：1.处理头结点 2.处理其他结点。使用双指针做法,pPreNode 指向不重复的结点,检测pNode和pNode->next是否重复,如重复,找到 pNext,使 pPreNode指向pNext.
 * 备注：保留和不保留重复节点两个版本,考虑全/不/头/尾/部分重复，单/空链表.
 */


//不保留重复结点
ListNode *P56_DeleteDuplication::deleteDuplication(ListNode *pHead) {
    if (pHead == nullptr)
        return pHead;
    //第一阶段，处理头结点，保证新的头结点不重复
    ListNode *pPreNode = pHead;     //头结点
    ListNode *pNode = pHead->next;  //下一个结点
    while(1){
        if(pNode && pPreNode->val == pNode->val)//头结点相等
        {
            //找一个不相等的结点pNext
            ListNode *pNext = pNode->next;
            while(pNext){
                if(pNext->val != pNode->val){
                    break;          //找到符合要求的pNext
                }
                else                //继续找
                    pNext = pNext->next;
            }

            //将pNext作为头结点
            pHead = pNext;
            pPreNode = pHead;
            if(pHead)       //如果新头结点不为空，则继续判断新头结点是否重复
                pNode = pHead->next;
            else            //为空直接退出
                break;
        }
        else
            break;
    }
    if (pHead == nullptr)
        return pHead;
    //第二阶段，处理链表其他结点  pPreNode, pNode
    while (pNode) {
        if (pNode->next && pNode->val == pNode->next->val) {    //pNode和pNode之后的元素重复

            //找一个不相等的结点pNext
            ListNode *pNext = pNode->next;
            while(pNext){
                if(pNext->val != pNode->val){
                    break;
                }
                else
                    pNext = pNext->next;
            }
            //使pPreNode指向pNext
            pPreNode->next = pNext;
            pNode = pNext;          //将pNext赋值给pNode，继续循环
        }
        else{
            pPreNode = pNode;       //保证pPreNode是不重复结点
            pNode = pNode->next;
        }
    }
    return pHead;
}


//保留重复结点
ListNode *P56_DeleteDuplication::deleteDuplication_reserve(ListNode *pHead) {
    if (pHead == nullptr)
        return pHead;
    ListNode *pPreNode = pHead;
    ListNode *pNode = pHead->next;
    while (pNode) {
        if (pPreNode->val == pNode->val) {
            ListNode *pNext = pNode->next;
            pPreNode->next = pNext;

            pNode = pNode->next;
        } else {
            pPreNode = pPreNode->next;
            pNode = pNode->next;
        }
    }
    return pHead;
}

int P56_DeleteDuplication::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;

    ListNode *pHead = p1;

    ListNode *pNode = deleteDuplication(pHead);
    while (pNode) {
        cout << pNode->val << " " << endl;
        pNode = pNode->next;
    }

    return 0;
}
