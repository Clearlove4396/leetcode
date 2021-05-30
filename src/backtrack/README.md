

# 基本理论

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





## 39.组合总和





## 40.组合总和II





## 216.组合总和III













# 分割





## 131.分割回文串





## 复原IP地址









# 子集







# 排列







# 棋盘问题









# 其他

