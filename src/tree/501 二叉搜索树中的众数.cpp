#include "tree.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    void func(TreeNode* root, unordered_map<int, int>& mp) {
        if(root == nullptr)
            return;
        func(root->left, mp);
        func(root->right, mp);
        mp[root->val]++;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        func(root, mp);

        int max = -1;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(max < it->second)
                max = it->second;
        }

        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == max)
                res.push_back(it->first);
        }
        return res;
    }
};



class Solution {
public:

    int count;
    int maxCount;
    TreeNode* pre;
    vector<int> res;


    void searchBST(TreeNode* root) {
        if(root == nullptr)
            return;
        
        searchBST(root->left);

        if(pre == nullptr || pre->val == root->val) {
            count++;
        }
        else {
            count = 1;
        }
        pre = root;

        if(count == maxCount) {
            res.push_back(root->val);
        }
        if(count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        }

        searchBST(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = nullptr;
        res.clear();

        searchBST(root);

        return res;
    }
};
