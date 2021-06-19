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

一个简单的想法是：先确定起点`cost[idx] <= gas[idx]`，然后从此起点处出发，验证是否可行。

不过这种方法最坏需要$O(n^2)$时间复杂度。

```c++
class Solution {
public:

    bool isBegin(vector<int>& gas, vector<int>& cost, int idx) {
        int oil = 0;
        for(int i = idx; i < gas.size(); i++) {
            oil += gas[i];
            oil -= cost[i];
            if(oil < 0)
                return false;
        }
        for(int i = 0; i < idx; i++) {
            oil += gas[i];
            oil -= cost[i];
            if(oil < 0)
                return false;
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;

        while(idx < gas.size()) {
            if(cost[idx] <= gas[idx] && isBegin(gas, cost, idx))
                return idx;
            idx++;
        }
        return -1;
    }
};
```



**贪心算法**（一次遍历）：

假设现在有一个数组`gc`，定义为`gas-cost`。我现在需要找到一个点，从该点开始，加和总是正的。也就是说如果现在确定了一点起点，但是从该起点开始相加时，出现了负数，那么确定的起点不是我们要找的，此时，要从出现问题的点继续向后寻找。

```c++
class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int idx = 0;
        int oil_rest = 0;
        for(int i = 0; i < gas.size(); i++) {
            oil_rest += gas[i] - cost[i];
            if(oil_rest < 0) {
                idx = -1;   // 前面确定的idx不合法，需要重新向后寻找。
                oil_rest = 0;   // 从下一个点寻找。
            }
            else if(idx == -1) {   // 加一层判断，否则idx可能一直向后移动，会出错
                idx = i;
            }
        }

        if(idx == -1)
            return -1;
        
        for(int i = 0; i < idx; i++) {
            oil_rest += gas[i] - cost[i];
            if(oil_rest < 0) {
                return -1;
            }
        }
        return idx;
    }
};
```



上面的代码还可以继续优化，优化的点是：我们有没有必要在确定`idx`之后，回过头判断`0~idx`这段路程的合法性？？？

```c++
for(int i = 0; i < idx; i++) {
    oil_rest += gas[i] - cost[i];
    if(oil_rest < 0) {
        return -1;
    }
}
```

可以优化成下面的代码：

`gc_cha`表示所有的“油”是否足够跑完所有的“路”。

为什么这种方法可行能？

抽象一下问题（在`gc`的基础上）：

假设`gc`的和是`a`，确定的点`idx`是`b`，问：是否存在一点`c`，使得`b+c<0`？？

![image-20210619175115392](D:\study\github\leetcode\src\greedy\image\1.png)

答：这一点不存在。证明如下：

![image-20210619175423992](D:\study\github\leetcode\src\greedy\image\2.png)

可以看出，此时`d>0`，但是如果`d>0`成立，那么我们找到的`idx`点一定在`d`处，而不是在`b`处。

```c++
class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int idx = 0;
        int oil_rest = 0;
        int gc_cha = 0;
        for(int i = 0; i < gas.size(); i++) {
            gc_cha = gc_cha + gas[i] - cost[i];
            oil_rest += gas[i] - cost[i];
            if(oil_rest < 0) {
                idx = -1;
                oil_rest = 0;
            }
            else if(idx == -1) {
                idx = i;
            }
        }

        return gc_cha >= 0? idx: -1;
    }
};
```



总结一下此题贪心算法（copy别人的。。。）：**局部最优：当前累加oil_rest[j]的和curSum一旦小于0，起始位置至少要是j+1，因为从j开始一定不行。全局最优：找到可以跑一圈的起始位置**。





## 968.监控二叉树







