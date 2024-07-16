/**
 * Created by B_White on 2024/7/16.
 * https://leetcode.cn/problems/design-linked-list/description/
 */
/*
 * 注意链表和节点不一样，链表由节点组成
 * 节点应该有的属性是值和next指针；链表应该有的属性应该是头指针和链表大小（默认单链表）
 */
struct LinkNode {   //链表中的每个节点
    int val;
    LinkNode* next;
    LinkNode(int val) : val(val), next(nullptr) {}  //结构体也可以使用初始化列表
};

class MyLinkedList {    //链表
private:
    int size;   //链表大小
    LinkNode* head; //这里初始化一个带头节点的单链表，head指向头节点

public:
    MyLinkedList() {    //如果提供有参构造，那么无参构造就会被覆盖掉，想使用必须显示定义
        size = 0;
        head = new LinkNode(0);
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        LinkNode* cur = head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkNode* cur = new LinkNode(val);
        cur->next = head->next;
        head->next = cur;
        ++size;
    }

    void addAtTail(int val) {
        LinkNode* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new LinkNode(val);
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;

        LinkNode* cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;

        LinkNode* newNode = new LinkNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        LinkNode* cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        LinkNode* tmp = cur->next;  //用tmp记录被删掉的节点，需要释放掉
        cur->next = tmp->next;
        delete tmp; //这会释放掉tmp指向的内存空间，但并不会释放掉tmp本身，tmp会随机指向一个地方
        tmp == nullptr; //所以要将tmp置空，防止野指针
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */