#include <vector>
using namespace std;


class Solution {
public:

    void backtrack(int n, int k, int idx, vector<vector<int> >& res, vector<int>& path) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = idx; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1, res, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;

        vector<int> path;
        backtrack(n, k, 1, res, path);

        return res;
    }
};