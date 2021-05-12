class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, h = x;
        h += 1;

        while(l < h) {
            long long mid = l + (h - l) / 2;
            long long t = mid * mid;
            // if(t == x)
            //     return mid;
            if(t <= x)
                l = mid + 1;
            else
                h = mid;
        }
        return (int)(l - 1);
    }
};