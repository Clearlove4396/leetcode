#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dqu;
        vector<int> res;
        
        int i = 0;
        while(i < k && i < nums.size()) {
            while(!dqu.empty() && dqu.back() < nums[i]) {
                dqu.pop_back();
            }
            dqu.push_back(nums[i]);
            i++;
        }
        int j = 0;
        while(i < nums.size()) {
            res.push_back(dqu.front());
            if(!dqu.empty() && dqu.front() == nums[j])
                dqu.pop_front();
            j++;
            
            while(!dqu.empty() && dqu.back() < nums[i]) {
                dqu.pop_back();
            }
            dqu.push_back(nums[i]);
            i++;
        }
        res.push_back(dqu.front());
        return res;
    }
};