//
// Created by yongpu on 2019/9/23.
//

#include "P36_FindFirstCommonNode.h"

/*
 * 题目：两个链表的第一个公共结点
 * 描述：输入两个链表，找出它们的第一个公共结点。
 * 输入：两个链表的头结点pHead1，pHead2
 * 输出：返回两个链表的公共结点
 * 思路：由于链表是单向，所以链表交点之后的结点都相同，则可以让长的先走x步，然后再一起走，直到最后相遇。
 * 或者通过将两个链表压入两个栈中，然后逐个出栈，开始时都相等，直到遇到第一个不相等的结点。
 */

int P36_FindFirstCommonNode::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);
    ListNode *p8 = new ListNode(8);

    ListNode* pHead1;
    ListNode* pHead2;
    //构建链表1: p1->p2->p3->p4->p5
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    pHead1 = p1;
    //构建链表2: p6->p7->p8->p3->p4->p5
    p6->next = p7;
    p7->next = p8;
    p8->next = p3;
    p3->next = p4;
    p4->next = p5;
    pHead2 = p6;

    //p3是公共结点
    ListNode* resNode = FindFirstCommonNode(pHead1, pHead2);
    cout << resNode->val << endl;
    return 0;
}

ListNode *P36_FindFirstCommonNode::FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    int len1 = GetLengthOfList(pHead1);
    int len2 = GetLengthOfList(pHead2);
    int length = min(len1, len2);

    ListNode *pNode1 = pHead1;
    ListNode *pNode2 = pHead2;
    if (len1 > len2) {    //链表1长
        int Step = len1 - length;
        while (Step--) {
            pNode1 = pNode1->next;
        }
    } else {               //链表2长
        int Step = len2 - length;
        while (Step--) {
            pNode2 = pNode2->next;
        }
    }
    //pNode1和pNode2为新的头
    ListNode* resNode = nullptr;
    while (pNode1 && pNode2) {
        if(pNode1 == pNode2){
            resNode = pNode1;
            break;
        }
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return resNode;
}

int P36_FindFirstCommonNode::GetLengthOfList(ListNode *pHead) {
    int length = 0;
    ListNode *pNode = pHead;
    while (pNode) {
        pNode = pNode->next;
        length++;
    }
    return length;
}