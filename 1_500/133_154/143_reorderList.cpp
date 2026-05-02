/* 143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 */
#include <ListNode_1.h>

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return;
        }
        ListNode *slow = head, *fast = head, *last = 0;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        while (slow->next)
        {
            ListNode *t = slow->next;
            slow->next = last;
            last = slow;
            slow = t;
        }
        slow->next = last;
        while (slow)
        {
            ListNode *t1 = head->next;
            ListNode *t2 = slow->next;
            head->next = slow;
            slow->next = t1;
            head = t1;
            slow = t2;
        }
        head->next = slow;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    Solution sol;
    sol.reorderList(l1);
    return 0;
}