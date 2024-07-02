/**
 * 描述：
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
*/
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
/*
 * multiset<>：可以查重复的值
 * pair<type,type> p    创建对组，p.first p.second 访问第一个和第二个元素
 * max(value1,value2)   返回最大值，注意不要起和函数名字一样的变量名
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int maxlen = 0,left = 0;    //left记录窗口左端位置
        int i =0;   //记录窗口末端位置

        for (i = 0; i < s.size(); i++) {
            if (um.find(s[i]) != um.end()) {    //map中有当前字符，说明窗口中的子串已经最大，要找下一个了
                maxlen = max(i - left, maxlen);     //记录当前子串的最大长度
                left = max(left, um[s[i]]+1);       //将窗口左端往后移。若仅left = um[s[i]] + 1,会导致left回溯，因此应取较大值。
            }
            um[s[i]] = i;   //若当前字符是重复字符，就修改其value值；若不是重复字符，就将其插入map
                                //若使用insert函数，有重复字符的时候插入不成功，还得删了再插，不如这个一举两得。
        }
        maxlen = max(i - left, maxlen); //走到最后若是不重复的，需要再计算一下窗口大小。
        return maxlen;
    }
};

