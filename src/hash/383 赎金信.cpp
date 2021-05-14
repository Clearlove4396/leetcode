#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> st(26, 0);
        for(char c: magazine) {
            st[c - 'a']++;
        }
        for(char c: ransomNote) {
            st[c - 'a']--;
            if(st[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};