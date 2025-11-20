/* 25. K 个一组翻转链表

给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 */

#include "Structure/ListNode_1.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *h = new ListNode(), *p = h, *q = head, *r, *t = 0;
        h->next = head;
        int index = 0;
        while (q)
        {
            ListNode *after = q->next;
            q->next = t;
            t = q;
            if (index == 0)
            {
                r = q;
            }
            index++;
            if (index % k == 0)
            {
                p->next = q;
                r->next = after;
                t = 0;
                p = r;
                index = 0;
            }
            q = after;
        }
        if (index > 0)
        {
            while (t)
            {
                ListNode *after = t->next;
                t->next = q;
                q = t;
                t = after;
            }
        }
        return h->next;
    }
};