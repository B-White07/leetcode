//
// Created by B_White on 2024/6/19.
//
// https://leetcode.cn/problems/valid-perfect-square/description/

//和69题算一个数的平方根思路一样，在0-target范围内二分查找就行了
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = num;
        int mid = low + ((high - low) >> 1);

        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if ((long long)mid * mid > num)
                high = mid - 1;
            else if ((long long)mid * mid < num)
                low = mid + 1;
            else
                return true;
        }
        return false;
    }
};