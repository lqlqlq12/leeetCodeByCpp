/* 69. x 的平方根
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 */

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 1, right = x, re = 0;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if ((long)mid * mid == x)
            {
                return mid;
            }
            else if ((long)mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                re = mid;
                left = mid + 1;
            }
        }
        return re;
    }
};