#include <vector>
#include "tree.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<TreeNode* > qu;
        vector<int> res;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            int maxVal = INT_MIN;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top->val > maxVal)
                    maxVal = top->val;
                if(top->left != nullptr)
                    qu.push(top->left);
                if(top->right != nullptr)
                    qu.push(top->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};