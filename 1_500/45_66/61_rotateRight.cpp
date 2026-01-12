/* 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 */
#include <Structure/ListNode_1.h>
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *h = new ListNode(), *p = h, *q = h;
        int count = 0;
        h->next = head;
        for (count = 0; count < k && p->next; count++)
        {
            p = p->next;
        }
        if (!p->next && count != 0)
        {
            k %= count;
            p = h;
            for (count = 0; count < k && p->next; count++)
            {
                p = p->next;
            }
        }
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        if (q->next)
        {
            p->next = h->next;
            h->next = q->next;
            q->next = 0;
        }
        return h->next;
    }
};