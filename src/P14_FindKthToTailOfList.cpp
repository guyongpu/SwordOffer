//
// Created by yongpu on 2019/9/13.
//

#include "P14_FindKthToTailOfList.h"

/*
 * 题目：链表中倒数第k个结点
 * 描述：输出一个链表中倒数第k个结点
 * 输入：pListHead，链表的头指针；k，倒数第k个
 * 输出：返回倒数第k个元素的指针
 * 思路：利用双指针思想，指针1先走k步，之后指针2与指针1同步移动，直到链表结尾。
 * 注意：本题实际上只需要考虑等于0，因为unsigned int是正数，但是如果是int则要考虑小于0
 * 测试要考虑0，空链表，倒数第x个，倒数第1个，倒数第length个等情况
 */

ListNode *P14_FindKthToTailOfList::FindKthToTail(ListNode *pListHead, unsigned int k) {
    ListNode* pos_front = pListHead;
    ListNode* pos_behind = pListHead;
    int cnt = 0;
    if(pListHead == nullptr || k <= 0)//实际上只需要考虑等于0，因为unsigned int是正数，但是如果是int则要考虑小于0
        return nullptr;
    //使pos_behind指向第k个元素
    while(cnt < k-1){
        cnt++;
        pos_behind = pos_behind->next;
        if(pos_behind == nullptr)//如果为空，则说明链表长度不够，直接返回nullptr
        {
            return nullptr;
        }
    }

    //cout << pos_behind->val << endl;
    //pos_front和pos_behind同步向后移动，直到链表结束
    while(pos_behind->next){
        pos_behind = pos_behind->next;
        pos_front = pos_front->next;
    }
    //cout << pos_front->val << endl;
    return pos_front;
}

int P14_FindKthToTailOfList::test() {
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    ListNode* phead = nullptr;
    ListNode* pnode = new ListNode(a[0]);
    phead = pnode;
    int cnt = 8;
    for(int i = 1; i < 10; i++)
    {
        ListNode* tmp = new ListNode(a[i]);
        pnode->next = tmp;
        pnode = tmp;
    }
    pnode = phead;
    while(pnode){
        //cout << pnode->val << endl;
        pnode = pnode->next;
    }
    FindKthToTail(phead,0); //倒数0个，返回nullptr
    FindKthToTail(phead,5); //正常情况
    FindKthToTail(phead,1); //返回最后一个元素
    FindKthToTail(nullptr,5); //空链表，返回nullptr
    FindKthToTail(phead,10); //返回第一个元素
    FindKthToTail(phead,11); //超过总长度，返回nullptr
    return 0;
}
