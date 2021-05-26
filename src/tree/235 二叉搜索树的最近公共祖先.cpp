#include "tree.h"
using namespace std;

class Solution {
public:

    TreeNode* func(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;

        if(root->val > p->val && root->val < q->val)
            return root;
        
        if(root->val < p->val)
            return func(root->right, p, q);
        else
            return func(root->left, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }

        return func(root, p, q);
    }
};


class Solution {
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == nullptr) return cur;

        if (cur->val > p->val && cur->val > q->val) { 
            return traversal(cur->left, p, q);
        }

        if (cur->val < p->val && cur->val < q->val) { 
            return traversal(cur->right, p, q);
        }
        return cur;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};