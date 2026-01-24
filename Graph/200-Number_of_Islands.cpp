class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        return islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Check bounds and if it's land
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }
        
        // Mark as visited by changing to '0'
        grid[i][j] = '0';
        
        // Visit all 4 directions
        dfs(grid, i + 1, j, m, n); // down
        dfs(grid, i - 1, j, m, n); // up
        dfs(grid, i, j + 1, m, n); // right
        dfs(grid, i, j - 1, m, n); // left
    }
};