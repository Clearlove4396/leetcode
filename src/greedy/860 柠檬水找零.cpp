#include "greedy.h"


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> nums(11, 0);

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                nums[5]++;
            }
            else if(bills[i] == 10) {
                if(nums[5] == 0)
                    return false;

                nums[5]--;
                nums[10]++;
            }
            else {
                if(nums[5] == 0) 
                    return false;

                int t = 15;
                if(nums[10] != 0) {   // 贪心
                    t -= 10;
                    nums[10]--;
                }
                if(nums[5] < (t / 5))
                    return false;
                nums[5] -= (t / 5);
            }
        }
        return true;
    }
};