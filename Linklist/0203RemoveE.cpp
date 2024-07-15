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

//添加一个头节点，这样原头节点就可以和普通节点一样处理
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode(0, head);    //新添加一个头节点
        ListNode *p = h, *q = h;

        while (p != nullptr) {
            while (p->val != val) {
                q = p;
                p = p->next;
                if (p == nullptr)
                    return h->next;
            }
            q->next = p->next;
            p = p->next;
        }
        return h->next;
    }
};

//递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)    //递归出口
            return head;

        head->next = removeElements(head->next,val);

        if (head->val == val)   //头节点值为val，则返回下一个节点
            return head->next;
        else
            return head;

    }
};