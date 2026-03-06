/* 130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：

连接：一个单元格与水平或垂直方向上相邻的单元格连接。
区域：连接所有 'O' 的单元格来形成一个区域。
围绕：如果一个区域中的所有 'O' 单元格都不在棋盘的边缘，则该区域被包围。这样的区域 完全 被 'X' 单元格包围。
通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> isUsed;
    vector<vector<char>> board;
    int m, n;
    void solve(vector<vector<char>> &board)
    {
        this->board = board;
        m = board.size(), n = board[0].size();
        isUsed = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {

            if (board[i][0] == 'O' && !isUsed[i][0])
            {
                dfs(i, 0);
            }
            if (board[i][n - 1] == 'O' && !isUsed[i][n - 1])
            {

                dfs(i, n - 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' && !isUsed[0][i])
            {
                dfs(0, i);
            }
            if (board[m - 1][i] == 'O' && !isUsed[m - 1][i])
            {
                dfs(m - 1, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !isUsed[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int x, int y)
    {
        isUsed[x][y] = true;
        if (x > 0 && board[x - 1][y] == 'O' && !isUsed[x - 1][y])
        {
            dfs(x - 1, y);
        }
        if (x < m - 1 && board[x + 1][y] == 'O' && !isUsed[x + 1][y])
        {
            dfs(x + 1, y);
        }
        if (y > 0 && board[x][y - 1] == 'O' && !isUsed[x][y - 1])
        {
            dfs(x, y - 1);
        }
        if (y < n - 1 && board[x][y + 1] == 'O' && !isUsed[x][y + 1])
        {
            dfs(x, y + 1);
        }
    }
};