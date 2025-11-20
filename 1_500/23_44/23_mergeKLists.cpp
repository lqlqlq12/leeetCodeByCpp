/* 23. 合并 K 个升序链表

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。 */

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
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int val;
        ListNode *p;
        bool operator<(const Node &another) const
        {
            return val > another.val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(), *p = head;
        int len = lists.size();
        if (len == 0)
        {
            return head->next;
        }
        priority_queue<Node> queue;

        for (int i = 0; i < len; i++)
        {
            if (lists[i])
            {
                queue.push(Node(lists[i]->val, lists[i]));
            }
        }
        while (!queue.empty())
        {
            Node node = queue.top();
            queue.pop();
            p->next = node.p;
            if (node.p->next)
            {
                queue.push(Node(node.p->next->val, node.p->next));
            }
            p = p->next;
        }
        return head->next;
    }
};