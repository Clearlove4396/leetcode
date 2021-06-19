#include "greedy.h"

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        while(i < nums.size() && k) {
            if(nums[i] >= 0)
                break;
            nums[i] = -nums[i];
            i++;
            k--;
        }

        sort(nums.begin(), nums.end());
        if((k % 2) == 1) 
            nums[0] = -nums[0];
        
        int res = 0;
        for(int t: nums) {
            res += t;
        }
        return res;
    }
};