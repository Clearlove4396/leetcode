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

    // TreeNode* merge(TreeNode* left, TreeNode* right) {
    //     if(right == nullptr)
    //         return left;
    //     if(right->val > left->val)

    // }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;

        pre = nullptr;
        cur = root;
        find(pre, cur, key);

        if(cur == nullptr)
            return root;
        
        TreeNode* tmp = cur->right;
        if(tmp == nullptr)
            tmp = cur->left;
        while(tmp->left != nullptr)
            tmp = tmp->left;
        tmp->left = cur->left;
        
        if(pre == nullptr)
            return cur->right;
        else {
            if(pre->left == cur){
                pre->left = tmp;
            }
            else {
                pre->right = tmp;
            }
        }
        return root;
    }
};