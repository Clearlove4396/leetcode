#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
        for(int i = 0, j = s.size() - n - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
        for(int i = s.size() - n, j = s.size() - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
        return s;
    }
};