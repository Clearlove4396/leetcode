#include "greedy.h"

class Solution {
public:


    bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        for(int i = 1; i < people.size(); i++) {
            auto t = people[i];
            int begin = people[i][1];
            for(int j = i - 1; j >= begin; j--) {
                people[j + 1] = people[j];
            }
            people[begin] = t;
        }
        return people;
    }
};