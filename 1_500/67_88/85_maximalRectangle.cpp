/* 85. 最大矩形
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 */
#include <vector>
using namespace std;
#include <stack>

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), re = 0;
        vector<int> high(n, 0);
        for (int i = 0; i < m; i++)
        {
            stack<int> sta;
            sta.push(-1);
            vector<int> left(n), right(n, n);
            for (int j = 0; j < n; j++)
            {
                high[j] = matrix[i][j] == '1' ? high[j] + 1 : 0;
                while (sta.top() != -1 && high[sta.top()] >= high[j])
                {
                    right[sta.top()] = j;
                    sta.pop();
                }
                left[j] = sta.top();
                sta.push(j);
            }
            for (int j = 0; j < n; j++)
            {
                re = max(re, high[j] * (right[j] - left[j] - 1));
            }
        }
        return re;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> t {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    sol.maximalRectangle(t);
    return 0;
}