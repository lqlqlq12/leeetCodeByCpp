/* 77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。 */

#include <vector>
using namespace std;
// dfs
class Solution
{
public:
    vector<vector<int>> re;

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        dfs(temp, 1, n, k);
        return re;
    }

    void dfs(vector<int> &current, int index, int n, int k)
    {
        if (current.size() == k)
        {
            re.emplace_back(current);
            return;
        }
        for (int i = index; i <= n - k + current.size() + 1; i++)
        {
            current.emplace_back(i);
            dfs(current, i + 1, n, k);
            current.pop_back();
        }
    }
};