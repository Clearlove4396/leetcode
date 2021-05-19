
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root == nullptr)
//             return nullptr;
        
//         queue<Node* > qu;
//         qu.push(root);
//         while(!qu.empty()) {
//             int size = qu.size();
//             while(size--) {
//                 auto top = qu.front();
//                 qu.pop();
//                 if(size != 0) {
//                     top->next = qu.front();
//                 }
//                 if(top->left != nullptr)
//                     qu.push(top->left);
//                 if(top->right != nullptr)
//                     qu.push(top->right);
//             }
//         }
//         return root;
//     }
// };


class Solution {
public:
    void func(Node* l, Node* r) {
        if(l == nullptr && r == nullptr) {
            return;
        }
        if(l != nullptr){
            l->next = r;
            func(l->left, l->right);
        }
        if(r != nullptr) {
            func(r->left, r->right);
        }
        if(l != nullptr && r != nullptr) {
            l->next = r;
        }
    }

    Node* connect(Node* root) {
        func(nullptr, root);
        return root;
    }
};