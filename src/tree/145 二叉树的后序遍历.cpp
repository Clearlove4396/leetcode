#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // 递归
    void postOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }

    // 非递归
    vector<int> postOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                stk.push(make_pair(top.first, true));
                if((top.first)->right)  stk.push(make_pair((top.first)->right, false));
                if((top.first)->left)   stk.push(make_pair((top.first)->left, false));
            }
            else
                res.push_back((top.first)->val);
        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;
        // postOrder(root, res);
        // return res;

        return postOrder(root);
    }
};