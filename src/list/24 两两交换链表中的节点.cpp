
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* p = head, *q = head;

        while(p != nullptr) {
            q = p->next;
            if(q == nullptr) {
                break;
            }
            ListNode* rear = q->next;
            pre->next = q;
            q->next = p;
            p->next = rear;

            pre = p;
            p = q = rear;
        }
        return dummy->next;
    }
};