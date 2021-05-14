

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



























