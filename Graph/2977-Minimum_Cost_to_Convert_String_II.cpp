class Solution {
public:
    static const unsigned long long INF = ULLONG_MAX;
    unsigned long long minCost[201][201];
    unsigned long long dp[1001];

    unordered_map<string, int> substringToId;
    unordered_set<int> substringLengths;

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const int m = original.size();
        const int n = source.length();

        substringToId.clear();
        substringLengths.clear();

        int nextId = 0;
        memset(minCost, 255, sizeof(minCost));

        for (int i = 0; i < m; ++i) {
            if (substringToId.find(original[i]) == substringToId.end()) {
                substringToId[original[i]] = nextId++;
                substringLengths.insert(original[i].size());
            }
            if (substringToId.find(changed[i]) == substringToId.end()) {
                substringToId[changed[i]] = nextId++;
            }
            int fromId = substringToId[original[i]];
            int toId = substringToId[changed[i]];
            minCost[fromId][toId] = min(minCost[fromId][toId], (unsigned long long)cost[i]);
        }

        const int numSubstrings = nextId;
        for (int i = 0; i < numSubstrings; ++i) {
            minCost[i][i] = 0;
        }

        for (int k = 0; k < numSubstrings; ++k) {
            for (int i = 0; i < numSubstrings; ++i) {
                if (minCost[i][k] != INF) {
                    for (int j = 0; j < numSubstrings; ++j) {
                        if (minCost[k][j] != INF) {
                            minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                        }
                    }
                }
            }
        }

        memset(dp, 255, sizeof(dp));
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int len : substringLengths) {
                if (i + len > n) continue;

                string sourceSubstr = source.substr(i, len);
                string targetSubstr = target.substr(i, len);

                auto sourceIt = substringToId.find(sourceSubstr);
                auto targetIt = substringToId.find(targetSubstr);

                if (sourceIt != substringToId.end() && targetIt != substringToId.end()) {
                    unsigned long long cost = minCost[sourceIt->second][targetIt->second];
                    if (cost != INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + cost);
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};