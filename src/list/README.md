

## 203.移除链表元素

增加**虚拟头结点**`ListNode* dummy = new ListNode(0, head);`，可以使`head`节点和后面的节点按照相同的算法处理。

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* p = dummy;
        while(p->next != nullptr) {
            if(p->next->val == val) {
                p->next = p->next->next;
                
                // ListNode *tmp = p->next;
                // p->next = tmp->next;
                // free(tmp);
            }
            else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};
```



## 707.设计链表

链表的插入、删除等操作



只增加虚拟头结点`dummy`就好了，千万别加尾节点`rear`:frowning_face:

```c++
class MyLinkedList {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new ListNode();
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= len)
            return -1;
        ListNode* p = dummy->next;
        while(index--) {
            p = p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = dummy->next;
        dummy->next = tmp;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *tmp = new ListNode(val);
        ListNode* p = dummy;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > len)
            return;
        if(index < 0)
            addAtHead(val);
        else if(index == len)
            addAtTail(val);
        else {
            ListNode* p = dummy;
            while(index--) {
                p = p->next;
            }
            ListNode* tmp = new ListNode(val);
            tmp->next = p->next;
            p->next = tmp;
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len || index < 0)
            return;
        ListNode *p = dummy;
        while(index--) {
            p = p->next;
        }
        p->next = p->next->next;
        len--;
    }

private:
    ListNode* dummy;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```



## 206.反转链表

双指针方法

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = nullptr, *pre = head;
        while(pre != nullptr) {
            ListNode* tmp = pre->next;
            pre->next = p;
            p = pre;
            pre = tmp;
        }
        return p;
    }
};
```

递归方法

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* p = head->next;
        head->next = nullptr;
        ListNode* reverseHead = reverseList(p);
        p->next = head;

        return reverseHead;
    }
};
```



## 24.两两交换链表中的节点



```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* p = head, *q = head;

        while(p != nullptr) {
            q = p->next;
            if(q == nullptr) {
                break;
            }
            ListNode* rear = q->next;
            pre->next = q;
            q->next = p;
            p->next = rear;

            pre = p;
            p = q = rear;
        }
        return dummy->next;
    }
};
```



## 19.删除链表的倒数第N个节点



```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p = dummy;
        ListNode* pre = dummy;
        while(n--) {
            p = p->next;
        }

        while(p->next != nullptr) {
            pre = pre->next;
            p = p->next;
        }
        
        pre->next = pre->next->next;
        return dummy->next;
    }
};
```



## 142.环形链表II

双指针方法：空间复杂度$O(1)$

双指针方法的数学推导可以参考：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md

该文章在附录I中。

```c++
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return head;

        ListNode* slow = head, *fast = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast == nullptr)
                break;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast == nullptr)
            return nullptr;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
```

使用`hash`表做标记，空间复杂度$O(n)$

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return head;

        unordered_set<ListNode* > st;
        ListNode* p = head;
        while(p != nullptr) {
            if(st.find(p) != st.end())
                break;
            st.insert(p);
            p = p->next;
        }
        return p;
    }
};

```





## 附录I：环形链表的数学推导

### 判断链表是否有环

可以使用快慢指针法， 分别定义 fast 和 slow指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内相遇呢，而不是永远的错开呢

首先第一点： **fast指针一定先进入环中，如果fast 指针和slow指针相遇的话，一定是在环中相遇，这是毋庸置疑的。**

那么来看一下，**为什么fast指针和slow指针一定会相遇呢？**

可以画一个环，然后让 fast指针在任意一个节点开始追赶slow指针。

会发现最终都是这种情况， 如下图：

[![142环形链表1](https://camo.githubusercontent.com/3ec305ed155e977e1e0d4ebd60b736b9aeec00165def5f21e1061ff99bcbf12e/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303331383136323233363732302e706e67)](https://camo.githubusercontent.com/3ec305ed155e977e1e0d4ebd60b736b9aeec00165def5f21e1061ff99bcbf12e/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303331383136323233363732302e706e67)

fast和slow各自再走一步， fast和slow就相遇了

这是因为fast是走两步，slow是走一步，**其实相对于slow来说，fast是一个节点一个节点的靠近slow的**，所以fast一定可以和slow重合。

动画如下：

[![141.环形链表](https://camo.githubusercontent.com/a34c992347976733ef3a34e19202a2248ef6b72a24f55f08bd27aa51dbaedc55/68747470733a2f2f747661312e73696e61696d672e636e2f6c617267652f30303865476d5a456c7931676f6f3478676c6b397967333066733062367530782e676966)](https://camo.githubusercontent.com/a34c992347976733ef3a34e19202a2248ef6b72a24f55f08bd27aa51dbaedc55/68747470733a2f2f747661312e73696e61696d672e636e2f6c617267652f30303865476d5a456c7931676f6f3478676c6b397967333066733062367530782e676966)

### 如果有环，如何找到这个环的入口

**此时已经可以判断链表是否有环了，那么接下来要找这个环的入口了。**

假设从头结点到环形入口节点 的节点数为x。 环形入口节点到 fast指针与slow指针相遇节点 节点数为y。 从相遇节点 再到环形入口节点节点数为 z。 如图所示：

[![142环形链表2](https://camo.githubusercontent.com/0c6e7f151c5324fca67245440e3f15d76209496a3744604287feff7226645f4e/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303331383136323933383339372e706e67)](https://camo.githubusercontent.com/0c6e7f151c5324fca67245440e3f15d76209496a3744604287feff7226645f4e/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303331383136323933383339372e706e67)

那么相遇时： slow指针走过的节点数为: `x + y`， fast指针走过的节点数：` x + y + n (y + z)`，n为fast指针在环内走了n圈才遇到slow指针， （y+z）为 一圈内节点的个数A。

因为fast指针是一步走两个节点，slow指针一步走一个节点， 所以 fast指针走过的节点数 = slow指针走过的节点数 * 2：

```
(x + y) * 2 = x + y + n (y + z)
```

两边消掉一个（x+y）: `x + y = n (y + z)`

因为要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。

所以要求x ，将x单独放在左面：`x = n (y + z) - y` ,

再从n(y+z)中提出一个 （y+z）来，整理公式之后为如下公式：`x = (n - 1) (y + z) + z `注意这里n一定是大于等于1的，因为 fast指针至少要多走一圈才能相遇slow指针。

这个公式说明什么呢？

先拿n为1的情况来举例，意味着fast指针在环形里转了一圈之后，就遇到了 slow指针了。

当 n为1的时候，公式就化解为 `x = z`，

这就意味着，**从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点**。

也就是在相遇节点处，定义一个指针index1，在头结点处定一个指针index2。

让index1和index2同时移动，每次移动一个节点， 那么他们相遇的地方就是 环形入口的节点。

动画如下：

[![142.环形链表II（求入口）](https://camo.githubusercontent.com/1b5bd012c476c747f6b783fa53a5f5a7cc50ef750ddbc40177b44043198650e5/68747470733a2f2f747661312e73696e61696d672e636e2f6c617267652f30303865476d5a456c7931676f6f3538676175696467333066773062693471722e676966)](https://camo.githubusercontent.com/1b5bd012c476c747f6b783fa53a5f5a7cc50ef750ddbc40177b44043198650e5/68747470733a2f2f747661312e73696e61696d672e636e2f6c617267652f30303865476d5a456c7931676f6f3538676175696467333066773062693471722e676966)

那么 n如果大于1是什么情况呢，就是fast指针在环形转n圈之后才遇到 slow指针。

其实这种情况和n为1的时候 效果是一样的，一样可以通过这个方法找到 环形的入口节点，只不过，index1 指针在环里 多转了(n-1)圈，然后再遇到index2，相遇点依然是环形的入口节点。

代码如下：

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};
```

### 补充

在推理过程中，大家可能有一个疑问就是：**为什么第一次在环中相遇，slow的 步数 是 x+y 而不是 x + 若干环的长度 + y 呢？**

即文章[链表：环找到了，那入口呢？](https://mp.weixin.qq.com/s/_QVP3IkRZWx9zIpQRgajzA)中如下的地方：

[![142环形链表5](https://camo.githubusercontent.com/5a9e3167c175ac53de53eff982a681c3ddbb8bcc24ecd5ea494ded42a2d87a3c/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303331383136353132333538312e706e67)](https://camo.githubusercontent.com/5a9e3167c175ac53de53eff982a681c3ddbb8bcc24ecd5ea494ded42a2d87a3c/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303331383136353132333538312e706e67)

首先slow进环的时候，fast一定是先进环来了。

如果slow进环入口，fast也在环入口，那么把这个环展开成直线，就是如下图的样子：

[![142环形链表3](https://camo.githubusercontent.com/59852323777b9828df5b584d701e9639099565298ca72a06d5aac0110074a723/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f323032313033313831363530333236362e706e67)](https://camo.githubusercontent.com/59852323777b9828df5b584d701e9639099565298ca72a06d5aac0110074a723/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f323032313033313831363530333236362e706e67)

可以看出如果slow 和 fast同时在环入口开始走，一定会在环入口3相遇，slow走了一圈，fast走了两圈。

重点来了，slow进环的时候，fast一定是在环的任意一个位置，如图：

[![142环形链表4](https://camo.githubusercontent.com/2c934e7bf6bcd745ad6ffb2b047a08e98ad5a61a60f96a637483b38e35c9369c/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f323032313033313831363531353732372e706e67)](https://camo.githubusercontent.com/2c934e7bf6bcd745ad6ffb2b047a08e98ad5a61a60f96a637483b38e35c9369c/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f323032313033313831363531353732372e706e67)

那么fast指针走到环入口3的时候，已经走了k + n 个节点，slow相应的应该走了(k + n) / 2 个节点。

因为k是小于n的（图中可以看出），所以(k + n) / 2 一定小于n。

**也就是说slow一定没有走到环入口3，而fast已经到环入口3了**。

这说明什么呢？

**在slow开始走的那一环已经和fast相遇了**。

那有同学又说了，为什么fast不能跳过去呢？ 在刚刚已经说过一次了，**fast相对于slow是一次移动一个节点，所以不可能跳过去**。