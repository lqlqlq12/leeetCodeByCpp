/* 49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。 */
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> re;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            map[str].emplace_back(strs[i]);
        }
        // for (auto [key, value] : map)
        // {
        //     re.push_back(value);
        // }
        for (auto it = map.begin(); it != map.end(); it++)
        {
            re.emplace_back(it->second);
        }
        return re;
    }
};