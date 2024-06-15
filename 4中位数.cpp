/**
 * 描述
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 */

/* 暴力解.lc要求复杂度是对数，太复杂了不管了
 * vector是动态数组，自动分配空间。有点儿类似栈，他很多操作都是只从一端操作的，但比栈更灵活一些，可以访问内部元素。
 * vec.reserve(totalSize)可以给vector预留totalsize的空间
 * vector插入：v.push_back(elem)
 *              insert(const_iterator pos, ele) 指定位置差
 * vector删除：v.pop_back()    删除最后一个元素
 *              erase(const_iterator pos)   指定位置删
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<float> vec;
        int totalSize = nums1.size() + nums2.size();

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        //以下为归并排序，复杂度m+n
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < *it2) {
                vec.push_back(*it1);
                ++it1;
            } else {
                vec.push_back(*it2);
                ++it2;
            }
        }
        //第一个还剩元素
        while (it1 != nums1.end()) {
            vec.push_back(*it1);
            ++it1;
        }
        //第二个还剩元素
        while (it2 != nums2.end()) {
            vec.push_back(*it2);
            ++it2;
        }

        return totalSize % 2 == 0 ? (vec[totalSize/2 - 1] + vec[totalSize/2]) / 2
                                  : vec[totalSize/2];
    }
};
