#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int> > res;
        queue<Node* > qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int> tmp;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                tmp.push_back(top->val);
                for(Node* node: top->children) {
                    qu.push(node);
                }
            }
        }
        return res;
    }
};