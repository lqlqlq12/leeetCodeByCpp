/* 109. 有序链表转换二叉搜索树
给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为 平衡 二叉搜索树。
*/

#include <ListNode_1.h>
#include <TreeNode_1.h>

class Solution
{
public:
    ListNode *hair;
    TreeNode *sortedListToBST(ListNode *head)
    {
        hair = head;
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return recursion(0, len - 1);
    }

    TreeNode *recursion(int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode();
        int mid = left + ((right - left) >> 1);
        root->left = recursion(left, mid - 1);
        root->val = hair->val;
        hair = hair->next;
        root->right = recursion(mid + 1, right);
        return root;
    }
};