#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        s = " " + s + " ";
        
        string tmp = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(tmp != "") {
                    reverse(tmp.begin(), tmp.end());
                    res += tmp + " ";
                    tmp = "";
                }
            }
            else{
                tmp += s[i];
            }
        }
        return res == ""? res: res.substr(0, res.size() - 1);
    }
};