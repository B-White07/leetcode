/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * 描述：
https://leetcode.cn/problems/add-two-numbers/description/
 *
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr;
        ListNode* h = nullptr;
        int jin = 0;
        while (l1 || l2) {
            int a1 = l1 ? l1->val : 0; // 空的数据用0代替
            int a2 = l2 ? l2->val : 0;
            int sum = a1 + a2 + jin;
            if (h) {
                l3->next = new ListNode(sum % 10);  // 若将sum定义为a1+a2,此处为sum%10,那sum=9而jin=1时会出错
                l3 = l3->next;
            } else {
                h = l3 = new ListNode(sum % 10);
            }

            sum > 9 ? jin = 1 : jin = 0;

            //没处理完的继续处理，处理完的就别动了
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        // 最后还有进位
        if (jin > 0) {
            l3->next = new ListNode(jin);
        }
        return h;
    }
};