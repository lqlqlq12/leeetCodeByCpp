#include <vector>
using namespace std;
#include <iostream>

/* 给你一个字符串 s，找到 s 中最长的 回文 子串。 */
/* dp[i][j] 表示[i...j]是否为回文串*/
class Solution {
   public:
    string longestPalindrome(string s) {
        int len = s.size(), maxLen = 1, maxIndex = 0;
        if (len < 2) {
            return s;
        }
        vector<vector<bool>> dp(len, vector<bool>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for (int size = 2; size <= len; size++) {
            if (size - maxLen > 2) {
                break;
            }
            for (int left = 0; left + size - 1 < len; left++) {
                if (s[left] == s[left + size - 1]) {
                    if (size == 2) {
                        dp[left][left + size - 1] = true;
                    } else {
                        dp[left][left + size - 1] = dp[left + 1][left + size - 2];
                    }
                    if (dp[left][left + size - 1] && size > maxLen) {
                        maxLen = size;
                        maxIndex = left;
                    }
                }
            }
        }
        return s.substr(maxIndex, maxLen);
    }
};

int main() {
    Solution sol;
    string re = sol.longestPalindrome("aba");
    cout<<re;
    return 0;
}