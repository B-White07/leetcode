/**
 * Created by B_White on 2024/7/28.
 * https://leetcode.cn/problems/group-anagrams/description/
 */
//Exceeding the time limit
class Solution {
public:
    bool Anagram(string s, string t) {  //judge if 2 string is Anagram
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
            return {strs};  //return {}; is also OK.return {} can return the type the function need.

        vector<vector<string>> ans;

        //the outer layer for loop is to group all the string.
        //the inner layer for loop is to find which group current string belongs to.
        for (const auto& str : strs) {
            bool found = false; //represent if current str belongs to any group in current vector ans.
            for (auto& group : ans) {   //traverse every group anagrams in ans.
                if (Anagram(str, group[0])) {   //group[0] can access the first str in one group,compare this two is anagram or not
                    group.push_back(str);   //①if they are,no need to find,the str belongs to current group
                    found = true;
                    break;
                }
            }
            if (!found) {   //⓶if they are not,create a new group in the ans vector.
                ans.push_back({str});
            }
        }
        return ans;
    }
};

//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};

        unordered_map<string, vector<string>> hash; //store the a set of same Anagrams as value,the key is one ordered string of the group

        for (const auto& str : strs) {  //divide different groups and save the same group as value of a certain key
            string key = str;
            sort(key.begin(), key.end());   //the ordered key is the real key of a group of Anagrams
            hash[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& pair : hash) {
            ans.push_back(pair.second); //insert every group into the vector
        }

        return ans;
    }
};