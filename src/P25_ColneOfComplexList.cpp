//
// Created by yongpu on 2019/9/14.
//

#include "P25_ColneOfComplexList.h"

/*
 * 题目：复杂链表的复制
 * 描述：输入一个复杂链表，返回结果为复制后复杂链表的head
 * 输入：pHead，待复制链表的头节点
 * 输出：newHead，复制后新链表的头节点
 * 思路：最简单的做法是先复制，再依次将节点查找后设置random指针。
 * 本题分为3步。1.复制节点，并插入到原链表中；2.设置random指针的值；3.拆分原链表和新链表。
 */

RandomListNode *P25_ColneOfComplexList::Clone(RandomListNode *pHead) {
    if(pHead == nullptr)
        return nullptr;
    RandomListNode *pNode = nullptr;
    //第一步，复制插入链表节点
    pNode = pHead;
    while(pNode)
    {
        //原始链表: A->B->C->D
        //复制后：  A->A'->B->B'->C->C'->D->D'
        //在A->B之间插入节点A’，过程如下：
        int ori_lab = pNode->label;             //原节点值A
        RandomListNode* ori_next = pNode->next; //原节点next指针，指向B
        RandomListNode* newNode = new RandomListNode(ori_lab);  //建立新节点A'
        pNode->next = newNode;      //原节点指向新节点，A->A'
        newNode->next = ori_next;   //新节点指向原节点指向的节点,A'->B

        pNode = ori_next; //处理下一个节点
    }
    //第二步，设置随机指针的值
    pNode = pHead;
    while(pNode)
    {
        //当前链表结构为：A->A'->B->B'->C->C'->D->D'
        RandomListNode* ori_random = pNode->random; //原节点A随机指向的节点X
        if(ori_random != nullptr)
        {
            RandomListNode* newNode = pNode->next;      //A的新节点A'
            newNode->random = ori_random->next;         //A'应指向X'，而X'在ori_random的下一个节点，即ori_random->next
        }
        pNode = pNode->next->next;                      //则pNode下一步处理B,需要跳过A'，故pNode = pNode->next->next
    }

    //第三步，拆开链表，原则上不能破坏之前的链表
    pNode = pHead;

    //建立初始节点
    RandomListNode* newHead= nullptr;
    RandomListNode* newpNode = pNode->next;
    newHead = newpNode;

    //建立之后的节点
    while(newpNode->next)
    {
        //还原旧链表
        pNode->next = pNode->next->next;
        pNode = pNode->next;

        //构造新链表
        newpNode->next = pNode->next;
        newpNode = newpNode->next;
    }
    pNode->next = nullptr;
    return newHead;
}

int P25_ColneOfComplexList::test() {

    RandomListNode *p1,*p2,*p3,*p4,*p5;
    p1 = new RandomListNode(1);
    p2 = new RandomListNode(2);
    p3 = new RandomListNode(3);
    p4 = new RandomListNode(4);
    p5 = new RandomListNode(5);

    p1->next = p2;
    p1->random = p3;

    p2->next = p3;
    p2->random = p5;

    p3->next = p4;

    p4->next = p5;
    p4->random = p2;


    RandomListNode* head = p1;
    RandomListNode* newHead = Clone(head);
    RandomListNode* pNode = nullptr;

    cout << "oldList:";
    pNode = head;
    while(pNode){
        cout << pNode->label << " ";
        pNode = pNode->next;
    }
    cout << endl;

    cout << "newList:";
    pNode = newHead;
    while(pNode){
        cout << pNode->label << " ";
        pNode = pNode->next;
    }

    return 0;
}
