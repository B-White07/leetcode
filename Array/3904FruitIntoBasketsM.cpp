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
            ++mmap[fruits[right]];  //以fruits[right]作为键，找到同类型的树就将对应的值++
            while (mmap.size() > 2) {   //篮子满了，需要腾一个空位，即移除一个类型
                auto it = mmap.find(fruits[left]);  //找到左窗口的类型，并移除。注意每次移除的可能不是同一种类型
                --it->second;
                if (it->second == 0)    //如果这次移除了以后导致其值为0，表示该类型在篮子中已经没有了
                    mmap.erase(it); //删掉他，篮子增加一个空位
                ++left; //注意left指向的一直是窗口左边，因此每次--的可能不是同一种类型
            }
            ans = max(right - left + 1, ans);   //记录窗口最大值
        }

        return ans;
    }
};
