#include "tree.h"
#include <cmath>
using namespace std;




class Solution {
public:

    int depthAndBalance(TreeNode* root, bool& res) {
        if(root == nullptr)
            return 0;
        
        int leftDep = depthAndBalance(root->left, res);
        int rightDep = depthAndBalance(root->right, res);
        if(abs(leftDep - rightDep) > 1)
            res = false;
        
        return std::max(leftDep, rightDep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        bool res = true;
        depthAndBalance(root, res);
        return res;
    }
};




class Solution {
public:

    int depthAndBalance(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int leftDep = depthAndBalance(root->left);
        int rightDep = depthAndBalance(root->right);
        if(leftDep == -1 || rightDep == -1 || abs(leftDep - rightDep) > 1)
            return -1;
        
        return std::max(leftDep, rightDep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int res = depthAndBalance(root);
        return res == -1? false: true;
    }
};