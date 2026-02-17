/* 92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。 */

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
#include <ListNode_1.h>

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode *h = new ListNode(), *p, *q, *r = h;
        h->next = head;
        int index = 0;
        while (index < left)
        {
            index++;
            if (index == left)
            {
                q = r;
                p = r->next;
            }
            r = r->next;
        }
        while (index < right)
        {
            r = r->next;
            ListNode *t = r->next;
            r->next = q->next;
            q->next = r;
            p->next = t;
            r = p;
            index++;
        }
        return h->next;
    }
};
