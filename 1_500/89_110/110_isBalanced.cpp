/* 110. 平衡二叉树
给定一个二叉树，判断它是否是 平衡二叉树

*/

#include <TreeNode_1.h>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int lh = height(root->left), rh = height(root->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
        {
            return -1;
        }
        return max(lh, rh) + 1;
    }
};
