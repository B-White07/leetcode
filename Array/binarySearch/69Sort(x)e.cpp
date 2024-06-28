//
// https://leetcode.cn/problems/sqrtx/description/
//

//二分查找
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int mid,ans;

        while(low<=high){
            mid = low + ((high - low)>>1);
            if((long long)mid*mid > x)  //转成long long防止溢出
                high = mid -1;
            else{   //这里一起处理 < 和 = 的逻辑，因为目的其实是找到一个最大的满足条件的数。和t34的思想类似。
                low = mid +1;
                ans = mid;  //当前的满足，记下来，找到更大的满足条件的再更新。
            }
        }
        return ans;
    }
};

//牛顿迭代法