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

    vector<int> sCnt(26, 0), pCnt(26, 0);   //count how many times different letters comes up
    vector<int> ans;    //store answer
    int left = 0, right = 0;    //window's border

    for (const auto& ch : p) {  //count times different letters appear in p
        pCnt[ch - 'a']++;   //'a' - 'a' == 0; 'b' - 'a' == 1
    }

    while (right < s.size()) {
        sCnt[s[right] - 'a']++;
        if (right - left + 1 == p.size()) { //if size of window is equal to p,judge if they are anagram
            if (sCnt == pCnt)
                ans.push_back(left);
            sCnt[s[left++] - 'a']--;    //only the size of window and p is equal,left need move.and corresponding letter's times should -1
        }
//        sCnt[s[right++] - 'a']++;
        ++right;    //every time the right should move.
    }

    return ans;
}

int main(){
    cout<<"test CMake";
    return 0;
}