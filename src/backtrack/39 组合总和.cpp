#include <vector>
using namespace std;


class Solution {
public:

    void backtrack(vector<int>& candidates, vector<vector<int> >& res, vector<int>& path, int target, int sum, int idx) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, res, path, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;

        backtrack(candidates, res, path, target, 0, 0);

        return res;
    }
};