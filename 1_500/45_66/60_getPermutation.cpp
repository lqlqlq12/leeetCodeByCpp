/* 60. 排列序列

给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。 */
#include <string>
using namespace std;
#include <vector>

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> factors(n);
        vector<bool> used(n);
        factors[0] = 1;
        for (int i = 1; i < n; i++)
        {
            factors[i] = factors[i - 1] * i;
        }
        string re;
        k--;
        for (int i = 0; i < n; i++)
        {
            int factor = factors[n - i - 1];
            int index = k / factor;
            k %= factor;
            for (int j = 0, count = 0; j < n; j++)
            {
                if (used[j])
                {
                    continue;
                }
                if (count == index)
                {
                    re += ('1' + j);
                    used[j] = true;
                    break;
                }
                count++;
            }
        }
        return re;
    }
};