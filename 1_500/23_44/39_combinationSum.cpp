/* 39. 组合总和

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的不同组合数少于 150 个。 */

#include <algorithm>
using namespace std;
#include <vector>

// dfs
class Solution
{
public:
    vector<vector<int>> re;
    vector<int> array;
    int finalTarget;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        array = candidates;
        finalTarget = target;
        vector<int> cur;
        dfs(cur, 0, 0);
        return re;
    }

    void dfs(vector<int> current, int sum, int index)
    {
        if (sum == finalTarget)
        {
            re.push_back(vector<int>(current));
            return;
        }
        for (int i = index; i < array.size(); i++)
        {
            if (sum + array[i] > finalTarget)
            {
                break;
            }
            current.push_back(array[i]);
            dfs(current, sum + array[i], i);
            current.pop_back();
        }
    }
};