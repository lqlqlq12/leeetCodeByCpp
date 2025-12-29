/* 54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> re;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                re.emplace_back(matrix[top][i]);
            }
            top++;
            if (top > bottom)
            {
                return re;
            }
            for (int i = top; i <= bottom; i++)
            {
                re.emplace_back(matrix[i][right]);
            }
            right--;
            if (left > right)
            {
                return re;
            }
            for (int i = right; i >= left; i--)
            {
                re.emplace_back(matrix[bottom][i]);
            }
            bottom--;
            if (top > bottom)
            {
                return re;
            }
            for (int i = bottom; i >= top; i--)
            {
                re.emplace_back(matrix[i][left]);
            }
            left++;
        }
        return re;
    }
};