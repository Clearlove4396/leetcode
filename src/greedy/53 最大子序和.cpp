#include "greedy.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int max = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(cur <= 0) {
                cur = 0;
            }
            cur += nums[i];
            max = std::max(max, cur);
        }

        // return cur < max? max: cur;
        return max;
    }
};