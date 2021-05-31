#include <vector>
using namespace std;


class Solution {
public:

    void backtrack(int k, int n, int idx, vector<vector<int> >& res, vector<int>& path) {
        if(n == 0 && path.size() == k) {
            res.push_back(path);
            return;
        }

        if(n < idx) {
            return;
        }

        for(int i = idx; i <= 9; i++) {
            path.push_back(i);
            n -= i;
            backtrack(k, n, i + 1, res, path);
            n += i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;

        vector<int> path;

        backtrack(k, n, 1, res, path);
        return res;
    }
};