/**
 * Created by B_White on 2024/7/19.
 * https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
  * 注意对这道题的理解，交叉节点的意思是，如果两个链表有交叉节点，那么这两个链表从交叉节点往后的节点是共用的。指针指向同一内存空间
  * 注意交叉节点不是值相同的第一个节点
  */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB)
            return nullptr;

        ListNode* cura = headA;
        ListNode* curb = headB;

        int sizea = 0;  //链表A的大小
        while (cura) {
            cura = cura->next;
            sizea++;
        }

        int sizeb = 0;  //链表B的大小
        while (curb) {
            curb = curb->next;
            sizeb++;
        }

        cura = headA;
        curb = headB;

        int dis = sizea > sizeb ? sizea - sizeb : sizeb - sizea;

        if (sizea >= sizeb) {   //长度大的链表想往前走，走到和长度小的链表一样长
            while (dis--)
                cura = cura->next;
        } else {
            while (dis--)
                curb = curb->next;
        }

        while(cura && curb){    //往后找交叉点
            if(cura == curb)
                return cura;
            cura = cura->next;
            curb = curb->next;
        }

        return nullptr;
    }
};