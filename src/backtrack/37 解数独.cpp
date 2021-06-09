#include "backtrack.h"

typedef struct node {
    int r;
    int c;
    char val;
    node(int rr, int cc, char vv): r(rr), c(cc), val(vv){}
}Node;

class Solution {
public:

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isRight(vector<vector<char> >& board, int r, int c) {
        int n = board.size();

        for(int d = 0; d < 4; d++) {
            int i = r, j = c;
            i += dir[d][0];
            j += dir[d][1];
            for(; i >= 0 && i < n && j >= 0 && j < n; i += dir[d][0], j += dir[d][1]) {
                if(board[i][j] == board[r][c])
                    return false;
            }
        }

        int rl = r / 3 * 3;
        int rh = rl + 2;
        int cl = c / 3 * 3;
        int ch = cl + 2;

        for(int i = rl; i <= rh; i++) {
            for(int j = cl; j <= ch; j++) {
                if(i == r && j == c)
                    continue;
                if(board[i][j] == board[r][c])
                    return false;
            }
        }

        return true;
    }

    bool backtrack(vector<Node>& v, vector<vector<char> >& board, int idx) {
        if(idx >= v.size()) {
            return true;
        }
        Node tmp = v[idx];
        for(char ch = tmp.val; ch <= '9'; ch++) {
            board[tmp.r][tmp.c] = ch;
            if(!isRight(board, tmp.r, tmp.c)){
                continue;
            }
            //v[idx].val = ch;
            if(backtrack(v, board, idx + 1) == true) {
                return true;
            }
        }
        board[tmp.r][tmp.c] = '.';   //回溯
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<Node> v;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    v.push_back(node(i, j, '1'));
                }
            }
        }

        backtrack(v, board, 0);
    }
};