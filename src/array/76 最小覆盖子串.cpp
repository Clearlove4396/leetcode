#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool covered(unordered_map<char, int>& tmp, unordered_map<char, int>& wmp) {
        for(auto it = tmp.begin(); it != tmp.end(); it++) {
            if(wmp[it->first] < it->second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        string res = s + s;

        unordered_map<char, int> tmp, wmp;
        for(int i = 0; i < t.size(); i++) {
            tmp[t[i]]++;
        }

        int l = 0, r = 0;
        while(r < s.size()) {
            wmp[s[r]]++;
            r++;
            
            while(l < r && covered(tmp, wmp)) {
                if(res.size() > r - l) {
                    res = s.substr(l, r - l);
                }
                wmp[s[l]]--;
                l++;
            }
        }
        return (res == s + s)? "": res;
    }
};