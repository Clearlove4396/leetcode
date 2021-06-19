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

直接排序，需要**两次**排序。

```c++
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        while(i < nums.size() && k) {
            if(nums[i] >= 0)
                break;
            nums[i] = -nums[i];
            i++;
            k--;
        }

        sort(nums.begin(), nums.end());
        if((k % 2) == 1) 
            nums[0] = -nums[0];
        
        int res = 0;
        for(int t: nums) {
            res += t;
        }
        return res;
    }
};
```



**按照绝对值排序**，只需要一次排序。

- 第一步：将数组按照绝对值大小从大到小排序，**注意要按照绝对值的大小**
- 第二步：从前向后遍历，遇到负数将其变为正数，同时K--（局部最优解）
- 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
- 第四步：求和

```c++
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};
```





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

有点类似于找“峰”值（`376`）。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        int hold = prices[0], rear = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < rear) {
                res += rear - hold;
                hold = prices[i];
            }
            rear = prices[i];
        }
        res += rear - hold;
        return res;
    }
};
```



精简的想法是：只要明天的价格高于今天，那么就今天买入，明天卖出

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

```



对于`[1,2,3,4]`这个例子，方法一会在`1`买入，`4`卖出，`2,3`不动。方法二会在`2,3`进行买入卖出操作。



### 714.买卖股票的最佳时机含手续费





## 两个维度权衡问题



### 135.分发糖果



### 406.根据身高重建队列







# 有点难度





## 区间问题



### 55.跳跃游戏

遍历到某一个数字时，比较当前剩余步数和当前数字的大小，取大的数字（局部最优解），如果数字大，我们就可能往后走更远的距离（全局最优解）（贪心）。

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            cur--;
            if(cur < 0)
                return false;
            if(cur < nums[i])
                cur = nums[i];
        }
        return true;
    }
};
```



### 45.跳跃游戏II

贪心思路：寻找的下一个点应该是能够到达更远的距离（局部最优），`if(max <= nums[j] + j)`。注意，这里的`=`不是必须的，只是加上等号之后，此次“跳跃”尽可能的往后跳。

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        int res = 1;
        int cur = 0;

        while(cur + nums[cur] < nums.size() - 1) {
            res++;

            int k = nums[cur];
            int max = -1;
            int hold, j = cur + 1;
            while(k--) {
                if(max <= nums[j] + j) {   // if(max < nums[j] + j)
                    hold = j;
                    max = nums[j] + j;
                }
                j++;
            }

            cur = hold;
        }
        return res;
    }
};
```





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







