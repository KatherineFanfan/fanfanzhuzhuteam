class Solution {
public:
    // graph 构成连通的点可以任意组合排序
    // dfs 找连通分量，存string 和 index，排序
    // time: o(vlogv) 排序上界  space：o(v^2)
    void dfs(string& s, int start, string &cur_s, vector<int> &idx) {
        if (visited[start]) return;
        visited[start] = 1;
        cur_s += s[start];
        idx.push_back(start);
        for (auto g : graph[start]) {
            dfs(s, g, cur_s, idx);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        visited = vector<int>(s.length(), 0);
        for (int i = 0; i < pairs.size(); ++i) {
            graph[pairs[i][0]].push_back(pairs[i][1]);
            graph[pairs[i][1]].push_back(pairs[i][0]);
        }
        for (int i = 0; i < s.length(); ++i) {
            string cur = "";
            vector<int> idx;
            dfs(s, i, cur, idx);
            sort(begin(cur), end(cur));
            sort(begin(idx), end(idx));
            for (int j = 0; j < idx.size(); ++j) {
                s[idx[j]] = cur[j];
            }
        }
        
        return s;
    }
    
private:
    unordered_map<int, vector<int>> graph;
    vector<int> visited;
};