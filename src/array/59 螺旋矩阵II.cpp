#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));

        int k = n * n;
        int c = 0, r = 1;
        while(r <= k) {
            for(int j = c; j < n - c && r <= k; j++) {
                res[c][j] = r++;
            }
            for(int i = c + 1; i < n - c && r <= k; i++) {
                res[i][n-c-1] = r++;
            }
            for(int j = n - c - 2; j >= c && r <= k; j--) {
                res[n-c-1][j] = r++;
            }
            for(int i = n - c - 2; i > c && r <= k; i--) {
                res[i][c] = r++;
            }
            c++;
        }
        return res;
    }
};