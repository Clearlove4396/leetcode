#include "tree.h"
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* >qu;
        qu.push(root);
        int res;
        while(!qu.empty()) {
            int size = qu.size();
            bool update = false;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(!update) {
                    update = true;
                    res = top->val;
                }
                if(top->left)
                    qu.push(top->left);
                if(top->right)
                    qu.push(top->right);
            }
            update = false;
        }
        return res;
    }
};


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        
        int curdep = 0;
        int maxdep = 0;
        int res = root->val;

        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();

            if(top.second == false) {
                top.second = true;
                stk.push(top);
                if((top.first)->right)
                    stk.push(make_pair((top.first)->right, false));
                if((top.first)->left)
                    stk.push(make_pair((top.first)->left, false));
                
                curdep++;
            }
            else {
                if(maxdep < curdep) {
                    maxdep = curdep;
                    res = (top.first)->val;
                }
                curdep--;
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxdep = INT_MIN;
    int res;

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int dep) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr) {
            if(dep > maxdep) {
                maxdep = dep;
                res = root->val;
            }
        }
        dfs(root->left, dep + 1);
        dfs(root->right, dep + 1);
    }
};



