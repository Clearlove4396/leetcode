

# hash基本原理

- 哈希表一般是用来判断一个元素是否出现在集合里。

- 一般使用**拉链法**和**线性探测法**，解决哈希碰撞

- 常见的`hash`结构：
  - 数组
  - `set`
  - `map`

| 集合               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::set           | 红黑树   | 有序     | 否               | 否           | O(logn)  | O(logn)  |
| std::multiset      | 红黑树   | 有序     | 是               | 否           | O(logn)  | O(logn)  |
| std::unordered_set | 哈希表   | 无序     | 否               | 否           | O(1)     | O(1)     |



| 映射               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::map           | 红黑树   | key有序  | key不可重复      | key不可修改  | O(logn)  | O(logn)  |
| std::multimap      | 红黑树   | key有序  | key可重复        | key不可修改  | O(logn)  | O(logn)  |
| std::unordered_map | 哈希表   | key无序  | key不可重复      | key不可修改  | O(1)     | O(1)     |



# 242.有效的字母异位词

使用数组进行`hash`

使用数组进行`hash`，一般需要限制范围，否则数组可能需要开辟很大，占用内存。

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> st(26, 0);
        for(int i = 0; i < s.size(); i++) {
            st[s[i] - 'a'] ++;
        }
        for(int i = 0; i < t.size(); i++) {
            st[t[i] - 'a'] --;
        }
        for(int i = 0; i < st.size(); i++) {
            if(st[i] != 0)
                return false;
        }
        return true;
    }
};
```



# 349.两个数组的交集



```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(int i: nums1) {
            st.insert(i);
        }
        vector<int> res;
        unordered_set<int> tmp;
        for(int i: nums2) {
            if(st.find(i) != st.end() && tmp.find(i) == tmp.end()) {
                tmp.insert(i);
                res.push_back(i);
            }
        }
        return res;
    }
};
```

注意构造函数的使用。

`unordered_set<int> nums_set(nums1.begin(), nums1.end());`

`vector<int>(result_set.begin(), result_set.end());`

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
```



# 202.快乐数



```c++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while(1) {
            if(n == 1)
                return true;
            else if(st.find(n) != st.end())
                return false;
            st.insert(n);

            int tmp = n;
            int t = 0;
            while(tmp != 0) {
                t += ((tmp % 10) * (tmp % 10));
                tmp /= 10;
            } 
            n = t;
        }
        return true;
    }
};
```



# 1.两数之和

可以使用`hash`做

也可以先排序，然后使用双指针，一个从头，一个从尾查找。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2)
            return {};
        
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int t = target - it->first;
            if(mp.find(t) == mp.end())
                continue;
            if(t == it->first) {
                if((it->second).size() >= 2) {
                    res.push_back((it->second)[0]);
                    res.push_back((it->second)[1]);
                    break;
                }
            }
            else{
                res.push_back((it->second)[0]);
                res.push_back(mp[t][0]);
                break;
            }
        }
        return res;
    }
};
```

别人的代码可以这样简洁~~

https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
```



# 454.四数相加II

对4个数组进行两两分组，`map`中`key`保存两个数组的和，`value`保存该和出现的个数。

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp1, mp2;
        
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                mp1[nums1[i] + nums2[j]] ++;
            }
        }

        for(int i = 0; i < nums3.size(); i++) {
            for(int j = 0; j < nums4.size(); j++) {
                mp2[nums3[i] + nums4[j]] ++;
            }
        }

        int res = 0;
        for(auto it = mp1.begin(); it !=  mp1.end(); it++) {
            auto iter = mp2.find(0 - it->first);
            if(iter != mp2.end())
                res = res + it->second * iter->second;
        }
        return res;
    }
};
```



# 383.赎金信

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> st(26, 0);
        for(char c: magazine) {
            st[c - 'a']++;
        }
        for(char c: ransomNote) {
            st[c - 'a']--;
            if(st[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
```



# 15.三数之和

双指针解法。

参考了这篇文章：https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/

注意代码中的**去重方法**

这道题的关键就是：设置1个[$3-2$个]不动点，然后使用双指针方法变量数组。

利用**不动点不可以重复**进行去重。

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int> > res;

        int l, r;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0)
                break;
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            // 假设序列是[-4, -1, -1, -1, 2]
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            l = i + 1;
            r = nums.size() - 1;
            while(l < r) {
                int t = nums[i] + nums[l] + nums[r];
                if(t > 0) {
                    r--;
                }
                else if(t < 0) {
                    l++;
                }
                else{
                    while(l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while(l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
```



# 18.四数之和

类似于三数之和。

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() <= 3)
            return {};

        vector<vector<int> > res;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int l = j + 1, r = nums.size() - 1;
                while(l < r) {
                    int t = nums[i] + nums[j] + nums[l] + nums[r];
                    if(t > target)
                        r--;
                    else if(t < target)
                        l++;
                    else{
                        while(l < r && nums[l] == nums[l + 1])
                            l++;
                        while(l < r && nums[r] == nums[r - 1])
                            r--;
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
```















