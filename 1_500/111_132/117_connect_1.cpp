/* 117. 填充每个节点的下一个右侧节点指针 II
给定一个二叉树：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。

初始状态下，所有 next 指针都被设置为 NULL 。 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <Node_1.h>
#include <queue>
using namespace std;

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        if (!root)
        {
            return root;
        }
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            Node *pre = nullptr;
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                if (pre)
                {
                    pre->next = node;
                }
                pre = node;
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};
