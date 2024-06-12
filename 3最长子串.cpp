/**
* 描述：
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
*/
//暴力解
/*
 * set<>：1数据插入时自动排序
 *      2不允许插入重复值
 * 大小：s.size()
 * 判空：s.empty()
 * 交换：s1.swap(s2)   交换两个set
 * 插入：s.insert(value)   pair<set<int>::iterator,bool> ret = s.insert(value) 返回pair，说明插入位置和是否插入成功
 * 删除：s.clear()清除所有     s.erase(it)删除迭代器所指位置    s.erase(begin,end)删除区间，返回下一个元素的迭代器  s.erase(value)按值删
 * 查找：s.find(value) 返回元素的迭代器
 * 统计：s.count(value)    只能是0/1
 *
 *
 * multiset<>：可以查重复的值
 * pair<type,type> p    创建对组，p.first p.second 访问第一个和第二个元素
 */
#include <iostream>;
#include "map";

using namespace std;

//暴力解
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        set<char> str;  //装子串
//        int max = 0;    //记录最大子串长度
//
//        for (int i = 0; i < s.size(); i++) {
//            for (int j = i; j < s.size(); j++) {
//                if (str.find(s[j]) == str.end())    //不是重复字符就加入子串
//                    str.insert(s[j]);
//                else
//                    break;  //是重复字符，本趟结束，即找到了一个不重复的子串
//            }
//            str.size() > max ? max = str.size() : max;  //看看子串长度
//            str.clear();    //清空以便保存下一个子串
//        }
//        return max;
//    }
//};

//滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_map<char, int> um;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (um.find(s[i]) == um.end()) {
                um.insert(pair<char, int>(s[i], i));
            } else {
                left = um[s[i]] + 1;
                um.insert(pair<char, int>(s[i], i));
                um.size() - left + 1 > max ? max = um.size() - left + 1 : max;
            }
        }
        um.size() - left + 1 > max ? max = um.size() - left + 1 : max;
        return max;
    }
};

