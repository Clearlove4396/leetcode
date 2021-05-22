#include "tree.h"
#include <stack>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        int res = INT_MAX;
        int dep = 0;
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                top.second = true;
                stk.push(top);
                if((top.first)->left != nullptr)
                    stk.push(make_pair((top.first)->left, false));
                if((top.first)->right != nullptr)
                    stk.push(make_pair((top.first)->right, false));
                dep++;
            }
            else {
                if((top.first)->left == nullptr && (top.first)->right == nullptr) {
                    res = std::min(res, dep);
                }
                dep--;
            }
        }
        return res;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        int leftDep = minDepth(root->left);
        int rightDep = minDepth(root->right);

        if(root->left != nullptr && root->right == nullptr)
            return 1 + leftDep;
        if(root->left == nullptr && root->right != nullptr)
            return 1 + rightDep;
        
        return 1 + std::min(leftDep, rightDep);
    }
};

#include <queue>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        queue<TreeNode* > qu;
        qu.push(root);
        int res = 0;
        while(!qu.empty()) {
            int size = qu.size();
            res++;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top->left == nullptr && top->right == nullptr)
                    return res;
                if(top->left != nullptr)
                    qu.push(top->left);
                if(top->right != nullptr)
                    qu.push(top->right);
            }
        }
        return res;
    }
};