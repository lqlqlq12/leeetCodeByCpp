/* 99. 恢复二叉搜索树
相关企业
给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。 */

#include <TreeNode_1.h>
// Moriss中序遍历!!!
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *pred = nullptr, *predecessor, *x = nullptr, *y;
        while (root)
        {
            if (root->left)
            {
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root)
                {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    if (pred && root->val < pred->val)
                    {
                        y = root;
                        if (!x)
                        {
                            x = pred;
                        }
                    }
                    pred = root;
                    root = root->right;
                    predecessor->right = nullptr;
                }
            }
            else
            {
                if (pred && root->val < pred->val)
                {
                    y = root;
                    if (!x)
                    {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }

        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};