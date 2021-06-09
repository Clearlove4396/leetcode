#include "backtrack.h"

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& path, vector<bool>& visited) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, res, path, visited);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, res, path, visited);

        return res;
    }
};