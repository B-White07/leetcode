/**
 * Created by B_White on 2024/6/28.
 * https://leetcode.cn/problems/move-zeroes/description/
 */
//双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 1)    //nums.empty()
            return;
        int left = 0, right = 0;    //left指向新数组的end()位置，right找新数组的元素
        while (right < nums.size()) {
            if (nums[right] != 0) { //要交换，不能简单覆盖
                int tmp = nums[left];
                nums[left++] = nums[right];
                nums[right] = tmp;
            }
            ++right;
        }
        return;
    }
};