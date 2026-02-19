/* 96. 不同的二叉搜索树
相关企业
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。 */
#include <ListNode_1.h>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> memory;
    int n;
    int numTrees(int n)
    {
        this->n = n;
        memory = vector<int>((n + 1) * (n + 1));
        return generateNums(1, n);
    }

    int &at(int i, int j)
    {
        return memory[i * (n + 1) + j];
    }

    int generateNums(int start, int end)
    {
        if (at(start, end) != 0)
        {
            return at(start, end);
        }

        if (start == end)
        {
            return 1;
        }
        int re = 0;
        re += generateNums(start + 1, end);
        re += generateNums(start, end - 1);
        for (int index = start + 1; index < end; index++)
        {
            re += (generateNums(start, index - 1) * generateNums(index + 1, end));
        }
        at(start, end) = re;
        return re;
    }
};