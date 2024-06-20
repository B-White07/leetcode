//
// Created by B_White on 2024/6/19.
//
//  https://leetcode.cn/problems/remove-element/description/
/*
 * algorithm库常用函数：
 *      find
 *      remove
 *
 * iterator库：使用迭代器
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(),nums.end(),val);  //remove是一种逻辑上的删除，只是将val放到容器的末尾，返回新的容器的结尾的迭代器。
        nums.erase(it,nums.end());  //删除目标元素
        return nums.size(); //大小就是个数了
    }
};


