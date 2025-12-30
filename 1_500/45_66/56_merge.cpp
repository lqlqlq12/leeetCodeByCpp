/* 56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
        //      {
        //     if (a[0]!=b[0]){
        //         return a[0]<b[0];
        //     }
        //     return a[1]<b[1]; });
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> re;
        int m = intervals.size();
        re.emplace_back(intervals[0]);
        for (int i = 1; i < m; i++)
        {
            vector<int> before = re[re.size() - 1];
            if (before[1] < intervals[i][0])
            {
                re.emplace_back(intervals[i]);
                continue;
            }
            re.back()[1] = max(intervals[i][1], before[1]);
        }
        return re;
    }
};