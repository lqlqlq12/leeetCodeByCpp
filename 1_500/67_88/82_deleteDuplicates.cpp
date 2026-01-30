/* 82. 删除排序链表中的重复元素 II
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。 */

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
#include "Structure/ListNode_1.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode h, *p = &h, *q = &h;
        p->next = head;
        p = p->next;
        while (p && p->next)
        {
            if (p->val != p->next->val)
            {
                q->next = p;
                q = q->next;
                p = p->next;
            }
            else
            {
                int pre = p->val;
                while (p && p->val == pre)
                {
                    p = p->next;
                }
            }
        }
        q->next = p;
        return h.next;
    }
};