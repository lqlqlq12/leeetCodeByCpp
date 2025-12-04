/* 43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int len1 = num1.size(), len2 = num2.size(), totalLen = len1 + len2;
        vector<int> arr1(len1), arr2(len2), total(totalLen);
        const char *p1 = num1.c_str(), *p2 = num2.c_str();
        for (int i = 0; i < len1; i++)
        {
            arr1[i] = p1[i] - '0';
        }

        for (int i = 0; i < len2; i++)
        {
            arr2[i] = p2[i] - '0';
        }

        for (int i = len1 - 1; i >= 0; i--)
        {
            int factor1 = arr1[i];
            for (int j = len2 - 1; j >= 0; j--)
            {
                int mul = factor1 * arr2[j];
                int index = totalLen - 1 - ((len1 - 1 - i) + (len2 - 1 - j));
                total[index] += mul;
            }
        }
        int remain = 0;
        for (int i = totalLen - 1; i >= 0; i--)
        {
            int temp = total[i] + remain;
            total[i] = temp % 10;
            remain = temp / 10;
        }
        string re;
        for (int i = 0; i < totalLen; i++)
        {
            if (total[i] == 0 && re == "")
            {
                continue;
            }
            re += total[i] - 0 + '0';
        }
        return re == "" ? "0" : re;
    }
};
