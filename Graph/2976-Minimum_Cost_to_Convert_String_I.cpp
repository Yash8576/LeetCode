class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));
    
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dist[from][to] = min(dist[from][to], cost[i]);
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            
            if (dist[from][to] == INF) {
                return -1;
            }
            totalCost += dist[from][to];
        }
        return totalCost;
    }
};