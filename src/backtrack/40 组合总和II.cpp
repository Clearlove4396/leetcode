#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:

    void backtrack(vector<int>& candidates, int target, int sum, int idx, vector<vector<int> >& res, vector<int>& path, vector<bool>& visited) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            if(i > 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false) 
                continue;

            sum += candidates[i];
            path.push_back(candidates[i]);
            visited[i] = true;
            backtrack(candidates, target, sum, i + 1, res, path, visited);
            path.pop_back();
            sum -= candidates[i];
            visited[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > res;
        vector<int> path;
        vector<bool> visited(candidates.size(), false);
        
        backtrack(candidates, target, 0, 0, res, path, visited);

        return res;
    }
};