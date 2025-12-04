/* 40. 组合总和 II

给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。  */

#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> re;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> list;
        dfs(target, 0, list, candidates, 0);
        return re;
    }

    void dfs(int target, int currentSum, vector<int> currentList, vector<int> preparedList, int index)
    {
        if (currentSum == target)
        {
            re.push_back(vector<int>(currentList));
            return;
        }
        for (int i = index; i < preparedList.size(); i++)
        {
            if (currentSum + preparedList[i] > target)
            {
                break;
            }
            if (i > index && preparedList[i] == preparedList[i - 1])
            {
                continue;
            }
            currentList.push_back(preparedList[i]);
            dfs(target, currentSum + preparedList[i], currentList, preparedList, i + 1);
            currentList.pop_back();
        }
    }
};