#include <vector>
#include "tree.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<TreeNode* > qu;
        vector<double> res;

        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            double t = 0;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                t += top->val;
                if(top->left)   qu.push(top->left);
                if(top->right)  qu.push(top->right);
            }
            res.push_back(t / size);
        }
        return res;
    }
};