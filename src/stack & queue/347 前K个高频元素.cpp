#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef struct node {
    int val;
    int num;
    Node(int v, int n): val(v), num(n){}
}Node;

struct cmp {
    bool operator() (Node a, Node b) {
        return a.num > b.num;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<Node, vector<Node>, cmp> pq;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] ++;
        }

        vector<int> res;
        auto it = mp.begin();
        while(k--) {
            pq.push(Node(it->first, it->second));
            it++;
        }

        while(it != mp.end()) {
            if(pq.top().num < it->second) {
                pq.pop();
                pq.push(Node(it->first, it->second));
            }
            it++;
        }
        while(!pq.empty()) {
            res.push_back(pq.top().val);
            pq.pop();
        }
        return res;
    }
};