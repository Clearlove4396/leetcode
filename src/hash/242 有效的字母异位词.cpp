#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> st(26, 0);
        for(int i = 0; i < s.size(); i++) {
            st[s[i] - 'a'] ++;
        }
        for(int i = 0; i < t.size(); i++) {
            st[t[i] - 'a'] --;
        }
        for(int i = 0; i < st.size(); i++) {
            if(st[i] != 0)
                return false;
        }
        return true;
    }
};