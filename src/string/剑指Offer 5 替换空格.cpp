#include <string>
using namespace std;


// class Solution {
// public:
//     string replaceSpace(string s) {
//         string res = "";
//         for(char c: s) {
//             if(c == ' ')
//                 res += "%20";
//             else
//                 res += c;
//         }
//         return res;
//     }
// };

class Solution {
public:
    string replaceSpace(string s) {
        int c = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                c++;
        }
        int len = s.size();
        int resLen = s.size() + c * 2;
        s.resize(resLen);
        
        int j = resLen - 1;
        for(int i = len - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            else {
                s[j--] = s[i];
            }
        }
        return s;
    }
};

