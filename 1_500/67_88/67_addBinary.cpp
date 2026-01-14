/* 67. 二进制求和
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。 */
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string re;
        int aLen = a.size(), bLen = b.size(), len = max(aLen, bLen), remain = 0;
        for (int i = 0; i < len; i++)
        {
            if (i < aLen && a[aLen - i - 1] == '1')
                remain += 1;
            if (i < bLen && b[bLen - i - 1] == '1')
                remain += 1;
            re = char('0' + remain % 2) + re;
            remain /= 2;
        }
        if (remain != 0)
        {
            re = '1' + re;
        }
        return re;
    }
};