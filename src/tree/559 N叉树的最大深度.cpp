#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        int max = 0;
        for(int i = 0; i < root->children.size(); i++) {
            max = std::max(max, maxDepth((root->children)[i]));
        }
        return 1 + max;
    }
};

#include <stack>

class Solution {
public:

    typedef struct st_node{
        Node* pointer;
        bool flag;
        int dep;
        st_node(Node* p): pointer(p), flag(false) {}
    };

    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        
        stack<st_node> stk;
        stk.push(st_node(root));
        int res = 0;
        int dep = 0;
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.flag == false) {
                top.flag = true;
                stk.push(top);
                for(auto pointer: top.pointer->children) {
                    stk.push(st_node(pointer));
                }
                dep++;
            }
            else {
                res = std::max(res, dep);
                dep--;
            }
        }
        return res;
    }
};