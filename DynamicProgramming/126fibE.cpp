/**
 * 描述：
 * https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/description/
 */
 //动态规划
/*
 * 动态规划五步：
 *     确定dp数组及下标含义
 *     确定递推公式
 *     dp数组如何初始化
 *     确定遍历顺序
 *     打印dp数组
*/
 class Solution {
 public:
     int fib(int n) {
         if (n < 2)
             return n;

         vector<int> dp(n + 1); // 初始化大小为n+1，否则大小默认为空，下面两行会报错
         dp[0] = 0;
         dp[1] = 1;

         for (int i = 2; i <= n; i++) {
             dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
         }
         return dp[n];
     }
 };
