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


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* p = nullptr, *pre = head;
//         while(pre != nullptr) {
//             ListNode* tmp = pre->next;
//             pre->next = p;
//             p = pre;
//             pre = tmp;
//         }
//         return p;
//     }
// };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* p = head->next;
        head->next = nullptr;
        ListNode* reverseHead = reverseList(p);
        p->next = head;

        return reverseHead;
    }
};