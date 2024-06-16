/**
 * 描述
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 */

#include <iostream>
#include "vector"

using namespace std;

//暴力解，效率太低了，过不了lc所有测试
string longestPalindrome(string s) {
    string s1 = "";
    string s2 = "";
    int index = 0, maxlen = 0;
    vector<string> vec;

    for (int i = 0; i < s.size(); i++) {
        s1.clear();
        for (int j = i; j < s.size(); j++) {
            s1 += s[j];
            s2 = s1;
            reverse(s1.begin(), s1.end());
            if (s2 == s1) {
                vec.push_back(s1);
            } else {
                reverse(s1.begin(), s1.end());
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].size() > maxlen) {
            maxlen = vec[i].size();
            index = i;
        }
    }

    return vec[index];
}

//动态规划dp
/*
 * 动态规划五步：
 *      确定dp数组及下标含义
 *      确定递推公式
 *      dp数组如何初始化
 *      确定遍历顺序
 *      打印dp数组
 */
int main() {
    cout << longestPalindrome("ccc");
    return 0;
}