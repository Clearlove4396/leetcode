#include "tree.h"
using namespace std;


class Solution {
public:

    TreeNode* pre;
    TreeNode* cur;

    void find(TreeNode*& pre, TreeNode*& cur, int& key) {
        if(cur == nullptr || cur->val == key)
            return;
        
        if(cur->val < key) {
            pre = cur;
            cur = cur->right;
            find(pre, cur, key);
        }
        else {
            pre = cur;
            cur = cur->left;
            find(pre, cur, key);
        }
    }

    TreeNode* get(TreeNode* root) {
        TreeNode* res = root->right;
        if(res == nullptr)
            return root->left;

        while(res->left != nullptr)
            res = res->left;

        res->left = root->left;
        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;

        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;

        pre = dummy;
        cur = root;
        find(pre, cur, key);
        
        if(cur == nullptr)
            return dummy->left;

        TreeNode* tmp = get(cur);

        if(pre->left == cur) {
            pre->left = tmp;
        }
        else {
            pre->right = tmp;
        }

        return dummy->left;
    }
};