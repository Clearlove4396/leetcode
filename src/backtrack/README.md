

# 基本理论

**回溯是递归的副产品，只要有递归就会有回溯**。

**一般是先写逻辑，然后需要什么参数，就填什么参数**

**回溯函数**

一般返回值是`void`

- 终止条件

  回溯函数终止条件伪代码如下：

  ```
  if (终止条件) {
      存放结果;
      return;
  }
  ```

- 遍历过程

  ![回溯算法理论基础](https://camo.githubusercontent.com/f65ca647f31913496481cd1aff144040bd7ee4f6bc30accd370bc78b4b265d13/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303133303137333633313137342e706e67)

  ```
  for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
      处理节点;
      backtracking(路径，选择列表); // 递归
      回溯，撤销处理结果
  }
  ```



**回溯函数模板**

```
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```



**典型回溯题目**

- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

总之：就是**从一个集合中按照一定规则搜索一个子集合**



# 组合

回溯法解决**组合**问题。和**排序**问题不同的是，在组合问题中元素的顺序不考虑，只需要从当前位置向后寻找。排序问题每次都需要**从头寻找**，需要用`visited`数组记录访问过的元素。



## 77.组合

模板题

```c++
class Solution {
public:

    void backtrack(int n, int k, int idx, vector<vector<int> >& res, vector<int>& path) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = idx; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1, res, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;

        vector<int> path;
        backtrack(n, k, 1, res, path);

        return res;
    }
};
```





## 17.电话号码的字母组合



```c++
class Solution {
public:

    void backtrack(string digits, int idx, vector<string>& c, vector<string>& res, string&& path) {
        if(idx == digits.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < c[digits[idx]-'0'].size(); i++) {
            backtrack(digits, idx + 1, c, res, path + c[digits[idx]-'0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> c = {"", "", "abc", "def", "ghi", "jkl",
         "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        backtrack(digits, 0, c, res, "");
        return res;
    }
};
```





## 39.组合总和

`backtrack(candidates, res, path, target, sum, i);`中的`i`就表示在递归树的下一层，仍然从`candidates[i]`这个数字开始查看，那么就代表`candidates[i]`可以重复使用。

```c++
class Solution {
public:

    void backtrack(vector<int>& candidates, vector<vector<int> >& res, vector<int>& path, int target, int sum, int idx) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, res, path, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;

        backtrack(candidates, res, path, target, 0, 0);

        return res;
    }
};
```



## 40.组合总和II

如果`candidates`中没有重复元素，则可以使用下面这种解答方法

`backtrack(candidates, target, sum, i + 1, res, path);`中的`i + 1`可以和第`216`做对比。

```c++
class Solution {
public:

    void backtrack(vector<int>& candidates, int target, int sum, int idx, vector<vector<int> >& res, vector<int>& path) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i + 1, res, path);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        
        backtrack(candidates, target, 0, 0, res, path);

        return res;
    }
};
```



由于含有重复元素，则可以先对`candidates`去除重复元素。

啊啊啊，去重是一个错误的操作方法

> 输入：
>
> [10,1,2,7,6,1,5] 
>
> 8
>
> 输出：
>
> [[1,2,5],[1,7],[2,6]]
>
> 预期结果：
>
> [[1,1,6],[1,2,5],[1,7],[2,6]]

下面是错误的方法

```c++
class Solution {
public:

    void backtrack(vector<int>& candidates, int target, int sum, int idx, vector<vector<int> >& res, vector<int>& path) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i + 1, res, path);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<int> st(candidates.begin(), candidates.end());
        vector<int> c(st.begin(), st.end());
        
        vector<vector<int> > res;
        vector<int> path;
        
        backtrack(c, target, 0, 0, res, path);

        return res;
    }
};
```



下面的思考是：如何去除结果集中的重复

用一个`visited`数组，因为这可以看做一种有序的，类似于排序问题了。

>输入：
>
>[10,1,2,7,6,1,5]
>
>8
>
>输出：
>
>[[1,2,5],[1,7],[1,6,1],[2,6],[2,1,5],[7,1]]
>
>预期结果：
>
>[[1,1,6],[1,2,5],[1,7],[2,6]]



```c++
class Solution {
public:

    void backtrack(vector<int>& candidates, int target, int sum, int idx, vector<vector<int> >& res, vector<int>& path, vector<bool>& visited) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            if(i > 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false) 
                continue;

            sum += candidates[i];
            path.push_back(candidates[i]);
            visited[i] = true;
            backtrack(candidates, target, sum, i + 1, res, path, visited);
            path.pop_back();
            sum -= candidates[i];
            visited[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > res;
        vector<int> path;
        vector<bool> visited(candidates.size(), false);
        
        backtrack(candidates, target, 0, 0, res, path, visited);

        return res;
    }
};
```













## 216.组合总和III

`if(n < idx) { return; }`是一种剪枝操作

```c++
class Solution {
public:

    void backtrack(int k, int n, int idx, vector<vector<int> >& res, vector<int>& path) {
        if(n == 0 && path.size() == k) {
            res.push_back(path);
            return;
        }

        if(n < idx) {
            return;
        }

        for(int i = idx; i <= 9; i++) {
            path.push_back(i);
            n -= i;
            backtrack(k, n, i + 1, res, path);
            n += i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;

        vector<int> path;

        backtrack(k, n, 1, res, path);
        return res;
    }
};
```













# 分割



## 131.分割回文串

使用回溯方法。

`end`可以直接替换成`s.size()`，因为一直都需要遍历到字符串的最后一个

```c++
class Solution {
public:
    
    bool isHuiWen(string& s, int begin, int end) {
        while(begin < end) {
            if(s[begin++] != s[end--])
                return false;
        }
        return true;
    }

    void backtrack(string& s, int begin, int end,
                 vector<vector<string> >& res, vector<string>& tmp) {
        if(begin >= end) {
            res.push_back(tmp);
            return;
        }

        for(int i = begin; i < end; i++) {
            if(isHuiWen(s, begin, i)) {
                tmp.push_back(s.substr(begin, i - begin + 1));
                backtrack(s, i + 1, end, res, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if(s.size() == 0)
            return {};

        vector<vector<string> > res;
        vector<string> tmp;
        backtrack(s, 0, s.size(), res, tmp);
        return res;
    }
};
```





## 93.复原IP地址

使用`count`记录点的个数。

使用**右引用**来避免`path`的回溯。

可以添加一个`else { break; }`，进行剪枝

```c++
class Solution {
public:

    bool isRight(string& s, int begin, int end) {
        string st = s.substr(begin, end - begin + 1);
        if(st[0] == '0' && st.size() != 1)
            return false;
        
        int t = atoi(st.c_str());
        if(t < 0 || t > 255)
            return false;

        return true;
    }

    void backtrack(string& s, int begin, int count, vector<string>& res, string&& path) {
        if(count == 0) {
            if(begin < s.size() && isRight(s, begin, s.size())) {
                res.push_back(path + "." + s.substr(begin, s.size() - begin));
            }
            return;
        }

        for(int i = begin; i < s.size(); i++) {
            if(isRight(s, begin, i)) {
                count--;
                if(path == "") {
                    backtrack(s, i + 1, count, res, s.substr(begin, i - begin + 1));
                }
                else {
                    backtrack(s, i + 1, count, res, path + "." + s.substr(begin, i - begin + 1));
                }
                count++;
            }
            else { break; }   // 剪枝！
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4)
            return {};

        vector<string> res;
        string path = "";
        backtrack(s, 0, 3, res, "");
        return res;
    }
};
```







# 子集



## 78.子集









## 90.子集II







# 排列







# 棋盘问题









# 其他

