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
