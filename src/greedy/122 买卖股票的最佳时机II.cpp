#include "greedy.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        int hold = prices[0], rear = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < rear) {
                res += rear - hold;
                hold = prices[i];
            }
            rear = prices[i];
        }
        res += rear - hold;
        return res;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
