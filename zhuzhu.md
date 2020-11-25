
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

#### 1047. Remove All Adjacent Duplicates In String (ok)
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

#### 1583. Count Unhappy Friends (new)

#### 924. Minimize Malware Spread (new)

#### 296. Best Meeting Point (new)

#### 1300. Sum of Mutated Array Closest to Target (new)

#### 889. Construct Binary Tree from Preorder and Postorder Traversal
对照：105. Construct Binary Tree from Preorder and Inorder Traversal<br>
106. Construct Binary Tree from Inorder and Postorder Traversal<br>
889. Construct Binary Tree from Preorder and Postorder Traversal<br>

### old

#### 103. Binary Tree Zigzag Level Order Traversal

#### 116. Populating Next Right Pointers in Each Node

#### 117. Populating Next Right Pointers in Each Node II

#### 100. Same Tree

#### 572. Subtree of Another Tree

236	
Lowest Common Ancestor of a Binary Tree    		47.4%	Medium	
1644	
Lowest Common Ancestor of a Binary Tree II    		59.9%	Medium	
1123	
Lowest Common Ancestor of Deepest Leaves    		67.1%	Medium	
235	
Lowest Common Ancestor of a Binary Search Tree    		50.9%	Easy	
1650	
Lowest Common Ancestor of a Binary Tree III    		79.2%	Medium	








