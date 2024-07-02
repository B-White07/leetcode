//
// Created by B_White on 2024/6/25.
//
/*
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
 */
//双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1, right = 1;    //left表示新数组的end()位置，初始化为1表示默认有一个元素，因为只有一个元素不会重复。
                                    //right用来找新数组的元素，从第二个位置开始
        while (right < nums.size()) {
            if (nums[left - 1] != nums[right])    //right要和新数组的最后一个元素对比，不一样就放进数组。新数组的最后一个元素是left-1不是left
                nums[left++] = nums[right];
            ++right;    //排除掉和新数组最后一个元素相同的元素
        }
        return left;
    }
};