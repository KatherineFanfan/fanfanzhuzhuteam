class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> cache;
        split(0, s, cache);
        return res;
    }
private:
    int res;
    void split(int cur, string s, unordered_set<string>& cache) {
        if (cur >= s.length()) {
            int size = cache.size();
            res = max(res, size);
        }
        
        for (int i = 1; i <= s.length() - cur; i++) {
            string sub = s.substr(cur, i);
            if (!cache.count(sub)) {
                cache.insert(sub);
                split(cur + i, s, cache);
                cache.erase(sub);
            }
        }
    }
};
