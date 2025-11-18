#include <ListNode_1.h>
#include <iostream>
using namespace std;
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2, *head = new ListNode(), *r = head;

        int remain = 0;
        while (p || q) {
            int pVal = p ? p->val : 0;
            int qVal = q ? q->val : 0;
            int sum = pVal + qVal + remain;
            r->next = new ListNode(sum % 10);
            r = r->next;
            remain = sum / 10;
            if (p) {
                p = p->next;
            }
            if (q) {
                q = q->next;
            }
        }
        if (remain != 0) {
            r->next = new ListNode(remain % 10);
        }
        return head -> next;
    }
};