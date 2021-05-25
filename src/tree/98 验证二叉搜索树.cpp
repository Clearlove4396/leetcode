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