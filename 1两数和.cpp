/**
描述：
https://leetcode.cn/problems/two-sum/description/
*/


#include <iostream>
#include <vector>

using namespace std;

//暴力解n^2
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i, j;
        for (i = 0; i < nums.size() - 1; i++) { //vector.size()返回容器的长度
            for (j = i + 1; j < nums.size(); j++) { //数组中同一个元素在答案里不能重复出现：就是自己不能和自己相加，因此j要从i的下一个位置开始
                if (nums[i] + nums[j] == target) {
                    return {i,j};  //C++11新特性，将{}中的内容转换成相应的对象返回，如这里将i,j构造成vector对象返回
                }
            }
        }
        return {};  //返回空的vector<int>对象
    }
};

//哈希表n
/* begin()和end()都是迭代器，分别指向容器第一个位置和最后一个位置的下一个位置。迭代器可以暂时理解为指针
 * m.first就是m的key,m.second就是vlaue
 * map插入：可以用pair
 *              也可以用map[key]=value的方式，map[key]=value也可以用于访问key的value
 * map删除：m.erase(m.begin()) 删除第一个元素
 *              m.erase(key)    按照key删除
 *              m.erase(m.begin(),m.end())  按照区间删，这其实就是清空了，等价于m.clear()
 * map查找：m.find(key)    若key存在，返回该key的迭代器；若不存在，返回m.end()
 * map计数：m.count(key)   统计key的次数，只能是0或1，因为map不允许重复的key.mulmap允许重复
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;   //unorder_map是无序的哈希表，map是有序的哈希表
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(target - nums[i]);
            if (it == hash.end())
                hash.insert(pair<int, int>(nums[i], i));    //insert插入需要用pair<>的方式插入键值对
            else
                return {it->second, i};
        }
        return {};
    }
};