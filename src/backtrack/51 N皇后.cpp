#include "backtrack.h"

class Solution {
public:

    // bool isRight(vector<string>& pan, int n, int i, int j) {
    //     for(int c = 0; c < n; c++) {
    //         if(pan[i][c] == 'Q')
    //             return false;
    //     }
    //     for(int r = 0; r < n; r++) {
    //         if(pan[r][j] == 'Q')
    //             return false;
    //     }
    //     int c = j, r = i;
    //     while(c >= 0 && r >= 0) {
    //         if(pan[r--][c--] == 'Q')
    //             return false;
    //     }
    //     c = j;
    //     r = i;
    //     while(c < n && r < n) {
    //         if(pan[r++][c++] == 'Q')
    //             return false;
    //     }
    //     c = j;
    //     r = i;
    //     while(c >= 0 && r < n) {
    //         if(pan[r++][c--] == 'Q')
    //             return false;
    //     }
    //     c = j;
    //     r = i;
    //     while(c < n && r >= 0) {
    //         if(pan[r--][c++] == 'Q')
    //             return false;
    //     }
    //     return true;
    // }

    int dir[8][2] = {{-1, -1}, {-1, 1}, {-1, 0},
                    {1, -1}, {1, 0}, {1, 1},
                    {0, -1}, {0, 1}};

    bool isRight(vector<string>& pan, int n, int i, int j) {
        for(int d = 0; d < 8; d++) {
            for(int r = i, c = j; r >= 0 && r < n && c >= 0 && c < n; r += dir[d][0], c += dir[d][1]) {
                if(pan[r][c] == 'Q')
                    return false;
            }
        }
        return true;
    }

    void backtrack(int n, int idx, vector<vector<string> >& res, vector<string>& pan) {
        if(idx >= n) {
            res.push_back(pan);
            return;
        }
        for(int j = 0; j < n; j++) {
            if(!isRight(pan, n, idx, j))
                continue;

            pan[idx][j] = 'Q';
            backtrack(n, idx + 1, res, pan);
            pan[idx][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> pan(n, string(n, '.'));
        vector<vector<string> > res;
        
        backtrack(n, 0, res, pan);

        return res;
    }
};