#include "tree.h"
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    void func(TreeNode* root, vector<string>& res, string&& ss) {
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr) {
            res.push_back(ss + "->" + to_string(root->val));
            return;
        }

        func(root->left, res, ss + "->" + to_string(root->val));
        func(root->right, res, ss + "->" + to_string(root->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return {};
        if(root->left == nullptr && root->right == nullptr)
            return {to_string(root->val)};

        vector<string> res;
        func(root->left, res, to_string(root->val));
        func(root->right, res, to_string(root->val));
        return res;
    }
};