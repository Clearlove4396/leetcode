#include "tree.h"
using namespace std;


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr)
            return sumOfLeftLeaves(root->right);

        if(root->left->left == nullptr && root->left->right == nullptr)
            return root->left->val + sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};