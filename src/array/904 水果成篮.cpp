#include <vector>
using namespace std;

typedef struct node {
    int val;
    int num;
}Node;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() < 3)
            return tree.size();

        int l = 0, r = 1;
        int curLen = 0, len = 0;
        Node a, b;
        a.val = tree[0];
        a.num = 1;

        while(r < tree.size() && tree[r] == a.val) {
            r++;
            a.num++;
        }

        if(r >= tree.size())
            return tree.size();
        else{
            curLen = r - l + 1;
            b.val = tree[r];
            b.num = 1;
            r++;
        }
            
        while(r < tree.size()) {
            if(tree[r] == a.val) {
                curLen++;
                a.num++;
                // r++;
            }
            else if(tree[r] == b.val) {
                curLen++;
                b.num++;
                // r++;
            }
            else{
                len = std::max(len, curLen);

                while(l < r && a.num != 0 && b.num != 0) {
                    if(tree[l] == a.val) {
                        a.num--;
                    }
                    else if(tree[l] == b.val){
                        b.num--;
                    }
                    l++;
                }
                if(a.num == 0) {
                    a.val = tree[r];
                    a.num = 1;
                }
                else {
                    b.val = tree[r];
                    b.num = 1;
                }
                curLen = r - l + 1;
                // r++;
            }
            r++;
        }
        return std::max(len, curLen);
    }
};