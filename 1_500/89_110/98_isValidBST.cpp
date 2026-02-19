/* 98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 严格小于 当前节点的数。
节点的右子树只包含 严格大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

#include <TreeNode_1.h>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> sta;
        long last = INT_MIN - (long)1;
        while (!sta.empty() || root)
        {
            while (root)
            {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            if (root->val <= last)
            {
                return false;
            }
            last = root->val;
            root = root->right;
        }
        return true;
    }
};