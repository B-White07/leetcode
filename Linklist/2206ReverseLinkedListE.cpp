/**
 * Created by B_White on 2024/7/17.
 * https://leetcode.cn/problems/reverse-linked-list/description/
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
 //头插法逆置链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* h = new ListNode(0, head);    //你个头节点，方便操作
        ListNode* cur = head->next; //当前要头插的节点
        ListNode* f = head; //逆置后的链表的表尾
        while (cur != nullptr) {
            f->next = cur->next;
            cur->next = h->next;
            h->next = cur;
            if (f->next == nullptr) //已逆置的链表的后边没元素了，说明已经完成了全部逆置
                return h->next;
            cur = f->next;  //否则继续处理下一个
        }

        head = h->next;
        delete h;   //释放掉头节点的空间
        h = nullptr;    //防野指针

        return head;
    }
};