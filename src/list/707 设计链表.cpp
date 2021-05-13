



class MyLinkedList {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new ListNode();
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= len)
            return -1;
        ListNode* p = dummy->next;
        while(index--) {
            p = p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = dummy->next;
        dummy->next = tmp;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *tmp = new ListNode(val);
        ListNode* p = dummy;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > len)
            return;
        if(index < 0)
            addAtHead(val);
        else if(index == len)
            addAtTail(val);
        else {
            ListNode* p = dummy;
            while(index--) {
                p = p->next;
            }
            ListNode* tmp = new ListNode(val);
            tmp->next = p->next;
            p->next = tmp;
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len || index < 0)
            return;
        ListNode *p = dummy;
        while(index--) {
            p = p->next;
        }
        p->next = p->next->next;
        len--;
    }

private:
    ListNode* dummy;
    int len;
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