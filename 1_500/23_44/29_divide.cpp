/* 29. 两数相除

给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

返回被除数 dividend 除以除数 divisor 得到的 商 。

注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。 */

using namespace std;
#include <iostream>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN)
        {
            if (divisor == 1)
            {
                return INT_MIN;
            }
            else if (divisor == -1)
            {
                return INT_MAX;
            }
        }
        if (dividend == 0)
        {
            return 0;
        }
        // 统一转负数
        int reverse = 1;
        if (dividend > 0)
        {
            reverse = -reverse;
            dividend = -dividend;
        }
        if (divisor > 0)
        {
            reverse = -reverse;
            divisor = -divisor;
        }

        int left = 1, right = INT_MAX, re = 0;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            bool check = isBigger(dividend, divisor, mid);
            if (check)
            {
                re = mid;
                if (mid == INT_MAX)
                {
                    return reverse == 1 ? INT_MAX : INT_MIN + 1;
                }
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return reverse == 1 ? re : -re;
    }

    // return y * z >= x,x<0,y<0,z>0
    bool isBigger(int x, int y, int z)
    {
        int result = 0, add = y;
        while (z)
        {
            if (z & 1)
            {
                if (result < x - add) // result+add超范围
                {
                    return false;
                }
                result += add;
            }
            if (z != 1)
            {
                if (add < x - add) // add+add超范围
                {
                    return false;
                }
                add <<= 1;
            }
            z >>= 1;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    sol.divide(2147483647, 1);
}