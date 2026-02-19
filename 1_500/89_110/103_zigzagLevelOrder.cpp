/* 103. 二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 */

#include <TreeNode_1.h>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int direction = 1;
        vector<vector<int>> re;
        deque<TreeNode *> deq;
        if (!root)
        {
            return re;
        }
        deq.push_back(root);
        while (!deq.empty())
        {
            int size = deq.size();
            vector<int> arr(size);
            for (int i = 0; i < size; i++)
            {
                if (direction == 1)
                {
                    TreeNode *node = deq.front();
                    deq.pop_front();
                    arr[i] = node->val;
                    if (node->left)
                    {
                        deq.push_back(node->left);
                    }
                    if (node->right)
                    {
                        deq.push_back(node->right);
                    }
                }
                else
                {
                    TreeNode *node = deq.back();
                    deq.pop_back();
                    arr[i] = node->val;
                    if (node->right)
                    {
                        deq.push_front(node->right);
                    }
                    if (node->left)
                    {
                        deq.push_front(node->left);
                    }
                }
            }
            direction = -direction;
            re.push_back(arr);
        }
        return re;
    }
};