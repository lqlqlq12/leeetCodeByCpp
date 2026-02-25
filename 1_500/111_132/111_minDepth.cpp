/* 111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/
#include <TreeNode_1.h>
#include <queue>
using namespace std;

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        int re = 0;
        if (!root)
        {
            return re;
        }
        que.push(root);
        re++;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (!node->left && !node->right)
                {
                    return re;
                }
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            re++;
        }
        return re;
    }
};