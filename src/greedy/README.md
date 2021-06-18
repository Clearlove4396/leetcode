# 什么是贪心

选择每一阶段的局部最优，从而达到全局最优



如何通过局部最优推出整体最优呢？什么时候可以使用贪心算法呢？

> 没有固定套路，只能先动手模拟，如果觉得可行（找不到反例，就可以试一试贪心），就可以试一试，不行的话，在思考动态规划方法。



贪心算法一般分为如下**四步**：

- 将问题分解为若干个子问题
- 找出适合的贪心策略
- 求解每一个子问题的最优解
- 将局部最优解堆叠成全局最优解





# 简单题目



## 455.分发饼干

**贪心**：小饼干尽量满足胃口小的孩子，这样才能留下大饼干去满足胃口大的孩子。

```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int idx = 0;
        for(int i = 0; i < s.size() && idx < g.size(); i++) {
            if(g[idx] <= s[i])
                idx++;
        }
        return idx;
    }
};
```





## 1005.K次取反后最大化的数组和





## 860.柠檬水找零









# 中等题目



## 序列问题



### 376.摆动序列

学习一下统计“峰”的方法

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        int preDiff = 0;
        int curDiff = 0;
        int res = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
};
```





### 738.单调递增的数字





## 贪心解决股票问题

### 122.买卖股票的最佳时机II



### 714.买卖股票的最佳时机含手续费



## 两个维度权衡问题



### 135.分发糖果



### 406.根据身高重建队列







# 有点难度





## 区间问题



### 55.跳跃游戏



### 45.跳跃游戏II





### 452.用最少数量的箭引爆气球





### 435.无重叠区间





### 763.划分字母区间





### 56.合并区间





## 53.最大子序和



```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int max = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(cur <= 0) {
                cur = 0;
            }
            cur += nums[i];
            max = std::max(max, cur);
        }

        // return cur < max? max: cur;
        return max;
    }
};
```





## 134.加油站





## 968.监控二叉树







