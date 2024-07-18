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
        if (head == nullptr)
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

//双指针：从第一个节点开始，以此将节点的指针指向前边的节点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;   //当前要变换指针的节点
        ListNode* pre = nullptr;    //cur要指向的元素，其实是链表头
        ListNode* tmp = cur;    //记录cur下一个节点的位置

        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre; //pre就是新链表的第一个节点
    }
};

//递归：递归和while循环是有对应关系的：循环体内做的事情就是单次递归要做的事情+传递下次递归参数。递归出口就是循环判断条件
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) //递归出口
            return pre;

        //每次递归做的事：首先记录cur下一个节点的位置；然后将cur的指针指向pre，这就是每次递归内做的所有事情。而更新pre和cur的位置应该作为下次递归的参数传递
        ListNode* tmp = cur->next;
        cur->next = pre;

        //更新下次递归的参数
        return reverse(cur, tmp);
    }


    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);  //初始化递归参数：初始pre为null,cur为head
    }
};

//递归，不创建新函数
/*
 * 1 -> 2 -> 3 -> 4 -> 5
 * |   stack top  |
 * | head=nullptr |
 * |    head=5    | 5
 * |    head=4    | 4
 * |    head=3    | 3
 * |    head=2    | 2
 * |    head=1    | 1
 * | stack bottom |
 *
 * 1st pop:head == 5;
 * 5: return 5;
 *
 * 2nd pop:head == 4;
 * 4:newHead = 5;
 * 4:1->2->3->4<->5newHead
 * 4:1->2->3->4<-5newHead
 * 4:return 5;
 *
 * 3rd pop:head == 3;
 * 3:newHead = 5;
 * 3:1->2->3<->4<-5newHead
 * 3:1->2->3<-4<-5newHead
 * 3:return 5;
 *
 * 4nd pop:head == 2;
 * 2:newHead = 5;
 * 2:1->2<->3<->4<-5newHead
 * 2:1->2<-3<->4<-5newHead
 * 2:return 5;
 *
 * 5nd pop:head == 1;
 * 1:newHead = 5
 * 1:1<->2<-3<-4<-5newHead
 * 1:1<-2<-3<-4<-5newHead
 * 1:return 5;
 *
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)   //递归出口
            return head;

        ListNode* newHead = reverseList(head->next);    //保存新的头节点，其实就是原链表的尾节点
        head->next->next = head;
        head->next = nullptr;

        return newHead; //返回新链表的头节点
    }
};