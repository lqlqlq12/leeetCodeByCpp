/* 107. 二叉树的层序遍历 II
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） */

#include <TreeNode_1.h>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> re;
        queue<TreeNode *> que;
        if (!root)
        {
            return re;
        }
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> arr(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                arr[i] = node->val;
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            re.push_back(arr);
        }
        reverse(re.begin(), re.end());
        return re;
    }
};