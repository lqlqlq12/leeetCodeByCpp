/* 51. N 皇后

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 */
#include <string>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<bool> rows;
    vector<bool> cols;
    vector<bool> x;
    vector<bool> y;
    vector<vector<string>> re;

    vector<vector<string>> solveNQueens(int n)
    {
        rows = vector<bool>(n);
        cols = vector<bool>(n);
        x = vector<bool>(2 * n - 1);
        y = vector<bool>(2 * n - 1);
        vector<string> lists;
        dfs(0, n, lists);
        return re;
    }

    void dfs(int index, int n, vector<string> &lists)
    {
        if (index == n)
        {
            re.emplace_back(lists);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!cols[i] && !x[i + n - index - 1] && !y[i + index])
            {
                cols[i] = x[i + n - index - 1] = y[i + index] = true;
                string str(n, '.');
                str[i] = 'Q';
                lists.emplace_back(str);
                dfs(index + 1, n, lists);
                lists.pop_back();
                cols[i] = x[i + n - index - 1] = y[i + index] = false;
            }
        }
    }
};
