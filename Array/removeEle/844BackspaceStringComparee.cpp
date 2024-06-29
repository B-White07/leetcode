/**
 * Created by B_White on 2024/6/29.
 * https://leetcode.cn/problems/backspace-string-compare/description/
 */
//分别处理两个数组，然后比较是否相等
//注意边界的处理，当新数组没有元素时，left指向0，不能再-1了，否是数组越界
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int left = 0, right = 0;    //left指向新数组end()位置，right找新数组的元素

        while (right < s.size()) {
            if (s[right] != '#')    //若right不指向退格，则新元素进数组
                s[left++] = s[right++];
            else {  //right指向退格
                if (left == 0) {        //此时新数组没有元素，
                    s.erase(left, 1);   //删除旧数组的第一个元素，其实就是删除多余的退格
                    right = left;       //两个指针重新指向起点，这个起点即是新数组的起点，也是旧数组的起点
                } else {
                    s.erase(left - 1, 2);   //此时新数组还有元素，就删掉最后一个元素
                    --left;             //重新指向新数组end()
                    right = left;
                }
            }
        }

        left = 0;
        right = 0;
        while (right < t.size()) {  //同样逻辑处理第二个数组
            if (t[right] != '#')
                t[left++] = t[right++];
            else {
                if (left == 0) {
                    t.erase(left, 1);
                    right = left;
                } else {
                    t.erase(left - 1, 2);
                    --left;
                    right = left;
                }
            }
        }

        if (s == t)
            return true;
        return false;
    }
};

//利用栈的特性处理
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return rebuild(s) == rebuild(t);
    }

    string rebuild(string s) {
        string ans; //用一个新的字符串记录最后的结果
        for (char ch : s) {
            if (ch != '#')
                ans.push_back(ch);  //使用栈的特性
            else {
                if (!ans.empty())
                    ans.pop_back();
            }
        }
        return ans;
    }
};

//双指针
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1; //从末尾开始对比，指向当前的非'#'字符
        int ss = 0, ts = 0; //分别记录本次检查到了几个'#'

        while (i >= 0 || j >= 0) {  //while是当前字符不相同的逻辑，条件是||,若为&&,则"bbbextm"  "bbb#extm"会得到true而正确结果是false
                                    //若为&&,则跳出循环的条件只需要有一个<0,而此时另一个是可能>=0的，此时表示二者不相等了，而跳出循环表示相等
            while (i >= 0) {
                if (s[i] == '#') {
                    ++ss, --i;
                } else if (ss > 0)
                    --ss, --i;
                else
                    break;
            }

            while (j >= 0) {    //单独处理每个字符串，找当前可比较的元素，即不应该被删掉的非'#'字符
                if (t[j] == '#') {
                    ++ts, --j;  //扫描到'#'，记录下来，指针往前移
                } else if (ts > 0)  //扫描到非'#'，但是该字符需要删掉
                    --ts, --j;
                else
                    break;  //扫描到非'#'，且该字符不需要删掉，则用该字符和另一个字符串做比较
            }

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])   //都没遍历完而且当前字符不等，说明字符串不想等
                    return false;
            } else {    //有一个已经遍历完了
                if (i >= 0 || j >= 0)   //此时只要另一个还没遍历完，则二者不想等
                    return false;
            }

            //当前字符相等，且都没有遍历完
            --i, --j;
        }

        return true;    //都遍历完了，而且过程中没发现不想等，则相等
    }
};