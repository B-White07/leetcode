/**
* https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/

//先找到元素，再向两边扩散。扩散若表中元素都相同，时间复杂度能达到O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int index;
        int fir = -1, fin = -1; //记录起始位置

        if (nums.size() == 0) { //空数组单独处理
            return {fir, fin};
        }

        while (low <= high) {   //找目标元素
            index = low + ((high - low) >> 1);
            if (nums[index] > target)
                high = index - 1;
            else if (nums[index] < target)
                low = index + 1;
            else
                break;
        }

        if (low > high) //没找到
            return {-1, -1};

        //以下两部最坏情况时间复杂度到达O(n)
        fin = index;    //找到了，向右看还有没有
        while (fin < nums.size() - 1 && nums[fin + 1] == target) {
            ++fin;
        }

        fir = index;    //找到了，向左看还有没有
        while (fir > 0 && nums[fir - 1] == target) {
            --fir;
        }

        return {fir, fin};
    }
};

//两次二分查找，时间复杂度O(n)
/* stl有内置的算法可以实现：
 * lower_bound(nums.begin(), nums.end(),target)；返回第一个大于等于target的迭代器；it != nums.end() && *it == target表示找到了
 * upper_bound(nums.begin(), nums.end(),target); 返回第一个大于target的迭代器；
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = search(nums, target);    //找第一次出现的位置
        int right = search(nums, target + 1);   //找比目标大1第一次出现的位置，若没找到最后也会停在刚好比target大的最小的元素的位置

        if (left == nums.size() || nums[left] != target)    //没找到
            return {-1, -1};

        return {left, right - 1};
    }

private:
    int search(vector<int>& nums, int target) { // 找不小于target的第一个元素
        int low = 0;
        int high = nums.size() - 1;
        int index;

        while (low <= high) {
            index = low + ((high - low) >> 1);
            if (nums[index] < target)
                low = index + 1;
            else
                high = index - 1;   //这里是nums[index] >= target,注意=和>一起处理，这样最后high停在大于等于target的前边，low停在大于等于target的第一个位置
                                        //这一步对=的处理是核心，实现了找到找到大于等于target的第一个位置
        }
        //循环结束可能没找到，也可能找到了

        return low;
    }
};