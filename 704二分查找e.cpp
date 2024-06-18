/**
* 描述：
 * https://leetcode.cn/problems/binary-search/description/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int index = low + (high - low) / 2;//避免溢出，效果等同于index=(low+high)/2
            if (nums[index] < target) {
                low = index + 1;
            } else if (nums[index] > target) {
                high = index - 1;
            } else
                return index;
        }
        return -1;
    }
};