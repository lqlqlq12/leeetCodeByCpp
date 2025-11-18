#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int len = s.length(), l = 0, r = 0, maxSize = 0;
        for (; r < len; r++) {
            char right = s.at(r);
            if (set.find(right) != set.end()) {
                if (set.size() > maxSize) {
                    maxSize = set.size();
                }
                while (s.at(l) != right) {
                    set.erase(s.at(l));
                    l++;
                }
                l++;
            }
            set.insert(right);
        }
        if (set.size() > maxSize) {
            maxSize = set.size();
        }
        return maxSize;
    }
};