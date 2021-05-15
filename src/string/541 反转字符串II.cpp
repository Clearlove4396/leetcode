#include <string>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        //string res = "";
        for(int i = 0; i < s.size(); i += 2*k) {
            int ii = i, j = i + k - 1, t = i + k;
            if(j > s.size() - 1) {
                j = s.size() - 1;
            }
            while(ii < j) {
                std::swap(s[ii++], s[j--]);
            }
        }
        return s;
    }
};