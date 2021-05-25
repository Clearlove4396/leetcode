# 基本理论

## 遍历方式

- 深度优先遍历
  - 前序遍历
  - 中序遍历
  - 后序遍历
- 广度优先遍历
  - 层次遍历

## 二叉树的递归遍历

二叉树的非递归遍历可以统一起来，看下面的代码。

因为中序和后序遍历时，看到一个节点之后，不是立刻放在结果集中（第二次“看到”该节点时才放入结果集中），所以需要使用一个`bool`量做标记。



**递归三要素**

1. **确定递归函数的参数和返回值：** 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
2. **确定终止条件：** 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
3. **确定单层递归的逻辑：** 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。



# 二叉树的深度优先遍历



## 144.二叉树的前序遍历

递归 & 非递归

```c++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // 递归
    void preOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    // 非递归
    vector<int> preOrder(TreeNode* root){
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<TreeNode* > stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            if(top->right)  stk.push(top->right);
            if(top->left)   stk.push(top->left);
        }

        return res;
    }

    // 统一风格的 非递归遍历
    vector<int> preOrder_sta(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                if((top.first)->right)  stk.push(make_pair((top.first)->right, false));
                if((top.first)->left)   stk.push(make_pair((top.first)->left, false));
                stk.push(make_pair(top.first, true));
            }
            else
                res.push_back((top.first)->val);
        }
        return res;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> res;
        // preOrder(root, res);
        // return res;

        return preOrder_sta(root);
    }
};
```



## 94.二叉树的中序遍历

递归 & 非递归

```c++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // 递归
    void inOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;

        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    // 非递归
    vector<int> inOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                if((top.first)->right != nullptr)
                    stk.push(make_pair((top.first)->right, false));
                stk.push(make_pair(top.first, true));
                if((top.first)->left != nullptr)
                    stk.push(make_pair((top.first)->left, false));
            }
            else
                res.push_back((top.first)->val);
        }

        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> res;
        // inOrder(root, res);
        // return res;

        return inOrder(root);
    }
};
```



## 145.二叉树的后序遍历

递归 & 非递归

```c++
class Solution {
public:
    // 递归
    void postOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr)
            return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }

    // 非递归
    vector<int> postOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> res;
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                stk.push(make_pair(top.first, true));
                if((top.first)->right)  stk.push(make_pair((top.first)->right, false));
                if((top.first)->left)   stk.push(make_pair((top.first)->left, false));
            }
            else
                res.push_back((top.first)->val);
        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;
        // postOrder(root, res);
        // return res;

        return postOrder(root);
    }
};
```



# 二叉树的层序遍历



## 102.二叉树的层序遍历

使用`queue`

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<vector<int> > res;
        queue<TreeNode* > qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();   // 记录每一层的个数
            vector<int> tmp;
            while(size--) {
                TreeNode* top = qu.front();
                qu.pop();

                tmp.push_back(top->val);
                if(top->left != nullptr)    qu.push(top->left);
                if(top->right != nullptr)    qu.push(top->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```



## 107.二叉树的层次遍历II



```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<vector<int> > res;

        queue<TreeNode* > qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int> tmp;
            while(size--) {
                TreeNode* top = qu.front();
                qu.pop();

                tmp.push_back(top->val);
                if(top->left != nullptr)    qu.push(top->left);
                if(top->right != nullptr)    qu.push(top->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```



## 199.二叉树的右视图



```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode* > qu;

        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top->left != nullptr)    qu.push(top->left);
                if(top->right != nullptr)   qu.push(top->right);
                if(size == 0)
                    res.push_back(top->val);
            }
        }
        return res;
    }
};
```



## 637.二叉树的层平均值

```c++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<TreeNode* > qu;
        vector<double> res;

        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            double t = 0;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                t += top->val;
                if(top->left)   qu.push(top->left);
                if(top->right)  qu.push(top->right);
            }
            res.push_back(t / size);
        }
        return res;
    }
};
```



## 429.N叉树的层序遍历

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int> > res;
        queue<Node* > qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int> tmp;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                tmp.push_back(top->val);
                for(Node* node: top->children) {
                    qu.push(node);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```

## 515.在每个树行中找最大值

```c++
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<TreeNode* > qu;
        vector<int> res;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            int maxVal = INT_MIN;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top->val > maxVal)
                    maxVal = top->val;
                if(top->left != nullptr)
                    qu.push(top->left);
                if(top->right != nullptr)
                    qu.push(top->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
```



## 116.填充每个节点的下一个右侧节点指针

层序遍历方法

```c++
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<Node* > qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(size != 0) {
                    top->next = qu.front();
                }
                if(top->left != nullptr)
                    qu.push(top->left);
                if(top->right != nullptr)
                    qu.push(top->right);
            }
        }
        return root;
    }
};
```



递归方法

此时空间复杂度为$O(1)$，满足题目要求

```c++
class Solution {
public:
    
    void func(Node* l, Node* r){
        if(l == nullptr && r == nullptr)
            return;
        if(l != nullptr){
            l->next = r;
            func(l->left, l->right);
        }
        if(r != nullptr){
            func(r->left, r->right);
        }
        if(l != nullptr && r != nullptr)
            func(l->right, r->left);
    }
    
    
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        func(nullptr, root);
        return root;
    }
};
```



## 117.填充每个节点的下一个右侧节点指针II

层序遍历方法同上



**递归方法：**

在连接`root`节点下一层的时候，可以通过`root->next`获取到`root`同一层的右侧节点。

```c++
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        if(root->left != nullptr && root->right != nullptr)
            root->left->next = root->right;

        if(root->left != nullptr && root->right == nullptr)
            root->left->next = getNext(root->next);

        if(root->right != nullptr)
            root->right->next = getNext(root->next);

        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* getNext(Node* root) {
        if(root == nullptr)
            return nullptr;
        if(root->left != nullptr)
            return root->left;
        if(root->right != nullptr)
            return root->right;
        if(root->next != nullptr)
            return getNext(root->next);
        return nullptr;
    }
};
```



# 二叉树的属性



## 101.对称二叉树

递归

```c++
class Solution {
public:
    bool func(TreeNode* l, TreeNode* r) {
        if(l == nullptr && r == nullptr)
            return true;
        
        // if(l == nullptr && r != nullptr || l != nullptr && r == nullptr)
        //     return false;
        
        // if(l->val != r->val)
        //     return false;

        if(l == nullptr || r == nullptr || l->val != r->val)
            return false;
        
        return func(l->left, r->right) && func(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return func(root, root);
    }
};
```



迭代

使用`#`替代空节点。

```c++
class Solution {
public:

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        queue<TreeNode* > qu;
        qu.push(root);
        bool flag = true;
        while(!qu.empty() && flag) {
            int size = qu.size();
            vector<string> tmp;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top == nullptr) {
                    tmp.push_back("#");
                    continue;
                }
                flag = true;
                qu.push(top->left);
                qu.push(top->right);
                tmp.push_back(to_string(top->val));
            }

            for(int i = 0, j = tmp.size() - 1; i < j; i++, j--) {
                if(tmp[i] != tmp[j])
                    return false;
            }
        }
        return true;
    }
};
```

迭代

不保存空节点

```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root.left);
        queue.offer(root.right);

        while (!queue.isEmpty()) {
            TreeNode node1 = queue.poll();
            TreeNode node2 = queue.poll();
            if (node1 == null && node2 == null) {
                continue;
            }
            if (node1 == null || node2 == null || node1.val != node2.val) {
                return false;
            }
            queue.offer(node1.left);
            queue.offer(node2.right);
            queue.offer(node1.right);
            queue.offer(node2.left);
        }

        return true;
    }
}
```



## 104.二叉树的最大深度

递归

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

迭代：层次遍历，对层数进行计数就好了。



## 559.N叉树的最大深度

递归

```c++
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        int max = 0;
        for(int i = 0; i < root->children.size(); i++) {
            max = std::max(max, maxDepth((root->children)[i]));
        }
        return 1 + max;
    }
};
```



迭代：层序遍历

**迭代**：基于栈的迭代的后序遍历。`dep`记录局部最优解，`res`记录全局最优解。

```c++
class Solution {
public:

    typedef struct st_node{
        Node* pointer;
        bool flag;
        st_node(Node* p): pointer(p), flag(false){}
    };

    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        
        stack<st_node> stk;
        stk.push(st_node(root));
        int res = 0;
        int dep = 0;
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.flag == false) {
                top.flag = true;
                stk.push(top);
                for(auto pointer: top.pointer->children) {
                    stk.push(st_node(pointer));
                }
                dep++;
            }
            else {
                res = std::max(res, dep);
                dep--;
            }
        }
        return res;
    }
};
```



## 111.二叉树的最小深度

递归

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        int leftDep = minDepth(root->left);
        int rightDep = minDepth(root->right);

        if(root->left != nullptr && root->right == nullptr)
            return 1 + leftDep;
        if(root->left == nullptr && root->right != nullptr)
            return 1 + rightDep;
        
        return 1 + std::min(leftDep, rightDep);
    }
};
```



深度优先遍历：使用`stack`的迭代版

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        int res = INT_MAX;
        int dep = 0;
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                top.second = true;
                stk.push(top);
                if((top.first)->left != nullptr)
                    stk.push(make_pair((top.first)->left, false));
                if((top.first)->right != nullptr)
                    stk.push(make_pair((top.first)->right, false));
                dep++;
            }
            else {
                if((top.first)->left == nullptr && (top.first)->right == nullptr) {
                    res = std::min(res, dep);
                }
                dep--;
            }
        }
        return res;
    }
};
```



或者使用层序遍历：当第一次出现`left == nullptr && right == nullptr`的节点时，返回结果。

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        queue<TreeNode* > qu;
        qu.push(root);
        int res = 0;
        while(!qu.empty()) {
            int size = qu.size();
            res++;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(top->left == nullptr && top->right == nullptr)
                    return res;
                if(top->left != nullptr)
                    qu.push(top->left);
                if(top->right != nullptr)
                    qu.push(top->right);
            }
        }
        return res;
    }
};
```



## 222.完全二叉树的节点个数

递归：遍历所有节点，时间复杂度$O(n)$

```c++
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```



根据完全二叉树的性质：完全二叉树   满二叉树

时间复杂度$O(logn·logn)$

![copy自代码随想录](https://camo.githubusercontent.com/5d85c9f8df419ce8db22f668ff22f7a3ae55660b8e9bead3b98e2d8cdd69ac9c/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303230313132343039323534333636322e706e67)



![](https://camo.githubusercontent.com/9dda2135e7216b78bcd3d71377dfa37ae7dc8b262add58376383c58db9e3c97a/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303230313132343039323633343133382e706e67)



```c++
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int ldep = 0, rdep = 0;
        TreeNode* lnode = root->left;
        while(lnode) {
            lnode = lnode->left;
            ldep++;
        }
        TreeNode* rnode = root->right;
        while(rnode) {
            rnode = rnode->right;
            rdep++;
        }
		// 2: 0010
        if(ldep == rdep)
            return (2 << ldep) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```



## 110.平衡二叉树

递归：后序遍历，时间复杂度$O(n)$

`depthAndBalance`函数既可以获得高度（通过返回值），又可以判断现在是否平衡（`bool& res`)。也可以通过返回`-1`来判断是否平衡。

```c++
class Solution {
public:

    int depthAndBalance(TreeNode* root, bool& res) {
        if(root == nullptr)
            return 0;
        
        int leftDep = depthAndBalance(root->left, res);
        int rightDep = depthAndBalance(root->right, res);
        if(abs(leftDep - rightDep) > 1)
            res = false;
        
        return std::max(leftDep, rightDep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        bool res = true;
        depthAndBalance(root, res);
        return res;
    }
};
```



```c++
class Solution {
public:

    int depthAndBalance(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int leftDep = depthAndBalance(root->left);
        int rightDep = depthAndBalance(root->right);
        if(leftDep == -1 || rightDep == -1 || abs(leftDep - rightDep) > 1)
            return -1;
        
        return std::max(leftDep, rightDep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int res = depthAndBalance(root);
        return res == -1? false: true;
    }
};
```



## 257.二叉树的所有路径

深度优先遍历：前序遍历

使用`string&& ss`可以不`pop_back()`

`string&& `可以想象成**临时的，即将消亡的**。

```c++
class Solution {
public:
    void func(TreeNode* root, vector<string>& res, string&& ss) {
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr) {
            res.push_back(ss + "->" + to_string(root->val));
            return;
        }

        func(root->left, res, ss + "->" + to_string(root->val));
        func(root->right, res, ss + "->" + to_string(root->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return {};
        if(root->left == nullptr && root->right == nullptr)
            return {to_string(root->val)};

        vector<string> res;
        func(root->left, res, to_string(root->val));
        func(root->right, res, to_string(root->val));
        return res;
    }
};
```



## 100.相同的树

利用短路特性

```c++
if(p == nullptr && q == nullptr)
	return true;
if(p == nullptr || q == nullptr || p->val != q->val)
	return false;
```



```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr || q == nullptr || p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```



## 572.另一个树的子树

嵌套的两次前序遍历

```c++
class Solution {
public:

    bool func(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)
            return true;
        if(root == nullptr || subRoot == nullptr || root->val != subRoot->val)
            return false;
        
        return func(root->left, subRoot->left) && func(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr ||
         root != nullptr && subRoot == nullptr)
            return true;
        if(root == nullptr && subRoot != nullptr)
            return false;

        return func(root, subRoot) ||
             isSubtree(root->left, subRoot) ||
             isSubtree(root->right, subRoot);
    }
};
```



## 404.左叶子之和



```c++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr)
            return sumOfLeftLeaves(root->right);

        if(root->left->left == nullptr && root->left->right == nullptr)
            return root->left->val + sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```





## 513.找树左下角的值

层序遍历

```c++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* >qu;
        qu.push(root);
        int res;
        while(!qu.empty()) {
            int size = qu.size();
            bool update = false;
            while(size--) {
                auto top = qu.front();
                qu.pop();
                if(!update) {
                    update = true;
                    res = top->val;
                }
                if(top->left)
                    qu.push(top->left);
                if(top->right)
                    qu.push(top->right);
            }
            update = false;
        }
        return res;
    }
};
```



深度优先搜索：迭代，先序遍历

```c++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        
        int curdep = 0;
        int maxdep = 0;
        int res = root->val;

        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();

            if(top.second == false) {
                top.second = true;
                stk.push(top);
                if((top.first)->right)
                    stk.push(make_pair((top.first)->right, false));
                if((top.first)->left)
                    stk.push(make_pair((top.first)->left, false));
                
                curdep++;
            }
            else {
                if(maxdep < curdep) {
                    maxdep = curdep;
                    res = (top.first)->val;
                }
                curdep--;
            }
        }
        return res;
    }
};
```



**深度优先遍历：使用`dep`记录当前遍历的深度**

```c++
class Solution {
public:
    int maxdep = INT_MIN;
    int res;

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int dep) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr) {
            if(dep > maxdep) {
                maxdep = dep;
                res = root->val;
            }
        }
        dfs(root->left, dep + 1);
        dfs(root->right, dep + 1);
    }
};
```





## 112.路径总和

递归函数，什么时候需要返回值，什么时候不需要呢？

**如果需要搜索整颗二叉树，那么递归函数就不要返回值，如果要搜索其中一条符合条件的路径，递归函数就需要返回值，因为遇到符合条件的路径了就要及时返回。**

上面的话copy自：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.md

感觉还是要靠自己体会吧，不需要死搬硬套。不过有了这句话，可以给自己一个指引，

```c++
class Solution {
public:

    void func(TreeNode* root, int& targetSum, bool& res) {
        if(root == nullptr)
            return;
        if(res == true)
            return;

        if(targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            res = true;
            return;
        }

        targetSum -= root->val;
        func(root->left, targetSum, res);
        if(res == false)
            func(root->right, targetSum, res);
        
        targetSum += root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        func(root, targetSum, res);
        return res;
    }
};
```



## 113.路径总和II

递归+回溯

```c++
class Solution {
public:

    void func(TreeNode* root, int targetSum, vector<vector<int> >& res, vector<int>& path) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        func(root->left, targetSum - root->val, res, path);
        func(root->right, targetSum - root->val, res, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > res;
        vector<int> path;
        
        func(root, targetSum, res, path);

        return res;
    }
};
```



# 二叉树的修改和构造

## 106.从中序与后序遍历序列构造二叉树

```c++
class Solution {
public:
    TreeNode* func(vector<int>& inorder, vector<int>& postorder, int li, int ri, int lp, int rp) {
        if(li > ri)
            return nullptr;
        
        TreeNode* node = new TreeNode(postorder[rp]);
        int i = li;
        while(i < ri && inorder[i] != postorder[rp])
            i++;
        node->left = func(inorder, postorder, li, i - 1, lp, lp + (i - li) - 1);
        node->right = func(inorder, postorder, i + 1, ri, lp + (i - li), rp - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return nullptr;
        
        return func(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
```



## 105.从前序与中序遍历序列构造二叉树

```c++
class Solution {
public:

    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri) {
        if(lp > rp)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[lp]);
        int i = li;
        while(i < rp && preorder[lp] != inorder[i])
            i++;
        node->left = func(preorder, inorder, lp + 1, lp + (i - li), li, i - 1);
        node->right = func(preorder, inorder, lp + (i - li) + 1, rp, i + 1, ri);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return nullptr;

        return func(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
```



## 654.最大二叉树

```c++
class Solution {
public:
    TreeNode* func(vector<int>& nums, int l, int r) {
        if(l > r)
            return nullptr;
        int idx = l;
        int max = -1;
        for(int i = l; i <= r; i++) {
            if(max < nums[i]) {
                max = nums[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(nums[idx]);
        root->left = func(nums, l, idx - 1);
        root->right = func(nums, idx + 1, r);

        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;

        return func(nums, 0, nums.size() - 1);
    }
};
```



## 617.合并二叉树

```c++
class Solution {
public:
    void func(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr)
            return;
            
        if(root1->left == nullptr) {
            root1->left = root2->left;
            root2->left = nullptr;
        }
        else if(root2->left != nullptr) {
            root1->left->val += root2->left->val;
        }

        if(root1->right == nullptr) {
            root1->right = root2->right;
            root2->right = nullptr;
        }
        else if(root2->right != nullptr) {
            root1->right->val += root2->right->val;
        }

        func(root1->left, root2->left);
        func(root1->right, root2->right);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr)
            return root2;
        if(root2 == nullptr)
            return root1;

        root1->val += root2->val;
        func(root1, root2);
        
        return root1;
    }
};
```



```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;

        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};
```



# 二叉搜索树的属性

二叉搜索树是一个有序树：

- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
- 它的左、右子树也分别为二叉搜索树



## 700.二叉搜索树中的搜索

```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        if(root->val == val)
            return root;
        if(root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};
```



## 98.验证二叉搜索树

可以先获得中序遍历序列，然后判断该序列是否单调递增

```c++
class Solution {
public:

    void func(TreeNode* root, vector<int>& res) {
        if(root != nullptr) {
            func(root->left, res);
            res.push_back(root->val);
            func(root->right, res);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        func(root, res);

        for(int i = 0; i < res.size() - 1; i++) {
            if(res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
};
```



递归

遍历到每个节点之前，需要记住该节点值应该在的范围。向左时，缩小最大值，向右时，增大最小值。

```c++
class Solution {
public:
    bool func(TreeNode* root, long long min, long long max) {
        if(root == nullptr)
            return true;
        if(root->val <= min || root->val >= max)
            return false;
        
        return func(root->left, min, root->val)
             && func(root->right, root->val, max);
        
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        long long min = INT_MIN;
        long long max = INT_MAX;

        return func(root, min - 1, max + 1);
    }
};
```



## 530.二叉搜索树的最小绝对差

中序遍历，序列是单调递增的，在出栈的时候，计算绝对值的最小值

```c++
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int f, r, res = INT_MAX;
        int c = 0;

        stack<pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if(top.second == false) {
                if((top.first)->left)
                    stk.push(make_pair((top.first)->left, false));
                stk.push(make_pair(top.first, true));
                if((top.first)->right)
                    stk.push(make_pair((top.first)->right, false));
            }
            else {
                if(c > 1) {
                    if(res > abs(r - f))
                        res = abs(r - f);
                    f = r;
                    r = (top.first)->val;
                }
                else if(c == 0){
                    c++;
                    f = (top.first)->val;
                }
                else {
                    c++;
                    r = (top.first)->val;
                }
            }
        }
        return abs(r - f) > res? res: abs(r - f);
    }
};
```



递归：中序遍历

题目中规定：每个节点的值是非负的。

```c++
class Solution {
public:
    void func(TreeNode* root, int& f, int& r, int& res) {
        if(root == nullptr)
            return;
        
        func(root->left, f, r, res);

        if(f == -1)
            f = root->val;
        else if(r == -1)
            r = root->val;
        else {
            if(res > abs(r - f))
                res = abs(r - f);
            f = r;
            r = root->val;
        }
        func(root->right, f, r, res);
    }

    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int f = -1, r = -1;

        func(root, f, r, res);
        return res > abs(r - f)? abs(r - f): res;
    }
};
```









## 501







## 538













# 二叉树公共祖先问题





# 二叉搜索树的修改与构造







































