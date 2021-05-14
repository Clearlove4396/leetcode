#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp1, mp2;
        
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                mp1[nums1[i] + nums2[j]] ++;
            }
        }

        for(int i = 0; i < nums3.size(); i++) {
            for(int j = 0; j < nums4.size(); j++) {
                mp2[nums3[i] + nums4[j]] ++;
            }
        }

        int res = 0;
        for(auto it = mp1.begin(); it !=  mp1.end(); it++) {
            auto iter = mp2.find(0 - it->first);
            if(iter != mp2.end())
                res = res + it->second * iter->second;
        }
        return res;
    }
};