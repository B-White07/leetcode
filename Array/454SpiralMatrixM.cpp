/**
 * Created by B_White on 2024/7/11.
 * https://leetcode.cn/problems/spiral-matrix/description/
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int l = 0, t = 0, r = matrix[0].size() - 1, b = matrix.size() - 1;
        //注意这四个是边界，l=0表示当前应该处理[i][0]的元素 r=n-1表示当前应该处理[i][n-1].t和b同理

        while (1) {
            for (int j = l; j <= r; j++)
                ans.push_back(matrix[t][j]);
            if (++t > b)    //t=b，此时上下边界相等，表示以此为边界的所有元素还没有处理，应该被处理
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