/**
 * Created by B_White on 2024/7/28.
 * https://leetcode.cn/problems/group-anagrams/description/
 */
//Exceeding the time limit
class Solution {
public:
    bool Anagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> ans;

        for (const auto& ch : s)
            ans[ch]++;

        for (const auto& ch : t) {
            ans[ch]--;
            if (ans[ch] < 0)
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {strs};

        vector<vector<string>> ans;

        for (const auto& str : strs) {
            bool found = false;
            for (auto& group : ans) {
                if (Anagram(str, group[0])) {
                    group.push_back(str);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back({str});
            }
        }
        return ans;
    }
};

