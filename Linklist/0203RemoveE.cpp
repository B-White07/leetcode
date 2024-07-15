/**
 * Created by B_White on 2024/7/15.
 *https://leetcode.cn/problems/remove-linked-list-elements/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head, *q = head;  //p指向当前元素，q指向p前边的一个元素

        while (head != nullptr && head->val == val) {   //看被删除的元素是不是头指针所指元素
            p = head->next;
            q = p;
            head = p;
        }

        if (head == nullptr)    //如果是头指针所指看删完以后表空没空或者这个表本身就是空的
            return head;

        while (p != nullptr) {  //不是上述两种情况，就删除制定元素
            while (p->val != val) { //找制定元素
                q = p;
                p = p->next;
                if (p == nullptr)
                    return head;
            }
            q->next = p->next;
            p = p->next;
        }
        return head;
    }
};