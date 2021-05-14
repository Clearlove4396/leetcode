#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2)
            return {};
        
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int t = target - it->first;
            if(mp.find(t) == mp.end())
                continue;
            if(t == it->first) {
                if((it->second).size() >= 2) {
                    res.push_back((it->second)[0]);
                    res.push_back((it->second)[1]);
                    break;
                }
            }
            else{
                res.push_back((it->second)[0]);
                res.push_back(mp[t][0]);
                break;
            }
        }
        return res;
    }
};