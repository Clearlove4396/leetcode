#include "tree.h"
#include <stack>
using namespace std;


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int f, r, res = INT_MAX;
        int c = 0;

        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                if((top.first)->left)
                    stk.push(make_pair((top.first)->left, false));
                stk.push(make_pair(top.first, true));
                if((top.first)->right)
                    stk.push(make_pair((top.first)->right, false));
            }
            else {
                if(c > 1) {
                    if(res > abs(r - f))
                        res = abs(r - f);
                    f = r;
                    r = (top.first)->val;
                }
                else if(c == 0){
                    c++;
                    f = (top.first)->val;
                }
                else {
                    c++;
                    r = (top.first)->val;
                }
            }
        }
        return abs(r - f) > res? res: abs(r - f);
    }
};


class Solution {
public:
    void func(TreeNode* root, int& f, int& r, int& res) {
        if(root == nullptr)
            return;
        
        func(root->left, f, r, res);

        if(f == -1)
            f = root->val;
        else if(r == -1)
            r = root->val;
        else {
            if(res > abs(r - f))
                res = abs(r - f);
            f = r;
            r = root->val;
        }
        func(root->right, f, r, res);
    }

    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int f = -1, r = -1;

        func(root, f, r, res);
        return res > abs(r - f)? abs(r - f): res;
    }
};