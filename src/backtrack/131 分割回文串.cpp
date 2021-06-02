#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    
    bool isHuiWen(string& s, int begin, int end) {
        while(begin < end) {
            if(s[begin++] != s[end--])
                return false;
        }
        return true;
    }

    void backtrack(string& s, int begin, int end,
                 vector<vector<string> >& res, vector<string>& tmp) {
        if(begin >= end) {
            res.push_back(tmp);
            return;
        }

        for(int i = begin; i < end; i++) {
            if(isHuiWen(s, begin, i)) {
                tmp.push_back(s.substr(begin, i - begin + 1));
                backtrack(s, i + 1, end, res, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if(s.size() == 0)
            return {};

        vector<vector<string> > res;
        vector<string> tmp;
        backtrack(s, 0, s.size(), res, tmp);
        return res;
    }
};