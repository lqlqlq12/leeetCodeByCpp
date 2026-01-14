/* 66. 加一

premium lock icon
相关企业
给定一个表示 大整数 的整数数组 digits，其中 digits[i] 是整数的第 i 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 0。

将大整数加 1，并返回结果的数字数组。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        digits[len - 1] += 1;
        for (int i = len - 1; i >= 1; i--)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                digits[i - 1]++;
            }
            else
            {
                return digits;
            }
        }
        if (digits[0] != 10)
            return digits;

        vector<int> ans(len + 1);
        ans[0] = 1;
        return ans;
    }
};