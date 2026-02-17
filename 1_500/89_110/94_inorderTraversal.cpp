/* 94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <TreeNode_1.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> re;
    vector<int> inorderTraversal(TreeNode *root)
    {
        inOrder(root);
        return re;
    }

    void inOrder(TreeNode *node)
    {
        if (!node)
            return;
        inOrder(node->left);
        re.push_back(node->val);
        inOrder(node->right);
    }
};