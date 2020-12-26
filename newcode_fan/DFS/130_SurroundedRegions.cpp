class Solution {
public:
    // dfs 找连通分量，从边界找不需要flip的
    void dfs(int x, int y, vector<vector<char>>& board) {
        if (x < 0 || x >= m_ || y < 0 || y >= n_ || board[x][y] != 'O') return;
        board[x][y] = 'U';
        for (int i = 0; i < 4; ++i) {
            int a = x + dir[i];
            int b = y + dir[i + 1];
            dfs(a, b, board); 
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        m_ = board.size();
        n_ = board[0].size();
        for (int i = 0; i < m_; ++i) {
            dfs(i, 0, board);
            dfs(i, n_ - 1, board);
        }
        for (int j = 0; j < n_; ++j) {
            dfs(0, j, board);
            dfs(m_ - 1, j, board);
        }
        
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (board[i][j] == 'U') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
    
    int m_, n_;
    vector<int> dir = {-1, 0, 1, 0, -1};
};