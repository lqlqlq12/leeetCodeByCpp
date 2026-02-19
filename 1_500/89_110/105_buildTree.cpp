/* 105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 */

#include <TreeNode_1.h>
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2)
    {
        int rootVal = preorder[l1], rootIndex;
        TreeNode *root = new TreeNode(rootVal);
        if (l1 == r1)
        {
            return root;
        }
        for (rootIndex = l2; rootIndex <= r2; rootIndex++)
        {
            if (inorder[rootIndex] == rootVal)
            {
                break;
            }
        }
        int leftChildsNum = rootIndex - l2, rightChildsNum = r1 - l1 - leftChildsNum;
        if (leftChildsNum > 0)
        {
            root->left = build(preorder, inorder, l1 + 1, l1 + leftChildsNum, l2, rootIndex - 1);
        }
        if (rightChildsNum > 0)
        {
            root->right = build(preorder, inorder, r1 - rightChildsNum + 1, r1, rootIndex + 1, r2);
        }
        return root;
    }
};