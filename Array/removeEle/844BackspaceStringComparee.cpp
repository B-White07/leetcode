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

