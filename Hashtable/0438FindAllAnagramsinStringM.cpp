/**
 * Created by B_White on 2024/7/31.
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 */
#include "iostream"
#include "map"
#include "vector"

using namespace std;

//exceeding time limit.holy shit I always get this.
/*bool isAnagrams(string s, string t) {
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> hash;
    for (const auto& ch : s) {
        hash[ch]++;
    }

    for (const auto& ch : t) {
        hash[ch]--;
        if (hash[ch] < 0)
            return false;
    }

    return true;
}

vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size())
        return {};

    vector<int> ans;
    int left = 0, right = p.size();
    string str(s, left, p.size());

    while (right <= s.size()) {
        str.assign(s, left, p.size());
        if (isAnagrams(str, p))
            ans.push_back(left);
        left++;
        right++;
    }

    return ans;
}*/

//sliding window
vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size())
        return {};

    vector<int> sCnt(26, 0), pCnt(26, 0);
    vector<int> ans;
    int left = 0, right = 0;

    for (const auto& ch : p) {
        pCnt[ch - 'a']++;
    }

    while (right < s.size()) {
        //sCnt[s[right] - 'a']++;
        if (right - left + 1 == p.size()) {
            if (sCnt == pCnt)
                ans.push_back(left);
            sCnt[s[left++] - 'a']--;
        }
        sCnt[s[right++] - 'a']++;
        //++right;
    }

    return ans;
}

int main(){
    cout<<"test CMake";
    return 0;
}