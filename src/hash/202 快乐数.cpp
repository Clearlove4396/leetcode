#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while(1) {
            if(n == 1)
                return true;
            else if(st.find(n) != st.end())
                return false;
            st.insert(n);

            int tmp = n;
            int t = 0;
            while(tmp != 0) {
                t += ((tmp % 10) * (tmp % 10));
                tmp /= 10;
            } 
            n = t;
        }
        return true;
    }
};