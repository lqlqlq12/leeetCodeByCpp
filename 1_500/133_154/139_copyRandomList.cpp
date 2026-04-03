
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#include <unordered_map>
using namespace std;

class Solution
{
private:
    unordered_map<Node *, Node *> map;

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        if (map.find(head) != map.end())
        {
            return map[head];
        }
        Node *stand = new Node(head->val);
        stand->next = copyRandomList(head->next);
        stand->random = copyRandomList(head->random);
        map[head] = stand;
        return stand;
    }
};