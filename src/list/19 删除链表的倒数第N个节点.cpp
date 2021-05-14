
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p = dummy;
        ListNode* pre = dummy;
        while(n--) {
            p = p->next;
        }

        while(p->next != nullptr) {
            pre = pre->next;
            p = p->next;
        }
        
        pre->next = pre->next->next;
        return dummy->next;
    }
};