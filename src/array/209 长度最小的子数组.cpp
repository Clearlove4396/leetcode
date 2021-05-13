#include <vector>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size() + 1;

        int l = 0, r = 0;
        int t = 0;
        while(r < nums.size()) {
            t += nums[r];
            r++;

            while(t >= target && l < r) {
                res = std::min(res, r - l);
                t -= nums[l++];
            }
        }
        if(res == nums.size() + 1)
            return 0;
        return res;
    }
};