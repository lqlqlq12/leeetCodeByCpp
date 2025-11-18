/* 22. 括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 */

// dfs (:+1 ):-1 添加(times-1

#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> re;
    vector<string> generateParenthesis(int n)
    {
        int len = 2 * n;
        char str[len + 1];
        dfs(0, n,0, str);
        return re;
    }

    // remain: 需要添加的 ')' 数量, times: 还能添加的 '(' 数量
    void dfs(int remain, int times, int index, char str[])
    {
        if (remain == 0 && times == 0)
        {
            str[index] = '\0';  // ✅ 字符串结束符
            re.push_back(string(str));
            return;
        }

        if (remain == 0)
        { // 只能加 '('
            str[index] = '(';
            dfs(1, times - 1, index + 1, str);
        }
        else
        {
            str[index] = ')';
            dfs(remain - 1, times, index + 1, str);
            if (times > 0)
            {
                str[index] = '(';
                dfs(remain + 1, times - 1, index + 1, str);  // ✅ times 拼写修正
            }
        }
    }
};