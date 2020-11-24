
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
#### 1583. Count Unhappy Friends (new)

#### 924. Minimize Malware Spread (new)

#### 296. Best Meeting Point (new)

#### 1300. Sum of Mutated Array Closest to Target (new)

#### 1111. Maximum Nesting Depth of Two Valid Parentheses Strings


### old

#### 394. Decode String

#### 2. Add Two Numbers

#### 445. Add Two Numbers II



