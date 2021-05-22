#include "tree.h"
#include <vector>
using namespace std;


class Solution {
public:

    void func(TreeNode* root, int targetSum, vector<vector<int> >& res, vector<int>& path) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        func(root->left, targetSum - root->val, res, path);
        func(root->right, targetSum - root->val, res, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > res;
        vector<int> path;
        
        func(root, targetSum, res, path);

        return res;
    }
};