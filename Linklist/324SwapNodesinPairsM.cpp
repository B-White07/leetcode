/**
 * Created by B_White on 2024/7/18.
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* nhead = new ListNode(0, head);    //新建个头节点
        ListNode* cur = head;   //每次交换cur和cur->next
        ListNode* pre = nhead;  //方便交换，记录cur前边的指针

        while (cur && cur->next) {  //cur为空自然不必继续交换了；cur->next为空则只剩cur，也不必交换了
            ListNode* tmp = cur->next->next;    //记录下一次cur的位置
            //交换节点
            cur->next->next = cur;
            pre->next = cur->next;
            cur->next = tmp;

            pre = cur;  //当前的cur就是下一次的pre
            cur = tmp;  //cur前移
        }

        head = nhead->next;
        delete nhead;   //new的要delete
        nhead = nullptr;    //不能nhead->next;这是非法的

        return head;
    }
};

//递归

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)   //空链表或者递归到只剩一个节点，则退出递归
            return head;

        ListNode* nhead = head->next;
        head->next = swapPairs(nhead->next);
        nhead->next = head;
        return nhead;
    }
};
