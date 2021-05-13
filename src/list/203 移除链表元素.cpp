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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* p = dummy;
        while(p->next != nullptr) {
            if(p->next->val == val) {
                p->next = p->next->next;
                
                // ListNode *tmp = p->next;
                // p->next = tmp->next;
                // free(tmp);
            }
            else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};