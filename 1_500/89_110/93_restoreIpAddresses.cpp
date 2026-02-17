/* 93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

*/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> re;
    string s;
    vector<string> restoreIpAddresses(string s)
    {
        this->s = s;
        vector<string> t;
        dfs(0, t);
        return re;
    }

    void dfs(int index, vector<string> &cur)
    {
        if (index == s.size())
        {
            if (cur.size() != 4)
            {
                return;
            }
            string str = cur[0];
            for (int i = 1; i < 4; i++)
            {
                str += ("." + cur[i]);
            }
            re.push_back(str);
            return;
        }
        if (s.size() - index > 3 * (4 - cur.size()))
        {
            return;
        }
        cur.emplace_back(string(1, s[index]));
        dfs(index + 1, cur);
        cur.pop_back();
        int val = s[index] - '0';
        for (int i = 1; i <= 2; i++)
        {
            val = val * 10 + (s[index + i] - '0');
            if (val < 10 || val > 255)
            {
                break;
            }
            cur.emplace_back(s.substr(index, i + 1));
            dfs(index + i + 1, cur);
            cur.pop_back();
        }
    }
};