#include "greedy.h"

class Solution {
public:

    bool isBegin(vector<int>& gas, vector<int>& cost, int idx) {
        int oil = 0;
        for(int i = idx; i < gas.size(); i++) {
            oil += gas[i];
            oil -= cost[i];
            if(oil < 0)
                return false;
        }
        for(int i = 0; i < idx; i++) {
            oil += gas[i];
            oil -= cost[i];
            if(oil < 0)
                return false;
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;

        while(idx < gas.size()) {
            if(cost[idx] <= gas[idx] && isBegin(gas, cost, idx))
                return idx;
            idx++;
        }
        return -1;
    }
};


class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int idx = 0;
        int oil_rest = 0;
        for(int i = 0; i < gas.size(); i++) {
            oil_rest += gas[i] - cost[i];
            if(oil_rest < 0) {
                idx = -1;
                oil_rest = 0;
            }
            else if(idx == -1) {
                idx = i;
            }
        }

        if(idx == -1)
            return -1;
        
        for(int i = 0; i < idx; i++) {
            oil_rest += gas[i] - cost[i];
            if(oil_rest < 0) {
                return -1;
            }
        }
        return idx;
    }
};


class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int idx = 0;
        int oil_rest = 0;
        int gc_cha = 0;
        for(int i = 0; i < gas.size(); i++) {
            gc_cha = gc_cha + gas[i] - cost[i];
            oil_rest += gas[i] - cost[i];
            if(oil_rest < 0) {
                idx = -1;
                oil_rest = 0;
            }
            else if(idx == -1) {
                idx = i;
            }
        }

        return gc_cha >= 0? idx: -1;
    }
};