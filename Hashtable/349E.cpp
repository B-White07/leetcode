/**
 * Created by B_White on 2025/2/6.
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        unordered_set<int> mySet;
        for (int i = 0; i < nums1.size(); ++i)
            mySet.insert(nums1[i]);

        for (int i = 0; i < nums2.size(); ++i) {
            // c++中的find(起始位置，终止位置，目标值)方法，未找到返回迭代器.end()
            if(mySet.end() != mySet.find(nums2[i]) && result.end() == std::find(result.begin(),result.end(),nums2[i]))
                result.push_back(nums2[i]);
        }

        return result;
    }
};
