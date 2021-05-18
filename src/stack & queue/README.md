# 基本理论

copy自：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md

我想栈和队列的原理大家应该很熟悉了，**队列是先进先出，栈是先进后出**。

如图所示：

[![栈与队列理论1](https://camo.githubusercontent.com/363cdde8c6b61a1c156e6c978b2957f80ba61bcdcb1bdeaa9c706b5bb82ea15b/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303130343233353334363536332e706e67)](https://camo.githubusercontent.com/363cdde8c6b61a1c156e6c978b2957f80ba61bcdcb1bdeaa9c706b5bb82ea15b/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303130343233353334363536332e706e67)

那么我这里在列出四个关于栈的问题，大家可以思考一下。以下是以C++为例，相信使用其他编程语言的同学也对应思考一下，自己使用的编程语言里栈和队列是什么样的。

1. C++中stack 是容器么？
2. 我们使用的stack是属于那个版本的STL？
3. 我们使用的STL中stack是如何实现的？
4. stack 提供迭代器来遍历stack空间么？

相信这四个问题并不那么好回答， 因为一些同学使用数据结构会停留在非常表面上的应用，稍稍往深一问，就会有好像懂，好像也不懂的感觉。

有的同学可能仅仅知道有栈和队列这么个数据结构，却不知道底层实现，也不清楚所使用栈和队列和STL是什么关系。

所以这里我在给大家扫一遍基础知识，

首先大家要知道 栈和队列是STL（C++标准库）里面的两个数据结构。

C++标准库是有多个版本的，要知道我们使用的STL是哪个版本，才能知道对应的栈和队列的实现原理。

那么来介绍一下，三个最为普遍的STL版本：

1. HP STL 其他版本的C++ STL，一般是以HP STL为蓝本实现出来的，HP STL是C++ STL的第一个实现版本，而且开放源代码。
2. P.J.Plauger STL 由P.J.Plauger参照HP STL实现出来的，被Visual C++编译器所采用，不是开源的。
3. SGI STL 由Silicon Graphics Computer Systems公司参照HP STL实现，被Linux的C++编译器GCC所采用，SGI STL是开源软件，源码可读性甚高。

接下来介绍的栈和队列也是SGI STL里面的数据结构， 知道了使用版本，才知道对应的底层实现。

来说一说栈，栈先进后出，如图所示：

[![栈与队列理论2](https://camo.githubusercontent.com/11adc719f6dd61352ae413331ebb24580b6a33b23f00146f9b796f4bf9e898cd/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303130343233353433343930352e706e67)](https://camo.githubusercontent.com/11adc719f6dd61352ae413331ebb24580b6a33b23f00146f9b796f4bf9e898cd/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303130343233353433343930352e706e67)

栈提供push 和 pop 等等接口，所有元素必须符合先进后出规则，所以栈不提供走访功能，也不提供迭代器(iterator)。 不像是set 或者map 提供迭代器iterator来遍历所有元素。

**栈是以底层容器完成其所有的工作，对外提供统一的接口，底层容器是可插拔的（也就是说我们可以控制使用哪种容器来实现栈的功能）。**

所以STL中栈往往不被归类为容器，而被归类为container adapter（容器适配器）。

那么问题来了，STL 中栈是用什么容器实现的？

从下图中可以看出，栈的内部结构，栈的底层实现可以是vector，deque，list 都是可以的， 主要就是数组和链表的底层实现。

[![栈与队列理论3](https://camo.githubusercontent.com/3137ea5cf8ab77dcccc2b8ae72187d4d3ef50ea3465b6a1159879813c67a33d5/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303130343233353435393337362e706e67)](https://camo.githubusercontent.com/3137ea5cf8ab77dcccc2b8ae72187d4d3ef50ea3465b6a1159879813c67a33d5/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303130343233353435393337362e706e67)

**我们常用的SGI STL，如果没有指定底层实现的话，默认是以deque为缺省情况下栈的低层结构。**

deque是一个双向队列，只要封住一段，只开通另一端就可以实现栈的逻辑了。

**SGI STL中 队列底层实现缺省情况下一样使用deque实现的。**

我们也可以指定vector为栈的底层实现，初始化语句如下：

```
std::stack<int, std::vector<int> > third;  // 使用vector为底层容器的栈
```

刚刚讲过栈的特性，对应的队列的情况是一样的。

队列中先进先出的数据结构，同样不允许有遍历行为，不提供迭代器, **SGI STL中队列一样是以deque为缺省情况下的底部结构。**

也可以指定list 为起底层实现，初始化queue的语句如下：

```
std::queue<int, std::list<int>> third; // 定义以list为底层容器的队列
```

所以STL 队列也不被归类为容器，而被归类为container adapter（ 容器适配器）。

我这里讲的都是（clck）C++ 语言中情况， 使用其他语言的同学也要思考栈与队列的底层实现问题， 不要对数据结构的使用浅尝辄止，而要深挖起内部原理，才能夯实基础。



# 232.用栈实现队列

进入栈A，然后从栈A中出来进入栈B，栈B中的元素排列就是队列了~

```c++
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stk2.size() == 0) {
            while(!stk1.size() == 0) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int res = stk2.top();
        stk2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res = this->pop();
        stk2.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.size() == 0 && stk2.size() == 0;
    }

private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```



# 225.用队列实现栈

因为从一个队列到另外一个队列，数据结构的性质没有改变，还是队列。所以操作更加复杂一点

可以使用一个队列解决问题，只需要记住`size`即可。

```c++
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qu1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(qu1.size() != 1) {
            qu2.push(qu1.front());
            qu1.pop();
        }
        int res = qu1.front();
        qu1.pop();
        while(qu2.size() != 0) {
            qu1.push(qu2.front());
            qu2.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = this->pop();
        qu1.push(res);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qu1.size() == 0;
    }

private:
    queue<int> qu1, qu2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```



# 20.有效的括号

使用一个`unordered_map`，减少判断语句

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp({{'(', ')'}, {'[', ']'}, {'{', '}'}});

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(stk.size() == 0)
                    return false;
                char top = stk.top();
                if(mp[top] != s[i])
                    return false;
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return stk.size() == 0;
    }
};
```



# 1047.删除字符串中的所有相邻重复项



```c++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;

        for(int i = 0; i < s.size(); i++) {
            if(stk.empty() || stk.top() != s[i]) 
                stk.push(s[i]);
            else
                stk.pop();
        }

        string res = "";
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.begin() + res.size());
        return res;
    }
};
```



# 150.逆波兰表达式求值

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || 
            tokens[i] == "*" || tokens[i] == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                if(tokens[i] == "+") 
                    stk.push(b + a);
                else if(tokens[i] == "-")  
                    stk.push(b - a);
                else if(tokens[i] == "*") 
                    stk.push(b * a);
                else
                    stk.push(b / a);
            }
            else {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};
```





# 239.滑动窗口最大值

**单调队列**：维护**队列**中的元素单调递减或者单调递增。

单调队列的`pop`和`push`方法

- `pop(value)`：如果窗口移除的元素value等于单调队列的**出口**元素，那么队列弹出元素，否则不用任何操作

- `push(value)`：如果push的元素value大于**入口**元素的数值，那么就将队列入口的元素弹出，直到push元素的数值**小于等于**队列入口元素的数值为止



在窗口中，如果`nums[j] > nums[i]`且`j > i`，则`i`的信息不需要保存，因为`nums[j]`不仅比`nums[i]`更加有用，而且`nums[i]`会后从窗口中被摒弃。如果`nums[j] == nums[i]`，则这两个值都需要被保留，因为一个被摒弃之后，另外一个可能成为窗口中的最大值。

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dqu;
        vector<int> res;
        
        int i = 0;
        while(i < k && i < nums.size()) {
            while(!dqu.empty() && dqu.back() < nums[i]) {
                dqu.pop_back();
            }
            dqu.push_back(nums[i]);
            i++;
        }
        int j = 0;
        while(i < nums.size()) {
            //找到窗口的最大值
            res.push_back(dqu.front());
            
            // pop
            if(!dqu.empty() && dqu.front() == nums[j])
                dqu.pop_front();
            j++;
            
            //push
            while(!dqu.empty() && dqu.back() < nums[i]) {
                dqu.pop_back();
            }
            dqu.push_back(nums[i]);
            i++;
        }
        res.push_back(dqu.front());
        return res;
    }
};
```



**单调队列模板**：

> 单调队列里的pop和push接口，仅适用于本题。单调队列不是一成不变的，而是不同场景不同写法，总之要**保证队列里单调递减或递增的原则**，所以叫做单调队列。 不要以为本地中的单调队列实现就是固定的写法。

```c++
class MyQueue { //单调队列（从大到小）
public:
    deque<int> que; // 使用deque来实现单调队列
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value) {
        if (!que.empty() && value == que.front()) {
            que.pop_front();
        }
    }
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value) {
        while (!que.empty() && value > que.back()) {
            que.pop_back();
        }
        que.push_back(value);

    }
    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front() {
        return que.front();
    }
};

```



# 347.前K个高频元素

**优先队列**：**披着队列外衣的堆**，因为优先级队列对外接口只是从**队头取元素**，从**队尾添加元素**，再无其他取元素的方式，看起来就是一个队列。

大顶堆（堆头是最大元素），小顶堆（堆头是最小元素）



写快排的cmp函数的时候，`return left>right` 就是从大到小，`return left<right` 就是从小到大。

**优先级队列的定义正好反过来了**

```c++
typedef struct node {
    int val;
    int num;
    Node(int v, int n): val(v), num(n){}
}Node;

struct cmp {
    bool operator() (Node a, Node b) {
        return a.num > b.num;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<Node, vector<Node>, cmp> pq;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] ++;
        }

        vector<int> res;
        auto it = mp.begin();
        while(k--) {
            pq.push(Node(it->first, it->second));
            it++;
        }

        while(it != mp.end()) {
            if(pq.top().num < it->second) {
                pq.pop();
                pq.push(Node(it->first, it->second));
            }
            it++;
        }
        while(!pq.empty()) {
            res.push_back(pq.top().val);
            pq.pop();
        }
        return res;
    }
};
```



下面的代码是copy的，更规范一点，学习学习

`pri_que.push(*it);`

`*it`是`pair<int, int>`

```c++
// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);   // 还可以这样
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
```























