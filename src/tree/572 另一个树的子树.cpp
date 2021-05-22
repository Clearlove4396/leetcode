#include "tree.h"
using namespace std;

class Solution {
public:

    bool func(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)
            return true;
        if(root == nullptr || subRoot == nullptr || root->val != subRoot->val)
            return false;
        
        return func(root->left, subRoot->left) && func(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr ||
         root != nullptr && subRoot == nullptr)
            return true;
        if(root == nullptr && subRoot != nullptr)
            return false;

        return func(root, subRoot) ||
             isSubtree(root->left, subRoot) ||
             isSubtree(root->right, subRoot);
    }
};