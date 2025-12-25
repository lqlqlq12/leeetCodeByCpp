/* 50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
-100.0 < x < 100.0
-231 <= n <= 231-1
n 是一个整数
要么 x 不为零，要么 n > 0 。
-104 <= xn <= 104
 */

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        if (x == -1)
        {
            return n % 2 == 0 ? 1 : -1;
        }
        double re = x;
        return n > 0 ? quickMulti(x, n) : 1 / quickMulti(x, -(long)n);
    }

    double quickMulti(double x, long n)
    {
        double factor = x, re = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                re *= factor;
            }
            factor *= factor;
            n >>= 1;
        }
        return re;
    }
};