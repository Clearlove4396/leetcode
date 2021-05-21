#include "tree.h"
#include <vector>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};