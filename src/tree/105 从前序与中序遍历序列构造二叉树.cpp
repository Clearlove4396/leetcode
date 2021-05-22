#include "tree.h"
#include <vector>
using namespace std;

class Solution {
public:

    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri) {
        if(lp > rp)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[lp]);
        int i = li;
        while(i < rp && preorder[lp] != inorder[i])
            i++;
        node->left = func(preorder, inorder, lp + 1, lp + (i - li), li, i - 1);
        node->right = func(preorder, inorder, lp + (i - li) + 1, rp, i + 1, ri);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return nullptr;

        return func(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};