/**
 * Created by B_White on 2025/2/6.
 * https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp(1002, 0);
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i) {
            tmp[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (tmp[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                tmp[nums2[i]]--;
            }
        }
        return result;
    }
};