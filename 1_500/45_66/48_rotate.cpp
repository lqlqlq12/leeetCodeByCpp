/* 48. 旋转图像

给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。 */

#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), top = 0, bottom = n - 1, left = 0, right = n - 1;
        for (int i = 0; i < n / 2; i++)
        {
            int t = matrix[top][left];
            matrix[top][left] = matrix[bottom][left];
            matrix[bottom][left] = matrix[bottom][right];
            matrix[bottom][right] = matrix[top][right];
            matrix[top][right] = t;
            vector<int> temp(n - 2 * i - 2);
            for (int j = left + 1; j <= right - 1; j++)
            {
                temp[j - left - 1] = matrix[top][j];
                matrix[top][j] = matrix[bottom + left - j][left];
            }
            for (int j = top + 1; j <= bottom - 1; j++)
            {
                matrix[j][left] = matrix[bottom][left + j - top];
            }
            for (int j = left + 1; j <= right - 1; j++)
            {
                matrix[bottom][j] = matrix[bottom - j + left][right];
            }
            for (int j = top + 1; j <= bottom - 1; j++)
            {
                matrix[j][right] = temp[j - top - 1];
            }
            top++;
            bottom--;
            left++;
            right--;
        }
    }
};

int main()
{
    vector<vector<int>> t{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution sol;
    sol.rotate(t);
    return 0;
}