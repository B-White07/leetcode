/**
 * Created by B_White on 2025/2/6.
 * https://leetcode.cn/problems/ransom-note/description/
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool flag = true;
        unordered_map<char, int> frq_map;
        for (int i = 0; i < ransomNote.size(); ++i) {
            frq_map[ransomNote[i]]++; //map中无键值对时，第一次访问该键会默认分配一个值，int类型默认为0，因此此处没问题
        }
        for (int i = 0; i < magazine.size(); ++i) {
            if (frq_map.end() != frq_map.find(magazine[i])) {
                frq_map[magazine[i]]--;
            }
        }
        for (auto it = frq_map.begin(); it != frq_map.end(); ++it) {
            if (it->second > 0)
                flag = false;
        }
        return flag;
    }
};