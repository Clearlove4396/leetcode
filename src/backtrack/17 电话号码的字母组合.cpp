#include <vector>
#include <string>
using namespace std;


class Solution {
public:

    void backtrack(string digits, int idx, vector<string>& c, vector<string>& res, string&& path) {
        if(idx == digits.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < c[digits[idx]-'0'].size(); i++) {
            backtrack(digits, idx + 1, c, res, path + c[digits[idx]-'0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> c = {"", "", "abc", "def", "ghi", "jkl",
         "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        backtrack(digits, 0, c, res, "");
        return res;
    }
};