#include "backtrack.h"

// class Solution {
// public:

//     void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& path, vector<bool>& visited) {
//         if(path.size() == nums.size()) {
//             res.push_back(path);
//             return;
//         }
//         for(int i = 0; i < nums.size(); i++) {
//             if(visited[i] == true || 
//                 (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == false)) {
//                 continue;
//             }
//             path.push_back(nums[i]);
//             visited[i] = true;
//             backtrack(nums, res, path, visited);
//             visited[i] = false;
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int> > res;
//         vector<int> path;
//         vector<bool> visited(nums.size(), false);

//         sort(nums.begin(), nums.end());

//         backtrack(nums, res, path, visited);

//         return res;
//     }
// };


class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& path, vector<bool>& visited) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i] == true) {
                continue;
            }
            if(st.find(nums[i]) != st.end()) {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, res, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);

        //sort(nums.begin(), nums.end());

        backtrack(nums, res, path, visited);

        return res;
    }
};