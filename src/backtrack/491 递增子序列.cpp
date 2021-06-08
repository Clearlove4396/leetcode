#include "backtrack.h"

class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int> >& res,
                vector<int>& path, int idx, unordered_set<string>& st, string&& tmp) {
        if(idx >= nums.size()) {
            return;
        }

        for(int i = idx; i < nums.size(); i++) {

            if(!path.empty() && nums[i] < path.back()) {
                continue;
            }
            
            path.push_back(nums[i]);
            if(path.size() >= 2) {
                if(st.find(tmp + "_" + to_string(nums[i])) == st.end()) {
                    st.insert(tmp + "_" + to_string(nums[i]));
                    res.push_back(path);
                }
            }
            backtrack(nums, res, path, i + 1, st, tmp + "_" + to_string(nums[i]));

            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;

        unordered_set<string> st;

        vector<bool> visited(nums.size(), false);

        backtrack(nums, res, path, 0, st, "");

        return res;
    }
};