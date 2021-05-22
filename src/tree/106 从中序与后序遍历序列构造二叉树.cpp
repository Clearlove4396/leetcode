#include "tree.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* func(vector<int>& inorder, vector<int>& postorder, int li, int ri, int lp, int rp) {
        if(li > ri)
            return nullptr;
        
        TreeNode* node = new TreeNode(postorder[rp]);
        int i = li;
        while(i < ri && inorder[i] != postorder[rp])
            i++;
        node->left = func(inorder, postorder, li, i - 1, lp, lp + (i - li) - 1);
        node->right = func(inorder, postorder, i + 1, ri, lp + (i - li), rp - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return nullptr;
        
        return func(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};