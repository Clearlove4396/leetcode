#include "greedy.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int idx = 0;
        for(int i = 0; i < s.size() && idx < g.size(); i++) {
            if(g[idx] <= s[i])
                idx++;
        }
        return idx;
    }
};