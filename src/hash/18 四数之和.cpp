#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() <= 3)
            return {};

        vector<vector<int> > res;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int l = j + 1, r = nums.size() - 1;
                while(l < r) {
                    int t = nums[i] + nums[j] + nums[l] + nums[r];
                    if(t > target)
                        r--;
                    else if(t < target)
                        l++;
                    else{
                        while(l < r && nums[l] == nums[l + 1])
                            l++;
                        while(l < r && nums[r] == nums[r - 1])
                            r--;
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};