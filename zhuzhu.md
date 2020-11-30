
## 11.21
#### 1593. Split a String Into the Max Number of Unique Substrings (ok)

#### 1573. Number of Ways to Split a String (ok)

#### 1530. Number of Good Leaf Nodes Pairs (ok)

#### 1534.Number of Subarrays With Odd Sum (ok)

#### 694. Number of Distinct Islands (ok)

#### 333. Largest BST Subtree (ok)

## 11.22
### new
#### 425. Word Squares (ok)

Tag: backtracking, hashmap, trie

#### 1095.	Find in Mountain Array (ok)
Tag: Binary Search
还是有些注意点的一道题

#### 1429.	First Unique Number (ok)

Tag: Hash Table, Design

非常类似于LRU cache

## 11.23
### new
#### 856. Score of Parentheses (ok)
Tag: Stack<br>
可以对照这Decode string一起来做。<br>
when see '(', push 0 into the s<br>
when see ')', pop the current value of '(...)' and add the value to the previous '()'<br>

#### 1249. Minimum Remove to Make Valid Parentheses
Tag: Stack<br>
Solution1: Stack(明天可以再做一下)<br>
// remove all invalid ')' <br>
when see '(', push i into the st<br>
when see ')', 1) st.empty() -> s.erase(s.begin() + i); i--; 2) st.pop();<br>
// remove all leftmost invalid '('<br>
while (!st.empty()) s.erase(s.begin() + st.top()); st.pop();<br>

Solution2: 明天整理一下思路。可以在面试的时候说得清楚一些<br>

#### 1614. Maximum Nesting Depth of the Parentheses
Tag: String<br>
### old
#### 723. Candy Crush (old)
Crushing Step:<br>
我们用negative sign表示可以crush的格子。这样的话，只需要判断连续三个绝对值是否相同。<br>
Gravity Step:<br>
Alternatively, we could use a sliding window approach, maintaining a read and write head.<br>
As the read head iterates through the column in reverse order, when the read head sees candy, the write head will write it down and move one place. Then, the write head will write zeroes to the remainder of the column.

            // drop
            for (int j = 0; j < col; j++) {
                int wr = row - 1;
                for (int i = row - 1; i >= 0; i--) {
                    if (board[i][j] > 0) {
                        board[wr][j] = board[i][j]; wr--;
                    }
                }
                while (wr >= 0) {
                    board[wr--][j] = 0;
                }
            }
            


## 11.24
### new

#### 1111. Maximum Nesting Depth of Two Valid Parentheses Strings (ok)
Tag: Greedy, String<br>

#### 1145. Binary Tree Coloring Game (ok)
Tag: Tree, DFS, BFS

#### 716. Max Stack (ok)
Tag: Map, Design, lined list<br>
并不觉得是easy难度的题目。。。design的题目都好难啊。

#### 1008. Construct Binary Search Tree from Preorder Traversal (ok)
用binary search tree的性质做。


### old

#### 394. Decode String (ok)
Tag: Stack, String<br>
一道常规老题了。需要借助两个stack，一个是number stack，一个是string stack。<br>
number: num = num * 10 + stoi(s[i]); <br>
char: cur += s[i]; <br>
[: numberStack.push(num); stringStack.push(cur); cur.clear(); num = 0; <br>
]: adds = cur; time = numberStack.top(); numberStack.pop(); stringStack.top() = stringStack.top() + time * adds; cur = stringStack.top(); stringStack.pop();<br>

#### 2. Add Two Numbers (ok)

#### 445. Add Two Numbers II (ok)
Tag: Linked list<br>
这道题是三道题的综合。reverse linked list, add strings, add two numbers<br>
Solution 1: reverse input + construct output by adding to front<br>
Solution 2: do not reverse the input. 1. sum the corresponding positions and build and output. 2. take care about the carry. 

### 128. Longest Consecutive Sequence (ok)
思路：剪枝方式（!set.count(*it - 1))进行判断。

#### 1047 . Remove All Adjacent Duplicates In String (ok)
思路：stack
#### 1209. Remove All Adjacent Duplicates in String II (ok)
思路：运用count来计数到现在为止有多少相同的字母了。然后进行删除。

#### 98. Validate Binary Search Tree (ok)
Solution 1: inorder traversal 然后判断array是不是从小到大排序的<br>
Solution 2: recursion 使用left and right value进行判断。注意边界条件。
#### 987. Vertical Order Traversal of a Binary Tree (ok)
可以跟314对照起来看。唯一的区别是。对于相同的x, y值。要排序。
#### 314. Binary Tree Vertical Order Traversal (ok)
Time complexity: O(N)<br>
降低时间复杂度的办法：用hashmap来存储vertical value。同时保存min vertical value and max vertical value。

#### 155. Min Stack (ok)
Tag: Stack

## 11.25
### new

#### 889. Construct Binary Tree from Preorder and Postorder Traversal (ok)
对照：105. Construct Binary Tree from Preorder and Inorder Traversal<br>
106. Construct Binary Tree from Inorder and Postorder Traversal<br>
889. Construct Binary Tree from Preorder and Postorder Traversal<br>

preorder: (root node) (preorder of left branch) (preorder of right branch) <br>
inorder: (inorder of left branch) (root node) (inorder of right branch) <br>
postorder: (postorder of left branch) (postorder of right branch) (root node) <br>

889 properties: the head node of left branch is pre[1], but it occurs last in the postorder representation of the left branch.<br>
pre[1] = post[L-1]. L = post.indexOf(pre[1]) + 1 <br>
left branch: pre[1:L+1], post[0:L] <br>
right branch: pre[L+1:N], post[L:N-1] <br>
感想：好容易出错啊

### old

#### 105. Construct Binary Tree from Preorder and Inorder Traversal (ok)

#### 106. Construct Binary Tree from Inorder and Postorder Traversal (ok)

#### 103. Binary Tree Zigzag Level Order Traversal (ok)

## 11.26
### new
#### 662. Maximum Width of Binary Tree (ok)
#### 1586 Binary Search Tree Iterator II (ok)
Solution: stack 存储inorder traversal(for next). vector存储prev
#### 1382 Balance a Binary Search Tree (ok)
#### 1650. Lowest Common Ancestor of a Binary Tree III (ok)
Point: all values in the binary tree are unique

### old
#### 114. Flatten Binary Tree to Linked List （ok）
#### 101. Symmetric Tree (ok)
Solution: isMirror
#### 199. Binary Tree Right Side View (ok)
#### 173. Binary Search Tree Iterator (ok)
Solution: Controlled Recursion. Behind: Inorder traversal<br>
#### 110 Balanced Binary Tree (ok)
#### 124. Binary Tree Maximum Path Sum (ok)
Solution: recursion 小技巧。可以巧用一些reference value来改变状态。
#### 236. Lowest Common Ancestor of a Binary Tree (ok)
Solution: 当成graph来做。
#### 235. Lowest Common Ancestor of a Binary Search Tree (ok)
#### 572. Subtree of Another Tree (ok)
#### 100. Same Tree (ok)
#### 116. Populating Next Right Pointers in Each Node (ok)
#### 117. Populating Next Right Pointers in Each Node II (ok)
#### 200. Number of Islands (ok)
#### 695. Max Area of Island (ok)

## 11.27
### new
#### 885. Spiral Matrix III (ok)
#### 252. Meeting Rooms (ok)
### old
#### 133. Clone Graph (ok)
#### 430. Flatten a Multilevel Doubly Linked List (ok)
Solution: Stack
#### 146. LRU Cache (ok)
#### 54. Spiral Matrix (ok)
#### 59. Spiral Matrix II (ok)
#### 139. Word Break (ok)
#### 140. Word Break II (OK)
#### 253. Meeting Rooms II (ok)
Solution 1: Map
Solution 2: sort and compare
#### 1029. Two City Scheduling (ok)
#### 694. Number of Distinct Islands (ok)
#### 797. All Paths From Source to Target （OK）
#### 62. Unique Paths (ok)
#### 63. Unique Paths II (ok)

## 11.28
#### 1135. Connecting Cities With Minimum Cost (ok)
Solution 1: Prim<br>
Solution 2: Krustal
#### 305. Number of Islands II (ok)
Solution: UnionFindSet <br>
psudo code for UnionFindSet: <br>
```
class UnionFindSet:
    func UnionFindSet(n):
        parents = [1..n]
        ranks = [0..0] (n zeros)
    
    func Find(x):
        if x != parents[x]:
            parents[x] = Find(parents[x])
        return parents[x]
    
    func Union(x, y):
        px, py = Find(x), Find(y)
        if ranks[px] > ranks[py]: parents[py] = px
        if ranks[px] < ranks[py]: parents[px] = py
        if ranks[px] == ranks[py]:
            parents[py] = px
            ranks[px]++
```
### old
#### 242. Valid Anagram (ok)
#### 78. Subsets (ok)
#### 90. Subsets II (ok)
#### 46. Permutations (ok)
#### 47. Permutations II (ok)
```
            if (i != 0 && nums_[i-1] == nums_[i] && visited[i - 1] == false){
                continue;
            }
```
## 11.29
### new
#### 264. Ugly Number II (ok)
#### 216. Combination Sum III (ok)
### old
#### 39. Combination Sum (ok)
#### 40. Combination Sum II (ok)
#### 131. Palindrome Partitioning (ok)
#### 5. Longest Palindromic Substring (ok)
Solution: Dynamic Programming<br>
Base: P[i, i] = true, P[i, i+1] = (s[i] == s[i + 1]) <br>
p[i, j] = p[i + 1, j - 1] and s[i] == s[j]
#### 1274. Number of Ships in a Rectangle （ok）
#### 7. Reverse Integer (ok)
#### 1. Two Sum (ok)
#### 283. Move Zeroes (ok)
感想： 学习了candy crush里面的写法。觉得非常的巧妙。应用到这道题里面之后写的更加精妙了。
#### 451. Sort Characters By Frequency(ok)
#### 611. Valid Triangle Number (ok)



#### 980. Unique Paths III (new)
#### 711. Number of Distinct Islands II (new)
Solution: dfs + canonical hash。很没必要了。
#### 1123. Lowest Common Ancestor of Deepest Leaves (new)
#### 865. Smallest Subtree with all the Deepest Nodes
#### 1583. Count Unhappy Friends (new)
#### 924. Minimize Malware Spread (new)
#### 296. Best Meeting Point (new)
#### 1300. Sum of Mutated Array Closest to Target (new)









