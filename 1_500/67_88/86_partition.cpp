/* 86. 分隔链表
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。 */
#include <ListNode_1.h>
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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *small = new ListNode(), *big = new ListNode(), *p = small, *q = big, *h = new ListNode();
        h->next = head;
        while (h->next)
        {
            if (h->next->val < x)
            {
                p->next = h->next;
                p = p->next;
            }
            else
            {
                q->next = h->next;
                q = q->next;
            }
            h = h->next;
        }
        p->next = big->next;
        q->next = 0;
        return small->next;
    }
};