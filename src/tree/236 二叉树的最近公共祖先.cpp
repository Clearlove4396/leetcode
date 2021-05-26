#include "tree.h"
using namespace std;


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(root == p || root == q)
            return root;

        if(l != nullptr && r != nullptr)
            return root;
        if(l != nullptr)
            return l;
        if(r != nullptr)
            return r;

        return nullptr;
    }
};