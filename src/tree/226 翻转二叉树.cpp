#include "tree.h"
using namespace std;


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;

        invertTree(root->left);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        invertTree(root->left);
        return root;
    }
};