/* 113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。 */

#include <TreeNode_1.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> re;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> t;
        if (!root)
        {
            return re;
        }
        t.push_back(root->val);
        dfs(root, t, targetSum - root->val);
        return re;
    }

    void dfs(TreeNode *root, vector<int> &arr, int target)
    {
        if (target == 0 && !root->left && !root->right)
        {
            re.push_back(arr);
        }
        if (root->left)
        {
            arr.push_back(root->left->val);
            dfs(root->left, arr, target - root->left->val);
            arr.pop_back();
        }
        if (root->right)
        {
            arr.push_back(root->right->val);
            dfs(root->right, arr, target - root->right->val);
            arr.pop_back();
        }
    }
};