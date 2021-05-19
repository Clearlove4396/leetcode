#include <vector>
#include <stack>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     void preOrder(TreeNode* root, vector<int>& res) {
//         if(root == nullptr)
//             return;
//         res.push_back(root->val);
//         preOrder(root->left, res);
//         preOrder(root->right, res);
//     }

//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         preOrder(root, res);
//         return res;
//     }
// };


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
    void preOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    // 非递归
    vector<int> preOrder(TreeNode* root){
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<TreeNode* > stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            if(top->right)  stk.push(top->right);
            if(top->left)   stk.push(top->left);
        }

        return res;
    }

    vector<int> preOrder_sta(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                if((top.first)->right)  stk.push(make_pair((top.first)->right, false));
                if((top.first)->left)   stk.push(make_pair((top.first)->left, false));
                stk.push(make_pair(top.first, true));
            }
            else
                res.push_back((top.first)->val);
        }
        return res;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> res;
        // preOrder(root, res);
        // return res;

        return preOrder_sta(root);
    }
};