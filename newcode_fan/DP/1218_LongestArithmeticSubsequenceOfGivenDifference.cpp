class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // dp[x] = dp[x - d] + 1
        unordered_map<int, int> hashmap;
        int maxlen = 0;
        for (int a : arr) {
            if (hashmap.find(a - difference) == hashmap.end()) {
                hashmap[a] = 1;
            } else {
                hashmap[a] = hashmap[a - difference] + 1;
            }
            maxlen = max(maxlen, hashmap[a]);
        }
        return maxlen;
    }
};