/**
 * 描述
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 */

#include <iostream>
#include "vector"

using namespace std;

//暴力解，效率太低了，过不了lc所有测试
/*string longestPalindrome(string s) {
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
}*/

//动态规划dp
/*
 * 动态规划五步：
 *      确定dp数组及下标含义
 *      确定递推公式
 *      dp数组如何初始化
 *      确定遍历顺序
 *      打印dp数组
 */
string longestPalindrome(string s) {
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));  //初始化dp数组，默认所有串都不是回文串
    int begin = 0;  //记录最长回文长起点
    int maxlen = 0; //记录最长回文串长度

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++) {    //遍历dp数组，需要根据最下角的值来确定当前值，因此遍历顺序应该从最左下角开始，并且根据实际意义，j应该大于i.
            if (s[i] == s[j]) { //当前字符相等，下面取决于两字符之间的是不是回文串
                if (j - i < 3)  //长度小于3，一定是
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];    //中间是就是，中间不是我也不是
            }

            if (dp[i][j] && j - i + 1 > maxlen) {   //如果当前串是回文串，记录长度
                begin = i;
                maxlen = j - i + 1;
            }
        }
    }
    return s.substr(begin, maxlen);
}

int main() {
    cout << longestPalindrome("babad");
    return 0;
}