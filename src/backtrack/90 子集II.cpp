#include "backtrack.h"

class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& path, vector<bool>& visited, int idx) {
        if(idx >= nums.size()) {
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            if(i != 0 && nums[i - 1] == nums[i] && nums[i - 1] == false)
                continue;
            path.push_back(nums[i]);
            res.push_back(path);
            visited[i] = true;
            backtrack(nums, res, path, visited, i + 1);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;

        sort(nums.begin(), nums.end());

        vector<bool> visited(nums.size(), false);

        backtrack(nums, res, path, visited, 0);
        res.push_back({});

        return res;
    }
};