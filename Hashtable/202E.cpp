/**
 * Created by B_White on 2025/2/6.
 * https://leetcode.cn/problems/happy-number/description/
 */
//注意题目描述，结果只有 无限循环 和 1 这两种情况，所以他一定会循环，想哈希表
//有时间可以再想一下怎么证明必循环而不是无限不循环：sum只要重复出现过1次，那么接下来的所有的便都是循环的，因此判断是否无限循环只需要判断是否重复出现过一次即可

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> result;
        while (1) {
            int sum = 0;
            while (n / 10 != 0) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            sum += n * n; //最后只剩个位数的时候还需要一次处理
            n = sum;

            if (sum == 1)
                return true;
            else if (result.end() == result.find(sum))
                result.insert(sum);
            else
                return false;
        }
    }
};
