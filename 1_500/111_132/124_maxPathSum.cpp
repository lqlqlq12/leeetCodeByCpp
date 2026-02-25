/* 124. 二叉树中的最大路径和]
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。 */

#include <TreeNode_1.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int re;
    int maxPathSum(TreeNode *root)
    {
        re = INT_MIN;
        maxGain(root);
        return re;
    }

    int maxGain(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            re = max(re, root->val);
            return root->val;
        }
        int lVal = max(maxGain(root->left), 0), rVal = max(maxGain(root->right), 0);
        re = max(re, lVal + rVal + root->val);
        return max(lVal, rVal) + root->val;
    }
};