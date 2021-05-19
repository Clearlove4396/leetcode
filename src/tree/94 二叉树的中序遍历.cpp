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
    void inOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;

        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    // 非递归
    vector<int> inOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                if((top.first)->right != nullptr)
                    stk.push(make_pair((top.first)->right, false));
                stk.push(make_pair(top.first, true));
                if((top.first)->left != nullptr)
                    stk.push(make_pair((top.first)->left, false));
            }
            else
                res.push_back((top.first)->val);
        }

        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> res;
        // inOrder(root, res);
        // return res;

        return inOrder(root);
    }
};