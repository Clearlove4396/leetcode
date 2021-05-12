#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);

        int l = 0, h = nums.size();
        // left bound
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else 
                h = mid;
        }
        if(h == nums.size() || nums[l] != target)
            return res;
        res[0] = l;
        
        l = 0, h = nums.size();
        // right bound
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] <= target)
                l = mid + 1;
            else
                h = mid;
        }
        res[1] = l - 1;

        return res;
    }
};
