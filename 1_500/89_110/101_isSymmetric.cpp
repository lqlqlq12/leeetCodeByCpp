/* 101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/
#include <TreeNode_1.h>

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSame(p->left, q->right) && isSame(p->right, q->left);
    }
};