#include <vector>
#include <string>
using namespace std;


class Solution {
public:

    bool isRight(string& s, int begin, int end) {
        string st = s.substr(begin, end - begin + 1);
        if(st[0] == '0' && st.size() != 1)
            return false;
        
        int t = atoi(st.c_str());
        if(t < 0 || t > 255)
            return false;

        return true;
    }

    void backtrack(string& s, int begin, int count, vector<string>& res, string&& path) {
        if(count == 0) {
            if(begin < s.size() && isRight(s, begin, s.size())) {
                res.push_back(path + "." + s.substr(begin, s.size() - begin));
            }
            return;
        }

        for(int i = begin; i < s.size(); i++) {
            if(isRight(s, begin, i)) {
                count--;
                if(path == "") {
                    backtrack(s, i + 1, count, res, s.substr(begin, i - begin + 1));
                }
                else {
                    backtrack(s, i + 1, count, res, path + "." + s.substr(begin, i - begin + 1));
                }
                count++;
            }
            else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4)
            return {};

        vector<string> res;
        string path = "";
        backtrack(s, 0, 3, res, "");
        return res;
    }
};