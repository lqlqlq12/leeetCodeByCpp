/* 106. 从中序与后序遍历序列构造二叉树
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。 */
#include <TreeNode_1.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> map;
    vector<int> inorder, postorder;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        this->inorder = inorder;
        this->postorder = postorder;
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        return build(0, inorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(int l1, int r1, int l2, int r2)
    {
        int rootVal = postorder[r2];
        TreeNode *root = new TreeNode(rootVal);
        if (l1 == r1)
        {
            return root;
        }
        int index = map[rootVal], leftNums = index - l1, rightNums = r1 - l1 - leftNums;
        if (leftNums > 0)
        {
            root->left = build(l1, index - 1, l2, l2 + leftNums - 1);
        }
        if (rightNums > 0)
        {
            root->right = build(index + 1, r1, r2 - rightNums, r2 - 1);
        }
        return root;
    }
};