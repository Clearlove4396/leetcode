
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(int i: nums1) {
            st.insert(i);
        }
        vector<int> res;
        unordered_set<int> tmp;
        for(int i: nums2) {
            if(st.find(i) != st.end() && tmp.find(i) == tmp.end()) {
                tmp.insert(i);
                res.push_back(i);
            }
        }
        return res;
    }
};