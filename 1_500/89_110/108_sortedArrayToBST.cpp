/* 108. 将有序数组转换为二叉搜索树
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。 */

#include <TreeNode_1.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nums;
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        this->nums = nums;
        return build(0, nums.size() - 1);
    }

    TreeNode *build(int left, int right)
    {
        if (left >= right)
        {
            return new TreeNode(nums[left]);
        }

        int index = left + ((right - left) >> 1);
        TreeNode *root = new TreeNode(nums[index]);
        if (index > left)
        {
            root->left = build(left, index - 1);
        }
        root->right = build(index + 1, right);
        return root;
    }
};