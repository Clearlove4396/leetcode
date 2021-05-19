#include <vector>
#include <queue>
#include "tree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<vector<int> > res;

        queue<TreeNode* > qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int> tmp;
            while(size--) {
                TreeNode* top = qu.front();
                qu.pop();

                tmp.push_back(top->val);
                if(top->left != nullptr)    qu.push(top->left);
                if(top->right != nullptr)    qu.push(top->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};