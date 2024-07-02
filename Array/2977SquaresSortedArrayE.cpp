/**
 * Created by B_White on 2024/7/1.
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 */

//暴力解，先赋值再排序
//有排序，最快也得nlogn
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;

        vector<int> ans;    //ans是空的，但是过程中需要多次申请、分配内存，性能不如下边的
        //vector<int> ans(nums.size()); // 初始化ans的大小与nums相同，这样下边才可以用ans[i]
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i] * nums[i]);   //用push_back()就避免了ans[i]的越界错误，因为上边的ans是空的，不能用ans[i]
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

//双指针
//只需要遍历一边数组，O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;

        vector<int> ans(nums.size());
        int index = nums.size() - 1;    //从最后一个位置开始放

        for (int i = 0, j = nums.size() - 1; i <= j;) { //i=j的时候是最后一个元素，也要处理，放到新数组中。    for的第三部分可以为空
            if (nums[i] * nums[i] < nums[j] * nums[j]) {    //哪个大把哪个放进新数组
                ans[index] = nums[j] * nums[j];
                --j;
            } else {
                ans[index] = nums[i] * nums[i];
                ++i;
            }
            --index;
        }

        return ans;
    }
};

