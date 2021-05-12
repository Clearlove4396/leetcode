#include <string>
using namespace std;


class Solution {
public:

    int func(string& s) {
        int ps = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if(ps >= 0)
                    ps--;
            }
            else{
                s[++ps] = s[i];
            }
        }
        ps++;

        return ps;
    }

    bool backspaceCompare(string s, string t) {
        int ps = func(s);
        int pt = func(t);
        
        if(ps != pt)
            return false;
        for(int i = 0; i < ps; i++) {
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
};