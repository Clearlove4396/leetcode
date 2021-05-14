#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int> > res;

        int l, r;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0)
                break;
            if(i >0 && nums[i] == nums[i-1])
                continue;
            
            l = i + 1;
            r = nums.size() - 1;
            while(l < r) {
                int t = nums[i] + nums[l] + nums[r];
                if(t > 0) {
                    r--;
                }
                else if(t < 0) {
                    l++;
                }
                else{
                    while(l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while(l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};