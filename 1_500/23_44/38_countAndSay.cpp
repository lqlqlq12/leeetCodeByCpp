/* 38. 外观数列

「外观数列」是一个数位字符串序列，由递归公式定义：

countAndSay(1) = "1"
countAndSay(n) 是 countAndSay(n-1) 的行程长度编码。


行程长度编码（RLE）是一种字符串压缩方法，其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的串联。例如，要压缩字符串 "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11" 替换。因此压缩后字符串变为 "23321511"。

给定一个整数 n ，返回 外观数列 的第 n 个元素。 */

#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string re = "1";
        for (int i = 1; i < n; i++)
        {
            re = next(re);
        }
        return re;
    }

    string next(string n)
    {
        int size = n.size();
        char alpha = n[0];
        int times = 1;
        string re = "";
        for (int i = 1; i < size; i++)
        {
            if (n[i] == alpha)
            {
                times++;
            }
            else
            {
                re += (to_string(times) + alpha);
                alpha = n[i];
                times = 1;
            }
        }
        re += (to_string(times) + alpha);
        return re;
    }

    string updateVer(int n)
    {
        string re = "1";
        for (int i = 2; i <= n; i++)
        {
            int pos = 0, start = 0;
            string cur = "";
            while (pos < re.size())
            {
                while (pos < re.size() && re[start] == re[pos])
                {
                    pos++;
                }
                cur += (to_string(pos - start) + re[start]);
                start = pos;
            }
            re = cur;
        }

        return re;
    }
};

int main()
{
    Solution sol;
    sol.countAndSay(6);
}