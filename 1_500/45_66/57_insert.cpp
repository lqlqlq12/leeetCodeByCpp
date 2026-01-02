/* 57. 插入区间
提示
给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。

在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。

返回插入之后的 intervals。

注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> re;
        int i;
        bool hasInsert = false;
        for (i = 0; i < intervals.size(); i++)
        {
            vector<int> item = intervals[i];
            int start = item[0], end = item[1];
            if (end < newInterval[0])
            {
                re.emplace_back(item);
            }
            else if (start > newInterval[1])
            {
                hasInsert = true;
                re.emplace_back(newInterval);
                re.emplace_back(item);
                i++;
                break;
            }
            else
            {
                hasInsert = true;
                int newStart = min(newInterval[0], start), newEnd;
                while (i < intervals.size() && newInterval[1] >= intervals[i][0])
                {
                    newEnd = max(newInterval[1], intervals[i][1]);
                    i++;
                }

                re.push_back({newStart, newEnd});
                break;
            }
        }
        for (; i < intervals.size(); i++)
        {
            re.emplace_back(intervals[i]);
        }
        if (!hasInsert)
        {
            re.emplace_back(newInterval);
        }
        return re;
    }
};