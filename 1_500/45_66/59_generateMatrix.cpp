/* 59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> re(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1, num = 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                re[top][i] = num++;
            }
            top++;
            if (top > bottom)
                return re;
            for (int i = top; i <= bottom; i++)
            {
                re[i][right] = num++;
            }
            right--;
            if (left > right)
                return re;
            for (int i = right; i >= left; i--)
            {
                re[bottom][i] = num++;
            }
            bottom--;
            if (top > bottom)
                return re;
            for (int i = bottom; i >= top; i--)
            {
                re[i][left] = num++;
            }
            left++;
        }
        return re;
    }
};