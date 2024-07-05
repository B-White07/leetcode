/**
 * Created by B_White on 2024/7/4.
 * https://leetcode.cn/problems/fruit-into-baskets/description/
 */
//滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mmap;

        int left = 0, ans = 0;
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
