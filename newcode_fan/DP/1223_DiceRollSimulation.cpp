class Solution {
public:
    // dp[5001][7][16] 连续k个j结尾的sequence数量， n = i
    int dieSimulator(int n, vector<int>& rollMax) {
        long long sum = 0;
        int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(7, vector<long long>(16, 0)));
        for (int j = 1; j <= 6; ++j) {
            dp[1][j][1] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                
                for (int k = 1; k <= 15; ++k) {
                    if (k == 1) {
                        for (int p = 1; p <= 6; ++p) {
                            if (p != j) {
                                for (int q = 1; q <= 15; ++q) dp[i][j][1] = (dp[i][j][1] + dp[i - 1][p][q]) % MOD;
                            }
                        }
                    } else {
                        if (k > rollMax[j - 1]) break;
                        dp[i][j][k] = dp[i - 1][j][k - 1];
                    }
                }
            }
        }
       
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= 15; ++k) {
                sum += dp[n][j][k];
                sum = sum % MOD;
            }
        }
        return (int)sum;
    }
};