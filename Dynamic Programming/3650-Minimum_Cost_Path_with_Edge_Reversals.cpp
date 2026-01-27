class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n), rev(n);
        for (int i = 0; i < edges.size(); ++i) {
            auto& e = edges[i];
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            rev[v].emplace_back(u, w);
        }
        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));
        dist[0][0] = 0;
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            auto [cost, u, used] = pq.top(); pq.pop();
            if (cost > dist[u][used]) continue;
            if (used == 0) {
                for (int i = 0; i < adj[u].size(); ++i) {
                    auto [v, w] = adj[u][i];
                    if (dist[v][0] > cost + w) {
                        dist[v][0] = cost + w;
                        pq.emplace(dist[v][0], v, 0);
                    }
                }
                for (int i = 0; i < rev[u].size(); ++i) {
                    auto [v, w] = rev[u][i];
                    if (dist[v][0] > cost + 2LL * w) {
                        dist[v][0] = cost + 2LL * w;
                        pq.emplace(dist[v][0], v, 0);
                    }
                }
            } else {
                for (int i = 0; i < adj[u].size(); ++i) {
                    auto [v, w] = adj[u][i];
                    if (dist[v][0] > cost + w) {
                        dist[v][0] = cost + w;
                        pq.emplace(dist[v][0], v, 0);
                    }
                }
            }
        }
        long long ans = min(dist[n - 1][0], dist[n - 1][1]);
        return ans == INF ? -1 : ans;
    }
};