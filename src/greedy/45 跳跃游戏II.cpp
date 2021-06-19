#include "greedy.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        int res = 1;
        int cur = 0;

        while(cur + nums[cur] < nums.size() - 1) {
            res++;

            int k = nums[cur];
            int max = -1;
            int hold, j = cur + 1;
            while(k--) {
                if(max <= nums[j] + j) {   // if(max < nums[j] + j)
                    hold = j;
                    max = nums[j] + j;
                }
                j++;
            }

            cur = hold;
        }
        return res;
    }
};