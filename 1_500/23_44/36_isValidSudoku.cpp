/* 36. 有效的数独

请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） */

#include <vector>
using namespace std;
#include <unordered_set>

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> blocks(9);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char alpha = board[i][j];
                if (alpha == '.')
                {
                    continue;
                }
                int number = alpha - '0';
                if (rows[i].find(number) != rows[i].end() || cols[j].find(number) != cols[j].end())
                {
                    return false;
                }
                int index = (i / 3) * 3 + j / 3;
                if (blocks[index].find(number) != blocks[index].end())
                {
                    return false;
                }
                rows[i].insert(number);
                cols[j].insert(number);
                blocks[index].insert(number);
            }
        }
        return true;
    }
};