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



























