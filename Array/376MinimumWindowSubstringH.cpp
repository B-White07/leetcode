/**
 * Created by B_White on 2024/7/7.
 * https://leetcode.cn/problems/minimum-window-substring/description/
 */
//滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";

        unordered_map<char, int> ht; // 目标字符出现的次数
        for (auto it : t) {
            ++ht[it];
        }
        int match = 0; // 匹配的字符数

        unordered_map<char, int> hs; // 记录当前窗口内各字符数量

        int left = 0;   //左窗口
        int start = 0, ans = INT32_MAX; //最终窗口的起点和大小

        for (int right = 0; right < s.size(); ++right) {
            // 始终都在延窗口
            ++hs[s[right]];
            if (ht.count(s[right]) && hs[s[right]] == ht[s[right]]) //写成hs[s[right]] == ht[s[right]] && ht.count(s[right])有问题，永远不满足条件
                                                                //实际上逻辑应该就是这样的，先判断有没有，再判断有几个
                ++match;

            // 满足条件时缩窗口
            while (match == ht.size()) {
                if (ans > right - left + 1) {   //记录最终窗口大小和起始位置
                    start = left;
                    ans = right - left + 1;
                }

                if (ht.count(s[left])) {    //移除的是目标字符
                    --hs[s[left]];
                    if (hs[s[left]] < ht[s[left]])
                        --match;
                }

                ++left; //缩窗口
            }
        }

        if (ans == INT32_MAX)
            return "";
        else
            return s.substr(start, ans);
    }
};