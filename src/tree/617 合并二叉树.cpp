#include "tree.h"
using namespace std;


class Solution {
public:
    void func(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr)
            return;
            
        if(root1->left == nullptr) {
            root1->left = root2->left;
            root2->left = nullptr;
        }
        else if(root2->left != nullptr) {
            root1->left->val += root2->left->val;
        }

        if(root1->right == nullptr) {
            root1->right = root2->right;
            root2->right = nullptr;
        }
        else if(root2->right != nullptr) {
            root1->right->val += root2->right->val;
        }

        func(root1->left, root2->left);
        func(root1->right, root2->right);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr)
            return root2;
        if(root2 == nullptr)
            return root1;

        root1->val += root2->val;
        func(root1, root2);
        
        return root1;
    }
};