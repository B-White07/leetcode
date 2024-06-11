/*
描述：
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]


get:
vector.size()返回容器的长度

*/


#include <iostream>
#include <vector>

using namespace std;

//暴力解
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i, j;
        for (i = 0; i < nums.size() - 1; i++) {
            for (j = i + 1; j < nums.size(); j++) { //数组中同一个元素在答案里不能重复出现：就是自己不能和自己相加，因此j要从i的下一个位置开始
                if (nums[i] + nums[j] == target) {
                    return {i,j};  //C++11新特性，将{}中的内容转换成相应的对象返回，如这里将i,j构造成vector对象返回
                }
            }
        }
        return {};  //返回空的vector<int>对象
    }
};

//哈希表