/* 102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 */

#include <TreeNode_1.h>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> re;
        if (!root)
        {
            return re;
        }
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> tArr(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                tArr[i] = node->val;
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            re.push_back(tArr);
        }
        return re;
    }
};