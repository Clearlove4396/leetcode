#include "backtrack.h"

class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& path, int idx) {
        if(idx >= nums.size()) {
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res.push_back(path);
            backtrack(nums, res, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;

        backtrack(nums, res, path, 0);
        res.push_back({});

        return res;
    }
};