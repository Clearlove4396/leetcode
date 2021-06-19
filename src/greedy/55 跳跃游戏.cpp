#include "greedy.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            cur--;
            if(cur < 0)
                return false;
            if(cur < nums[i])
                cur = nums[i];
        }
        return true;
    }
};