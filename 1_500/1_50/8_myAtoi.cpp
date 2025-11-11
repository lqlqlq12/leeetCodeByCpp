#include <string>
#include <iostream>
using namespace std;

/* 8. 字符串转换整数 (atoi)

请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。

函数 myAtoi(string s) 的算法如下：

空格：读入字符串并丢弃无用的前导空格（" "）
符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
返回整数作为最终结果。 */

class Solution
{
public:
    int myAtoi(string s)
    {
        int len = s.size(), re = 0, index = 0, sign = 1;
        if (len == 0)
        {
            return re;
        }
        const char *p = s.c_str();
        while (index < len && p[index] == ' ')
        {
            index++;
        }
        if (index == len)
            return re;
        if (p[index] == '-' || p[index] == '+')
        {
            sign = p[index] == '-' ? -1 : 1;
            index++;
        }
        for (; index < len && p[index] >= '0' && p[index] <= '9'; index++)
        {
            int digit = p[index] - '0';
            if (re == 0)
            {
                re = digit * sign;
                continue;
            }
            if ((re > INT_MIN / 10 && re < INT_MAX / 10) || (re == INT_MIN / 10 && digit <= 8) || (re == INT_MAX / 10 && digit <= 7))
            {
                re = re * 10 + digit * sign;
            }
            else if (sign == -1 )
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
        return re;
    }
};

int main()
{
    Solution sol;
    int re = sol.myAtoi("2147483648");
    cout << re << endl;
    return 0;
}