#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        int i = 0;

        // while(i < s.size()) {
        //     if(stk.empty())
        //         stk.push(s[i++]);
        //     else {
        //         if(stk.top() == s[i]) {
        //             while(i < s.size() && stk.top() == s[i]){
        //                 i++;
        //             }
        //             stk.pop();
        //         }
        //         else {
        //             stk.push(s[i++]);
        //         }
        //     }
        // }

        while(i < s.size()) {
            if(stk.empty() || stk.top() != s[i]) {
                stk.push(s[i]);
            }
            else {
                stk.pop();
            }
            i++;
        }

        string res = "";
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.begin() + res.size());
        return res;
    }
};