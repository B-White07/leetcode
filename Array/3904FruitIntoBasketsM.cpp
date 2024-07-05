/**
 * Created by B_White on 2024/7/4.
 * https://leetcode.cn/problems/fruit-into-baskets/description/
 */
//滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mmap;   //相当于篮子的容量为2，相同的果树只占用一个空间，用map比较合适，重复数据值保留一份。无序，使用unordered_map更高效
                                        //unordered_map为哈希表，查找可以达到O(1).map是红黑树，时间复杂度O(nlogn)

        int left = 0, ans = 0;  //left指向窗口左边界，ans保存符合条件的窗口的最大长度
        for (int right = 0; right < fruits.size(); ++right) {
            ++mmap[fruits[right]];
            while (mmap.size() > 2) {
                auto it = mmap.find(fruits[left]);
                --it->second;
                if (it->second == 0)
                    mmap.erase(it);
                ++left;
            }
            ans = max(right - left + 1, ans);
        }

        return ans;
    }
};
