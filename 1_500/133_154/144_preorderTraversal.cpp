/* 44. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 */

#include <TreeNode_1.h>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> re;
        if (!root)
        {
            return re;
        }
        stack<TreeNode *> stash;
        while (root || !stash.empty())
        {
            while (root)
            {
                stash.push(root);
                re.push_back(root->val);
                root = root->left;
            }
            root = stash.top();
            stash.pop();
            root = root->right;
        }
        return re;
    }
};