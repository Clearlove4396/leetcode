struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head == nullptr)
//             return head;

//         ListNode* slow = head, *fast = head;
//         while(fast != nullptr) {
//             fast = fast->next;
//             if(fast == nullptr)
//                 break;
//             fast = fast->next;
//             slow = slow->next;
//             if(fast == slow)
//                 break;
//         }
//         if(fast == nullptr)
//             return nullptr;
        
//         slow = head;
//         while(slow != fast) {
//             slow = slow->next;
//             fast = fast->next;
//         }
//         return slow;
//     }
// };

#include <unordered_set>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return head;

        unordered_set<ListNode* > st;
        ListNode* p = head;
        while(p != nullptr) {
            if(st.find(p) != st.end())
                break;
            st.insert(p);
            p = p->next;
        }
        return p;
    }
};

