class Solution {
public:
    bool isPerfectSquare(int num) {
        // 寻找左边界：小于等于sqrt(num)的最大值
        long long l = 0, h = num;
        h += 1;

        while(l < h) {
            long long mid = l + (h - l) / 2;
            long long t = mid * mid;
            
            if(t <= num)
                l = mid + 1;
            else
                h = mid;
        }
        if((l - 1) * (l - 1) == num)
            return true;
        else
            return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        // 寻找右边界：大于等于sqrt(num)的最小值
        long long l = 0, h = num;
        h += 1;

        while(l < h) {
            long long mid = l + (h - l) / 2;
            long long t = mid * mid;
            
            if(t >= num)
                h = mid;
            else
                l = mid + 1;
        }
        if(l * l == num)
            return true;
        else
            return false;
    }
};