#include "tree.h"


class Solution {
public:
    bool func(TreeNode* l, TreeNode* r) {
        if(l == nullptr && r == nullptr)
            return true;
        
        // if(l == nullptr && r != nullptr || l != nullptr && r == nullptr)
        //     return false;
        
        // if(l->val != r->val)
        //     return false;

        if(l == nullptr || r == nullptr || l->val != r->val)
            return false;
        
        return func(l->left, r->right) && func(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return func(root, root);
    }
};

#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        queue<TreeNode* > qu;
        qu.push(root);
        bool flag = true;
        while(!qu.empty() && flag) {
            int size = qu.size();
            vector<string> tmp;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top == nullptr) {
                    tmp.push_back("#");
                    continue;
                }
                flag = true;
                qu.push(top->left);
                qu.push(top->right);
                tmp.push_back(to_string(top->val));
            }

            for(int i = 0, j = tmp.size() - 1; i < j; i++, j--) {
                if(tmp[i] != tmp[j])
                    return false;
            }
        }
        return true;
    }
};



class Solution {
public:

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        queue<TreeNode* > qu;
        
    }
};