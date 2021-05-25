#include "tree.h"
#include <vector>
using namespace std;


class Solution {
public:

    void func(TreeNode* root, vector<int>& res) {
        if(root != nullptr) {
            func(root->left, res);
            res.push_back(root->val);
            func(root->right, res);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        func(root, res);

        for(int i = 0; i < res.size() - 1; i++) {
            if(res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool func(TreeNode* root, long long min, long long max) {
        if(root == nullptr)
            return true;
        if(root->val <= min || root->val >= max)
            return false;
        
        return func(root->left, min, root->val)
             && func(root->right, root->val, max);
        
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        long long min = INT_MIN;
        long long max = INT_MAX;

        return func(root, min - 1, max + 1);
    }
};