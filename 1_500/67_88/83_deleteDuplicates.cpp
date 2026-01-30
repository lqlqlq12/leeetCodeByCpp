/* 83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。 */

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

#include "ListNode_1.h"
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) return head;
        ListNode h, *p = &h, *q = &h;
        p->next = head;
        p = p->next->next;
        while (p)
        {
            if (q->next->val != p->val)
            {
                q = q->next;
                q->next = p;
            }
            p = p->next;
        }
        q = q->next;
        q->next = p;
        return head;
    }
};