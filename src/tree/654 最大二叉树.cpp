#include "tree.h"
#include <vector>
using namespace std;


class Solution {
public:

    TreeNode* func(vector<int>& nums, int l, int r) {
        if(l > r)
            return nullptr;
        int idx = l;
        int max = -1;
        for(int i = l; i <= r; i++) {
            if(max < nums[i]) {
                max = nums[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(nums[idx]);
        root->left = func(nums, l, idx - 1);
        root->right = func(nums, idx + 1, r);

        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;

        return func(nums, 0, nums.size() - 1);
    }
};