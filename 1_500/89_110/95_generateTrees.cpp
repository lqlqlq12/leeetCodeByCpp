/* 95. 不同的二叉搜索树 II
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。 */

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
    vector<TreeNode *> generateTrees(int n)
    {
        return generate(1, n);
    }

    vector<TreeNode *> generate(int start, int end)
    {
        vector<TreeNode *> re;
        if (start == end)
        {
            re.emplace_back(new TreeNode(start));
            return re;
        }

        vector<TreeNode *> l = generate(start, end - 1);
        vector<TreeNode *> r = generate(start + 1, end);
        for (TreeNode *left : l){
            TreeNode *root = new TreeNode(end);
            root->left = left;
            re.emplace_back(root);
        }
        for (TreeNode *right : r){
            TreeNode *root = new TreeNode(start);
            root->right = right;
            re.emplace_back(root);
        }
        for (int index = start + 1; index < end; index++)
        {
            vector<TreeNode *> leftNodes = generate(start, index - 1);
            vector<TreeNode *> rightNodes = generate(index + 1, end);
            for (TreeNode *left : leftNodes)
            {
                for (TreeNode *right : rightNodes)
                {
                    TreeNode *root = new TreeNode(index);
                    root->left = left;
                    root->right = right;
                    re.emplace_back(root);
                }
            }
        }
        return re;
    }
};