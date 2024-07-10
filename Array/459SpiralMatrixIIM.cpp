/**
 * Created by B_White on 2024/7/10.
 */
//O(n^2)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int startx = 0, starty = 0; //每层循环的起点坐标
        int lap = 0, offset = 1;    //lap记录循环多少圈，offset相当于记录右边开区间的位置
        int cnt = 1;    //1-n^2
        while (lap < (n / 2)) {
            //以下分别left->right,top->bottom,right->left,bottom->top
            for (int j = starty; j < n - offset; ++j)
                ans[startx][j] = cnt++;
            for (int i = startx; i < n - offset; ++i)
                ans[i][n - offset] = cnt++;
            for (int j = n - offset; j > starty; --j)
                ans[n - offset][j] = cnt++;
            for (int i = n - offset; i > startx; --i)
                ans[i][starty] = cnt++;

            ++lap, ++startx, ++starty, ++offset;
        }
        if (n % 2 == 1) //奇数最中间的元素单独填充一下
            ans[n / 2][n / 2] = n * n;
        return ans;
    }
};

