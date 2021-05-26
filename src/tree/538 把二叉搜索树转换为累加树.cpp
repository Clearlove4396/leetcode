#include "tree.h"
using namespace std;


class Solution {
public:

    void func(TreeNode* root, int& cur) {
        if(root == nullptr)
            return;

        func(root->right, cur);

        int t = root->val;
        root->val += cur;
        cur += t;

        func(root->left, cur);
    }

    TreeNode* convertBST(TreeNode* root) {
        int cur = 0;
        func(root, cur);
        return root;
    }
};