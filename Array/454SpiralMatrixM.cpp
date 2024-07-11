/**
 * Created by B_White on 2024/7/11.
 * https://leetcode.cn/problems/spiral-matrix/description/
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int l = 0, t = 0, r = matrix[0].size() - 1, b = matrix.size() - 1;

        while (1) {
            for (int j = l; j <= r; j++)
                ans.push_back(matrix[t][j]);
            if (++t > b)
                break;
            for (int i = t; i <= b; i++)
                ans.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int j = r; j >= l; --j)
                ans.push_back(matrix[b][j]);
            if (--b < t)
                break;
            for (int i = b; i >= t; --i)
                ans.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return ans;
    }
};