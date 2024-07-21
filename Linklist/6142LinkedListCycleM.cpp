/**
 * Created by B_White on 2024/7/21.
 * https://leetcode.cn/problems/linked-list-cycle-ii/description/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这类链表题目一般都是使用双指针法解决的，例如寻找距离尾部第 K 个节点、寻找环入口、寻找公共尾部入口等

class Solution {
    /*
     * say the distance between the list's head and the entry of the circle is x.
     * the dis between the entry and the meet point is y.the dis between tht meet point and the entry is z.
     * x,y,z meet the equation:
     * 2(x+y) = (x+y) + n(y+z)
     * x = (n-1)(y+z) + z
     * n is the number of how many times the faster traverse the circle,n>=1
     * and it turns out that,x=z all the time
     * so after the fast and the slow meet at the first,let the fast go from the head again at the speed of 1 unit,they will meet at the entry again.
     */
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* fast = head;  //move 2 units at first
        ListNode* slow = head;  //move 1 unit
                                //given this,if the list has a circle,the fast pointer will meet the slow pointer in a cycle.
                                // in another word,the slow won't go through the circle more than once

        while (true) {
            if (fast == nullptr || fast->next == nullptr)   //indicate there is not circle
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)   //first meet
                break;
        }

        fast = head;    //then the fast pointer move 1 unit also.

        while (fast != slow) {  //when they meet again,the point is the entry of the circle
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};