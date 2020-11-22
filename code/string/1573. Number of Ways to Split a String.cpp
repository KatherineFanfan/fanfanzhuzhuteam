class Solution {
public:
    int numWays(string s) {
        long long kmod = pow(10, 9) + 7;
        vector<long long> zeros;
        long long cur = 0;
        int oneNum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                cur++;
            } else {
                oneNum++;
                zeros.push_back(cur);
                cur = 0;
            }
        }
        
        zeros.push_back(cur);
        
        long long zeroNum = s.length() - oneNum;

        if (oneNum == 0) {
            return (int)(((zeroNum - 2) * (zeroNum - 1) / 2) % kmod);
        } 
        
        if (oneNum % 3 != 0) {
            return 0;
        }

        long long x = (zeros[oneNum / 3] + 1) * (zeros[oneNum * 2 / 3] + 1);
        return (int)((x) % kmod);
    }
};
