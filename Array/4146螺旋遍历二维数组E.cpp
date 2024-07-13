/**
 * Created by B_White on 2024/7/13.
 * https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/
 */
//和54题一样

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if (array.empty())
            return {};
        vector<int> ans;

        int l = 0, r = array[0].size() - 1, t = 0, b = array.size() - 1;

        while (true) {
            for (int j = l; j <= r; j++)
                ans.push_back(array[t][j]);
            if (++t > b)
                break;
            for (int i = t; i <= b; i++)
                ans.push_back(array[i][r]);
            if (--r < l)
                break;
            for (int j = r; j >= l; j--)
                ans.push_back(array[b][j]);
            if (--b < t)
                break;
            for (int i = b; i >= t; i--)
                ans.push_back(array[i][l]);
            if (++l > r)
                break;
        }

        return ans;
    }
};