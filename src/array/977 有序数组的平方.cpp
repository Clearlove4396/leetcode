#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        vector<int> res;
        int r = 0;
        while(r < nums.size() && nums[r] <= 0)
            r++;
        int f = r - 1;
        
        while(f >= 0 && r < nums.size()) {
            int nf = nums[f] * nums[f];
            int nr = nums[r] * nums[r];

            if(nf <= nr) {
                res.push_back(nf);
                f--;
            }
            else {
                res.push_back(nr);
                r++;
            }
        }

        while(f >= 0) {
            res.push_back(nums[f] * nums[f]);
            f--;
        }
        while(r < nums.size()) {
            res.push_back(nums[r] * nums[r]);
            r++;
        }
        return res;
    }
};