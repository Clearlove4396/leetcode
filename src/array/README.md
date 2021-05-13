[TOC]



# 二分查找

## 704. 二分查找

==查找区间的定义==是不变量：每次缩小查找区间时，区间的定义（左右两边）总是和第一次相同。



```c++
// 查找区间定义：左闭右开
class Solution {
public:
    int search(vector<int> &nums, int target){
        int l = 0, h = nums.size();
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                h = mid;
        }
        return -1;
    }
};

// 查找区间定义：左闭右闭
class Solution {
public:
    int search(vector<int> &nums, int target){
        int l = 0, h = nums.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }
};
```



## 35.搜索插入位置

查找第一个大于等于target的值。

```c++
// 左闭右开
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size();
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else
                h = mid;
        }
        return h;
    }
};
```





## 34.在排序数据中查找元素的第一个和最后一个位置

先找左边，再找右边

```c++
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
```



## 69.x的平方根

寻找左边界

```c++
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, h = x;
        h += 1;

        while(l < h) {
            long long mid = l + (h - l) / 2;
            long long t = mid * mid;
            if(t == x)
                return mid;
            else if(t < x)
                l = mid + 1;
            else
                h = mid;
        }
        return (int)(l - 1);
    }
};
```



```c++
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
```



## 367.有效的完全平方数



```c++
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
```



```c++
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
```





# 双指针

==两个指针，一快一慢==



## 27.移除元素



```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int f = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val)
                continue;
            nums[f++] = nums[i];
        }
        return f;
    }
};
```



## 26. 删除有序数组中的重复项



```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        int slow = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != nums[slow]) {
                nums[++slow] = nums[i];
            }
        }
        return slow + 1;
    }
};
```



## 283.移动零



```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[slow++], nums[i]);
            }
        }
    }
};
```



## 844.比较含退格的字符串

处理到'#'时，指针向后退。

```c++
class Solution {
public:
    int func(string& s) {
        int ps = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if(ps >= 0)
                    ps--;
            }
            else{
                s[++ps] = s[i];
            }
        }
        ps++;

        return ps;
    }

    bool backspaceCompare(string s, string t) {
        int ps = func(s);
        int pt = func(t);
        
        if(ps != pt)
            return false;
        for(int i = 0; i < ps; i++) {
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
};
```



# 滑动窗口

所谓滑动窗口，**就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果**。



==关注3点：==

- **窗口中的内容**     `while(t >= target && l < r)`
- **右边界，向窗口中加入元素**    `while(r < nums.size())`
- **左边界，在满足窗口内容的情况下，缩小窗口**     `t -= nums[l++]`



## 209.长度最小的子数组



```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size() + 1;

        int l = 0, r = 0;
        int t = 0;
        while(r < nums.size()) {
            t += nums[r];
            r++;

            while(t >= target && l < r) {
                res = std::min(res, r - l);
                t -= nums[l++];
            }
        }
        if(res == nums.size() + 1)
            return 0;
        return res;
    }
};
```



## 904.水果成篮

需要记录窗口中的值，和该值在窗口中的数量。



也可以用`unordered_map`替代结构体。

```c++
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
```



## 76.最小覆盖子串

使用哈希表，判断窗口中的元素和目标窗口（t）中元素的关系

```c++
class Solution {
public:
    bool covered(unordered_map<char, int>& tmp, unordered_map<char, int>& wmp) {
        for(auto it = tmp.begin(); it != tmp.end(); it++) {
            if(wmp[it->first] < it->second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        string res = s + s;

        unordered_map<char, int> tmp, wmp;
        for(int i = 0; i < t.size(); i++) {
            tmp[t[i]]++;
        }

        int l = 0, r = 0;
        while(r < s.size()) {
            wmp[s[r]]++;
            r++;
            
            while(l < r && covered(tmp, wmp)) {
                if(res.size() > r - l) {
                    res = s.substr(l, r - l);
                }
                wmp[s[l]]--;
                l++;
            }
        }
        return (res == s + s)? "": res;
    }
};
```



# 模拟行为



## 59.螺旋矩阵II

使用`c`表示“现在转到第几圈了”

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));

        int k = n * n;
        int c = 0, r = 1;
        while(r <= k) {
            for(int j = c; j < n - c && r <= k; j++) {
                res[c][j] = r++;
            }
            for(int i = c + 1; i < n - c && r <= k; i++) {
                res[i][n-c-1] = r++;
            }
            for(int j = n - c - 2; j >= c && r <= k; j--) {
                res[n-c-1][j] = r++;
            }
            for(int i = n - c - 2; i > c && r <= k; i--) {
                res[i][c] = r++;
            }
            c++;
        }
        return res;
    }
};
```



## 54.螺旋矩阵



```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int c = 0, k = m * n, r = 1;
        while(r <= k) {
            for(int j = c; j < n - c && r <= k; j++) {
                res.push_back(matrix[c][j]);
                r++;
            }
            for(int i = c + 1; i < m - c && r <= k; i++) {
                res.push_back(matrix[i][n-c-1]);
                r++;
            }
            for(int j = n - c - 2; j >= c && r <= k; j--) {
                res.push_back(matrix[m-c-1][j]);
                r++;
            }
            for(int i = m - c - 2; i >= c + 1 && r <= k; i--) {
                res.push_back(matrix[i][c]);
                r++;
            }
            c++;
        }
        return res;
    }
};
```







