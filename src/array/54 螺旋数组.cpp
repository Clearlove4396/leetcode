#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int c = 0, k = m * n, r = 1;
        while(r <= k) {
            for(int j = c; j < n - c && r <= k; j++) {
                res.push_back(matrix[c][j]);
                r++;
            }
            for(int i = c + 1; i < m - c && r <= k; i++) {
                res.push_back(matrix[i][n-c-1]);
                r++;
            }
            for(int j = n - c - 2; j >= c && r <= k; j--) {
                res.push_back(matrix[m-c-1][j]);
                r++;
            }
            for(int i = m - c - 2; i >= c + 1 && r <= k; i--) {
                res.push_back(matrix[i][c]);
                r++;
            }
            c++;
        }
        return res;
    }
};