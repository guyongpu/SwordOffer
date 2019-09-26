//
// Created by yongpu on 2019/9/26.
//

#include "P55_EntryNodeOfLoop.h"

/*
 * 题目：链表中环的入口结点
 * 描述：给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null.
 * 输入：链表头结点
 * 输出：环的入口结点
 * 思路：第1步，判断链表是否成环，快慢指针相遇；第2步，pFast先走step步，然后再一起走，首次相遇就是入口.
 * 备注：使用链表注意细节
 */

ListNode *P55_EntryNodeOfLoop::EntryNodeOfLoop(ListNode *pHead) {
    if (pHead == nullptr)    //空链表或只有一个结点
        return nullptr;

    //1.判断是否成环
    ListNode *pFast = pHead;
    ListNode *pSlow = pHead;
    int step = 0;
    while (1) {
        step++;
        if (pFast->next == nullptr || pFast->next->next == nullptr)
            return nullptr;
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pFast == pSlow) {
            break;
        }
    }
    //cout << "loop " << step << endl;

    //2.找入口
    pFast = pHead;
    pSlow = pHead;
    for (int i = 0; i < step; i++) {
        pFast = pFast->next;
    }
    ListNode *MeetNode = nullptr;
    while (1) {
        if (pFast == pSlow) {
            MeetNode = pFast;
            break;
        } else {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
    }
    return MeetNode;
}

int P55_EntryNodeOfLoop::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p2;

    ListNode *pHead = p1;

    ListNode *MeetNode = EntryNodeOfLoop(pHead);
    cout << MeetNode->val << endl;
    return 0;
}
