/* 104. 二叉树的最大深度
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。 */

#include <TreeNode_1.h>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        int depth = 0;
        if (!root)
        {
            return depth;
        }
        que.push(root);
        while (!que.empty())
        {
            depth++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left){
                    que.push(node->left);
                }
                if (node->right){
                    que.push(node->right);
                }
            }
        }
        return depth;
    }
};