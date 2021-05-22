#include "tree.h"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


class Solution {
public:

    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int ldep = 0, rdep = 0;
        TreeNode* lnode = root->left;
        while(lnode) {
            lnode = lnode->left;
            ldep++;
        }
        TreeNode* rnode = root->right;
        while(rnode) {
            rnode = rnode->right;
            rdep++;
        }

        if(ldep == rdep)
            return (2 << ldep) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
