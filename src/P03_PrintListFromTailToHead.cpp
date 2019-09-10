//
// Created by yongpu on 2019/9/10.
//
/*
 * 题目：从尾到头打印链表
 * 描述：将一个链表从尾到头的顺序存放到一个vector中
 * 思路：这个题比较简单，将链表进行遍历，依次放入vector中，然后再使用reverse函数即可，reverse时间复杂度为O(n)
 * 另外，通过反转链表实现的话得看面试官的要求，因为那样做的话修改了链表结构。
 */

#include "P03_PrintListFromTailToHead.h"

vector<int> P03_PrintListFromTailToHead::printListFromTailToHead(ListNode *head) {
    vector <int> ans;
    ListNode *tmp = head;
    while(tmp)
    {
        ans.push_back(tmp->val);
        tmp = tmp->next;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int P03_PrintListFromTailToHead::test() {
    ListNode *head = NULL;
    head = new ListNode(0);
    ListNode *pnode = head;
    int a[5] = {1,2,3,4,5};
    for(int i =0; i < 5; i++)
    {
        ListNode *tmp = new ListNode(a[i]);
        pnode->next = tmp;
        pnode = tmp;
    }
    ListNode *p = head;
    while(p){
        cout << p->val <<endl;
        p = p->next;
    }
    return 0;
}
