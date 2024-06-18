/**
* 描述：
 * https://leetcode.cn/problems/search-insert-position/description/
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int index = low + (high - low) / 2; //防止low+high潜在的溢出问题

        while (low <= high) {
            index = low + ((high - low) >> 1);  //>>1右移一位，等价于/2
            if (nums[index] > target)
                high = index - 1;
            else if (nums[index] < target)
                low = index + 1;
            else
                return index;
        }
        return low; //最后停在low=high+1
    }
};