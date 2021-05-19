#include <vector>
#include "tree.h"
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode* > qu;

        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top->left != nullptr)    qu.push(top->left);
                if(top->right != nullptr)   qu.push(top->right);
                if(size == 0)
                    res.push_back(top->val);
            }
        }
        return res;
    }
};