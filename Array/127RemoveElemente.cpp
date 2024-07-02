//
// Created by B_White on 2024/6/19.
//
//  https://leetcode.cn/problems/remove-element/description/
/*
 * algorithm库常用函数：
 *      find()
 *      remove()
 *
 * iterator库：使用迭代器
 *
 * 删除数组是逻辑上的删除，而且删以后要把后边的元素往前移动保证删除元素后的数组空间连续
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(),nums.end(),val);  //remove是一种逻辑上的删除，只是将val放到容器的末尾，返回新的容器的结尾的迭代器。
        nums.erase(it,nums.end());  //删除目标元素，erase()时间复杂度是O(n),本题其实就是erase的实现
        return nums.size(); //大小就是个数了
    }
};

//暴力解,超时了
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < nums.size(); j++)   //从i的下一个位置开始移动元素
                    nums[j - 1] = nums[j];  //若上一行初始化为j=i,那这里需要nums[j] = nums[j+1],这会导致j=size-1时，nums[j+1]越界
                --i;    //此时的i指向移动后的第一个元素，这个元素还没判断是不是要删除的元素，所以要往回指一下
                ++ans;
            }
        }
        return nums.size() - ans;
    }
};

/*
 * 双指针，O(n)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;    //right找要新数组的元素，left是删除掉目标元素以后的新数组的末位置
        while (left < nums.size() && right < nums.size()) {
            if (nums[right] != val)
                nums[left++] = nums[right]; //初始l和r均为0，此处不会使数组变化；以后运行到这了表示找到了不等于要删除的元素的下一个元素
                                            //left仅在删除了目标元素以后才往后走
            ++right;    //right始终往后走
        }
        /*
        while (left < nums.size() && right < nums.size()) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                ++left;
                ++right;
            } else {
                ++right;
            }
        }
         */
        return left;
    }
};

