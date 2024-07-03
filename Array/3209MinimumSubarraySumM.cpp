/**
 * Created by B_White on 2024/7/2.
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
 */
 //本题需要注意，子数组，子串都是连续的，子序列是可以不连续的。因此本题不能先将数组降序排序再找

 //滑动窗口
 class Solution {
 public:
     int minSubArrayLen(int target, vector<int>& nums) {
         int left = 0, sum = 0, ans = nums.size() + 1;// left记录窗口左端，sum记录当前窗口内的元素和
                                                // ans记录满足条件的窗口的最小值。初始化为nums.size() + 1而不是nums.size()
                                                // 是为了防止出现整个数组的和都小于target时，仍返回nums.size()的错误结果，其实也可以初始化为INT32_MAX

         for (int right = 0; right < nums.size(); ++right) {    //right记录窗口右端
             sum += nums[right];    //每次循环都先计算当前窗口的元素和

             while (sum >= target) {    //每次循环都先判断当前窗口是否满足要求，如果满足要求就从左端缩小窗口，否则就从右侧增大窗口
                 ans > right - left + 1 ? ans = right - left + 1 : ans; //保留满足条件的最小的窗口
                 sum -= nums[left++];   //缩小窗口并重新计算下一个窗口的元素和
             }
         }

         return ans == nums.size() + 1 ? 0 : ans;   //ans没被改动过说明所有窗口都不满足，返回0.否则就是有满足条件的窗口。
     }
 };