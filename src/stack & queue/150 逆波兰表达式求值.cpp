#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || 
            tokens[i] == "*" || tokens[i] == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                if(tokens[i] == "+") 
                    stk.push(b + a);
                else if(tokens[i] == "-")  
                    stk.push(b - a);
                else if(tokens[i] == "*") 
                    stk.push(b * a);
                else
                    stk.push(b / a);
            }
            else {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};