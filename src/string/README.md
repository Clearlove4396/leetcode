# 344.反转字符串

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
```



# 541.反转字符串II

两年前，写了几十行代码才解决问题，现在就几行，嘿嘿

```c++
class Solution {
public:
    string reverseStr(string s, int k)
    {
        string rec = "";

        int count = 1;
        int begin = 0;
        while(count * 2 * k <= s.size())
        {
            string str = s.substr(begin, 2 * k);
            begin = count * 2 * k;
            count++;
            int i = k - 1;
            while(i >= 0)
            {
                rec = rec + str[i];
                i--;
            }
            rec = rec + str.substr(k, str.size());
        }
        string str = s.substr(begin, s.size() - begin);
        if(str.size() < k)
        {
            reverse(str.begin(), str.end());
            rec = rec + str;
        }
        else
        {
            int i = k - 1;
            while(i >= 0)
            {
                rec = rec + str[i];
                i--;
            }
            rec = rec + str.substr(k, str.size());
        }
        return rec;
    }
};
```



```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2*k) {
            int ii = i, j = i + k - 1;
            if(j > s.size() - 1) {
                j = s.size() - 1;
            }
            while(ii < j) {
                std::swap(s[ii++], s[j--]);
            }
        }
        return s;
    }
};
```



# 剑指Offer 05.替换空格

```c++
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for(char c: s) {
            if(c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
};
```

不使用额外空间：先统计空格的个数，然后扩展`s`的尺寸，最后**从后向前遍历字符串**

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int c = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                c++;
        }
        int len = s.size();
        int resLen = s.size() + c * 2;
        s.resize(resLen);
        
        int j = resLen - 1;
        for(int i = len - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            else {
                s[j--] = s[i];
            }
        }
        return s;
    }
};
```



# 151.翻转字符串里的单词

在首尾先提前加一个空格，然后每次遇到空格的时候，就把之前收集到的字母链接到结果字符串中。

```c++
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        s = " " + s + " ";
        
        string tmp = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(tmp != "") {
                    reverse(tmp.begin(), tmp.end());
                    res += tmp + " ";
                    tmp = "";
                }
            }
            else{
                tmp += s[i];
            }
        }
        return res == ""? res: res.substr(0, res.size() - 1);
    }
};
```



# 剑指Offer 58 II左旋转字符串

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
        for(int i = 0, j = s.size() - n - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
        for(int i = s.size() - n, j = s.size() - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
        return s;
    }
};
```

