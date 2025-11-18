/* 21. 合并两个有序链表

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  */

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

#include <Structure/ListNode_1.h>
using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(), *p = head;
        while (list1 || list2)
        {
            int val1 = list1 ? list1->val : 101;
            int val2 = list2 ? list2->val : 101;
            if (val1 < val2)
            {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        return head->next;
    }
};