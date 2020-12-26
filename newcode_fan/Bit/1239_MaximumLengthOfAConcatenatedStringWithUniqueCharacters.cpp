//
//  1239_MaximumLengthOfAConcatenatedStringWithUniqueCharacters.cpp
//  leetcode
//
//  Created by Wenjing Fan on 2020/12/25.
//

#include <iostream>
#include <vector>
using namespace std;
// bit + dfs(combination)
// __builtin_popcount(int a) a的二进制表示下1的个数 

class Solution {
public:
    // dfs 找到所有的组合 2^n 
    int ans = 0;
    void dfs(vector<int>& cnt, int start, int mask) {
        ans = max(ans, __builtin_popcount(mask));
        for (int i = start; i < cnt.size(); ++i) {
            if ((cnt[i] & mask) == 0) {
                dfs(cnt, i + 1, cnt[i] | mask);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        // 用mask表示所有没有重复元素的字符串
        vector<int> cnt;
        for (auto s : arr) {
            int mask = 0;
            for (char c : s) {
                mask |= 1 << (c - 'a');
            }
            if (__builtin_popcount(mask) != s.length()) continue;
            cnt.push_back(mask);
        }

        dfs(cnt, 0, 0);
        return ans;
        
    }
};
