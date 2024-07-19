/**
 * Created by B_White on 2024/7/19.
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;   //size of list
        ListNode* vhead = new ListNode(0, head);    //virtual head
        ListNode* cur = head;   //point to the node need to delete and calculate the size of the list

        while (cur) {   //calculate list's size
            cur = cur->next;
            ++size;
        }

        int idx = size - n + 1; //the index from the begin of the node need to be delated
        cur = head; //point to the target
        ListNode* pre = vhead;  //previous node of the target

        while (--idx) { //let cur point to the target
            pre = pre->next;
            cur = pre->next;
        }

        pre->next = cur->next;  //delete target node

        ListNode* tmp = new ListNode(0, cur);   //free the space of the target node
        delete tmp;
        tmp = nullptr;

        head = vhead->next;
        delete vhead;   //free vhead
        vhead = nullptr;

        return head;
    }
};