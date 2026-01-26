/* 74. 搜索二维矩阵
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

*/
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, possibleRow = -1;
        while (top <= bottom)
        {
            int mid = top + ((bottom - top) >> 1);
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
            {
                bottom = mid - 1;
            }
            else
            {
                possibleRow = mid;
                top = mid + 1;
            }
        }
        if (possibleRow == -1)
        {
            return false;
        }
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (matrix[possibleRow][mid] == target)
            {
                return true;
            }
            else if (matrix[possibleRow][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};