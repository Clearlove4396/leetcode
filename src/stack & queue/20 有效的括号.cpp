#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp({{'(', ')'}, {'[', ']'}, {'{', '}'}});

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(stk.size() == 0)
                    return false;
                char top = stk.top();
                if(mp[top] != s[i])
                    return false;
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return stk.size() == 0;
    }
};