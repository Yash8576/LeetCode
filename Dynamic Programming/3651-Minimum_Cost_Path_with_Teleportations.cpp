class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k && grid[0][0] >= grid[m - 1][n - 1]) return 0;

        int mx = 0;
        for (auto& r : grid) for (int v : r) mx = max(mx, v);

        vector<int> suf(mx + 2, INT_MAX), min_f(mx + 1), dp(n + 1);

        for (int t = 0; t <= k; ++t) {
            fill(min_f.begin(), min_f.end(), INT_MAX);
            fill(dp.begin(), dp.end(), INT_MAX / 2);
            dp[1] = -grid[0][0];

            for (auto& row : grid) {
                for (int j = 0; j < n; ++j) {
                    int v = row[j];
                    dp[j + 1] = min(min(dp[j], dp[j + 1]) + v, suf[v]);
                    min_f[v] = min(min_f[v], dp[j + 1]);
                }
            }

            auto temp = suf;
            for (int i = mx; i >= 0; --i) 
                suf[i] = min(suf[i + 1], min_f[i]);
            
            if (suf == temp) break;
        }
        return dp[n];
    }
};