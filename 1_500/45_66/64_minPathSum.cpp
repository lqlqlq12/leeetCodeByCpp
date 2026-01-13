/* 64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < n; i++)
        {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < m; i++)
        {
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[m - 1][n - 1];
    }
};