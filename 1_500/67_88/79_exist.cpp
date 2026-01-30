/* 79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> isUsed;
    vector<vector<char>> board;
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        isUsed = vector<vector<bool>>(m, vector<bool>(n));
        this->board = board;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    isUsed[i][j] = true;
                    if (dfs(i, j, word, 0))
                    {
                        return true;
                    }
                    isUsed[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(int row, int col, string word, int index)
    {
        if (index == word.size() - 1)
            return true;
        if (row > 0)
        {
            if (!isUsed[row - 1][col] && word[index + 1] == board[row - 1][col])
            {
                isUsed[row - 1][col] = true;
                if (dfs(row - 1, col, word, index + 1))
                    return true;
                isUsed[row - 1][col] = false;
            }
        }
        if (row < board.size() - 1)
        {
            if (!isUsed[row + 1][col] && word[index + 1] == board[row + 1][col])
            {
                isUsed[row + 1][col] = true;
                if (dfs(row + 1, col, word, index + 1))
                    return true;
                isUsed[row + 1][col] = false;
            }
        }
        if (col > 0)
        {
            if (!isUsed[row][col - 1] && word[index + 1] == board[row][col - 1])
            {
                isUsed[row][col - 1] = true;
                if (dfs(row, col - 1, word, index + 1))
                    return true;
                isUsed[row][col - 1] = false;
            }
        }
        if (col < board[0].size() - 1)
        {
            if (!isUsed[row][col + 1] && word[index + 1] == board[row][col + 1])
            {
                isUsed[row][col + 1] = true;
                if (dfs(row, col + 1, word, index + 1))
                    return true;
                isUsed[row][col + 1] = false;
            }
        }
        return false;
    }
};