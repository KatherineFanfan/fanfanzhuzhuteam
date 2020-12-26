# 刷题笔记

[TOC]

## Heap

### 1642. Furthest Building You Can Reach

Given the number of bricks and ladders

Keep a min heap which has the same size of ladders. If the size is larger than ladders', pop the smallest difference, which is on the top of the min heap. The number of bricks is substracted by the pop number.



## Graph

### 1631. Path With Minimum Effort

Dijstra算法 无向有权图，求单源最短路径



## DP

### 1621. Number of Sets of K Non-Overlapping Line Segments

![image-20201122142502968](/Users/katherine/Library/Application Support/typora-user-images/image-20201122142502968.png)

n = 4, k =2, ans = 5

`dp[i][0] = 0`

`dp[i][1]= i * (i+1) / 2`

`dp[i][j] = dp[i-1][j] + sum(dp[i-1][j-1], dp[i-2][j-1], ..., dp[j][j-1])`

时间复杂度o(nk)



## String

### Palindrome

### 1616. Split Two Strings to Make Palindrome

从a的开头和b的结尾开始two pointer找same substring

**剩下的部分**判断s[left:right]是否为palindrome 



## DFS

### 1593. Split a String Into the Max Number of Unique Substrings

典型的dfs，注意时间复杂度为2^n





## 12.2

1573 Number of Ways to Split a String (math)

1558 Minimum Numbers of Function Calls to Make Target Array (Bit)

1530 Number of Good Leaf Nodes Pairs (tree)



## 12.3

1520 Maximum Number of Non-Overlapping Substrings （Greedy）

1508 Range Sum of Sorted Subarray Sums (array)

* brute force o(n * n * logn)
* Minheap  存以n个结点开头的数组{}，按sum从小到大排序  节省空间为o(n)
* binary search 





## Set

set<int> suns;

auto it = suns.upper_bound(num) // 返回set中>num的第一个元素的迭代器

*it 是元素的位置

suns.erase(iterator) or suns.erase(element);  // 删除元素

suns.insert(element) // add



## Priority_queue

struct CustomCompare {    

​	bool operator()(const int**&** lhs, const int**&** rhs) const   {

​        return lhs **<** rhs;    

​	} 

};

priority_queue**<**int,vector**<**int**>**, CustomCompare **>** pq;

默认是最大堆；

最小堆 = greater = return (a > b)

## Vector

int initial = 4;

vector<int> data;

data.**resize**(3);

std::**iota**(begin(data), end(data), initial);  // 填充data begin->end 从initial开始单调递增复制 4，5，6





## Fenwick Tree

解决 求array中 （i, j）的sum，如果arr是动态的，那么不能用prefiix sum来求 -> fenwick tree

query o(logn)

update o(logn)



## Union Find Set

Examples: 1319

