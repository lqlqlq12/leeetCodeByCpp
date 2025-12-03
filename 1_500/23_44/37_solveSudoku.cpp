/* 37. 解数独


数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

 */

#include <vector>
using namespace std;

class Solution
{
public:
    bool rows[9][9];
    bool cols[9][9];
    bool blocks[3][3][9];
    vector<pair<int, int>> spaces;

    bool dfs(vector<vector<char>> &board, int index)
    {
        if (index == spaces.size())
        {
            return true;
        }
        auto [i, j] = spaces[index];
        for (int digit = 0; digit < 9; digit++)
        {
            if (!rows[i][digit] && !cols[j][digit] && !blocks[i / 3][j / 3][digit])
            {
                board[i][j] = '0' + digit + 1;
                rows[i][digit] = cols[j][digit] = blocks[i / 3][j / 3][digit] = true;
                if (dfs(board, index + 1))
                {
                    return true;
                }
                rows[i][digit] = cols[j][digit] = blocks[i / 3][j / 3][digit] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(blocks, false, sizeof(blocks));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
                else
                {
                    int digit = board[i][j] - '0' - 1;
                    rows[i][digit] = cols[j][digit] = blocks[i / 3][j / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }
};