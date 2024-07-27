/**
 * Created by B_White on 2024/7/27.
 * https://leetcode.cn/problems/valid-anagram/description/
 */
#include "iostream"
#include "map"

using namespace std;

/*
 * auto it = map.begin(),can't use "const" and "&":const auto& it = map.begin() is false.
 *      and it's usage is it->first and it->second
 * for (const auto& pair : map) is admitted.
 *      pair.first and pair.second
 */
//4 times for loop
//bool isAnagram(string s, string t) {
//    unordered_map<char, int> hs;
//    unordered_map<char, int> ht;
//
//    for (int i = 0; i < s.size(); i++) {
//        hs[s[i]]++;
//    }
//
//    for (int i = 0; i < t.size(); i++) {
//        ht[t[i]]++;
//    }
//
//    bool flag = true;
//    auto it = hs.begin();
//    while (it != hs.end()) {    //notice can't use "it++ != hs.end()" here.
//                                    // cause it will increase immediately after the statement,but the following statement want to use the old one.
//        if (ht.find(it->first) == ht.end() || ht[it->first] != it->second) {
//            flag = false;
//            break;  //the result is false as long as one char's count isn't equally.
//        }
//        ++it;
//    }
//
//    for (const auto& pair : ht) {   //another way to traverse map.
//        if (hs.find(pair.first) == hs.end() ||
//            hs[pair.first] != pair.second) {
//            flag = false;
//            break;
//        }
//    }
//
//    return flag;
//}

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> ans;

    for (auto ch : s) {
        ans[ch]++;
    }

    for (auto ch : t) {
        ans[ch]--;
        if (ans[ch] < 0)    //super intelligent! maybe you would think if s has a char comes up 4 times,but in t,it is 3.so it should be false.
                //but ans[a] will never < 0,so it would never return false!
                //But the comparison is based on the size between s and t is equal.so if a char in a comes up more than it in t,there is always
                    //some other chars in t can result ans[t] < 0.
            return false;
    }

    return true;
}

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    cout << isAnagram(s, t);

    return 0;
}