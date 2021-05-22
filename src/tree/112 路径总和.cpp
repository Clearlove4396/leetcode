#include "tree.h"
using namespace std;


class Solution {
public:

    void func(TreeNode* root, int& targetSum, bool& res) {
        if(root == nullptr)
            return;
        if(res == true)
            return;

        if(targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            res = true;
            return;
        }

        targetSum -= root->val;
        func(root->left, targetSum, res);
        if(res == false)
            func(root->right, targetSum, res);
        
        targetSum += root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        func(root, targetSum, res);
        return res;
    }
};