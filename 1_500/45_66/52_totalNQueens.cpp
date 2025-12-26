/* 52. N 皇后 II
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 */
#include <vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        cols = vector<bool>(n);
        x = vector<bool>(2 * n - 1);
        y = vector<bool>(2 * n - 1);
        re = 0;
        dfs(0, n);
        return re;
    }

    vector<bool> cols;
    vector<bool> x;
    vector<bool> y;
    int re;


    void dfs(int index, int n)
    {
        if (index == n)
        {
            re++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!cols[i] && !x[i + n - index - 1] && !y[i + index])
            {
                cols[i] = x[i + n - index - 1] = y[i + index] = true;
                dfs(index + 1, n);
                cols[i] = x[i + n - index - 1] = y[i + index] = false;
            }
        }
    }
};