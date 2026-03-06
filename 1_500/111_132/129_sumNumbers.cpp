/* 129. 求根节点到叶节点数字之和
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。 */

#include <TreeNode_1.h>
#include <queue>
using namespace std;

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int ret = 0;
        if (!root)
        {
            return ret;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (!node->left && !node->right)
                {
                    ret += node->val;
                    continue;
                }
                if (node->left)
                {
                    node->left->val += (node->val * 10);
                    que.push(node->left);
                }
                if (node->right) {
                    node->right->val += (10*node->val);
                    que.push(node->right);
                }
            }
        }
        return ret;
    }
};